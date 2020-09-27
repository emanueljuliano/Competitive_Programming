program Roof;
{
 This program solves the problem 'Roof'.

  The algorithm is divided into two main parts. One of them calculates
  how much water falls from sky on each roof segment and where it
  falls (by sweeping). The second part calculates how much water
  is collected on each segment.
}
{ limits }
const MaxN = 40000; Skx = 1000000; Sky = 1000000; MaxH = 25;
{ Skx and Sky are coordinate limits }
{ MaxH limits the number of segments on a vertical line }

{ input data }

var n : LongInt;                                {number of the roof segments  }
    x1, y1, x2, y2 : Array[1..MaxN] of LongInt; {lines of input               }

{ other global variables }

var { water[k] of water falls on k, from the sky only }
    wsky  : Array[0..MaxN] of LongInt;
    { water[k] of water falls on k, in total          }
    water : Array[0..MaxN] of LongInt;
    { water from segment k falls on next[k]           }
    next: Array[1..MaxN] of LongInt;



procedure Broom;
{The first part calculates (by sweeping from left to right):
 wsky[k] : how much water falls from Sky to segment k;
 next[k] : water from segment k falls on segment next[k] (0 if none).
}
var broom : Array [1 .. MaxH] of LongInt; bnum : LongInt;
    { indices of roof segments crossing the broom, and how many of them }

    bpos: Array[1..MaxN] of LongInt;
    { to simplify removing segments from the broom, bpos[broom[j]] = k  }

type SegEnd = record                      {either end of a roof segment }
  x, y : LongInt;                         {coordinates                  }
  k  : LongInt;                           {number of its segment        }
  se : Integer;                           {1 = left end, 2 = right end  }
  end;

var ends: Array[1..2*MaxN] of SegEnd;     {all the segment ends         }

function Cmp(s1, s2: SegEnd) : Boolean;
{ Determine the order of considering the segment ends s1 and s2.        }
{ True if s1 before s2.                                                 }
begin
  {from left to right...}
  if s1.x <> s2.x then Cmp := s1.x < s2.x
  {first add new segments to the broom, then remove the old ones...}
  else if s1.se <> s2.se then Cmp := s1.se < s2.se
  {add from bottom to top...}
  else if s1.se = 1 then Cmp := s1.y < s2.y
  {but remove from top to bottom...}
  else Cmp := s1.y > s2.y
  end;

procedure Sort(l, r: LongInt);
{ This function sorts all segment ends according to results of Cmp.     }
{ Quick sort algorithm.                                                 }
var
  i, j: LongInt; x, y : SegEnd;
begin
  i := l; j := r; x := ends[(l+r) DIV 2];
  repeat
    while Cmp(ends[i],x) do i := i + 1;
    while Cmp(x,ends[j]) do j := j - 1;
    if i <= j then begin
      y := ends[i]; ends[i] := ends[j]; ends[j] := y;
      i := i + 1; j := j - 1;
      end;
    until i > j;
  if l < j then Sort(l, j);
  if i < r then Sort(i, r);
  end;

function FindNext(x, y: LongInt) : LongInt;
{ The water from position (x,y) will fall on the segment FindNext(x, y).}
{ Of course, x has to be the current broom position.                    }
var j, k : LongInt;
    {We count on fractions (nom/den), not on floats.}
    yinom, yiden, ymaxnom, ymaxden : Int64;
begin
  ymaxnom := -1; ymaxden := 1; FindNext := 0;
  for j := 1 to bnum do begin
    k := broom[j];
    yiden := (x2[k] - x1[k]);
    yinom := (x - x1[k])*Int64(y2[k] - y1[k]) + yiden * y1[k];
    if (yinom / yiden < y) and (yinom * ymaxden > ymaxnom * yiden) then begin
      ymaxden := yiden; ymaxnom := yinom; FindNext := k
      end
    end
  end;

procedure AddSegment(k: LongInt);
{add a segment to the broom.}
begin
{ WriteLn('Adding segment ',k,
    ': (',x1[k],',',y1[k],') - (',x2[k],',',y2[k],')'); }
  if y1[k] < y2[k] then next[k] := FindNext(x1[k], y1[k]);
  Inc(bnum); broom[bnum] := k; bpos[k] := bnum
  end;

procedure DelSegment(k: LongInt);
{remove a segment from the broom.}
begin
{ WriteLn('Deling segment ',k,
    ': (',x2[k],',',y2[k],') - (',x1[k],',',y1[k],')'); }
  if y2[k] < y1[k] then next[k] := FindNext(x2[k], y2[k]);
  broom[bpos[k]] := broom[bnum]; bpos[broom[bnum]] := bpos[k]; Dec(bnum)
  end;

var i, k: LongInt;
begin {Broom}
  { no water is known to fall }
  for k := 1 to n do wsky[k] := 0;

  { prepare an array of all segment ends }
  for k := 1 to n do begin
    ends[2*k-1].k := k;     ends[2*k-1].se := 1;
    ends[2*k-1].x := x1[k]; ends[2*k-1].y  := y1[k];
    ends[2*k  ].k := k;     ends[2*k  ].se := 2;
    ends[2*k  ].x := x2[k]; ends[2*k  ].y  := y2[k];
    end;

  { sort it }
  Sort(1, 2*n);
  
  { the broom is empty }
  bnum := 0;
  
  { add and remove all segments }
  for i := 1 to 2*n do begin
    if ends[i].se = 1 then AddSegment(ends[i].k) else DelSegment(ends[i].k);
{   Write('Broom: '); for j := 1 to bnum do Write(' ',broom[j]); WriteLn;}
{   invariant: for j := 1 to bnum, bpos[broom[j]] = j }
    if bnum > 0 then
      {some water from the Sky falls on the top segment}
      Inc(wsky[FindNext(ends[i].x, Sky+1)], ends[i+1].x - ends[i].x);
    end;
  end; {Broom}



procedure Waterfall;
{ This part accumulates all the water falling on each segment. }
var k: LongInt;
    prev: Array[0..MaxN] of LongInt;

procedure AddWater(k, qty: LongInt);
{ Invariant: prev[k] is the number of all water sources that immediately    }
{ affect segment k (including the sky), which have not been counted yet.    }
{ This procedure counts another source:                                     }
begin
  Inc(water[k], qty);
  Dec(prev[k]);
  if prev[k] = 0 then 
    AddWater(next[k], water[k])
  end;

begin {Waterfall}
  prev[0] := N+1; {so prev[0] will never fall to 0}

  for k := 1 to n do prev[k] := 1;
  for k := 1 to n do Inc(prev[next[k]]);

  { no water is known to fall }
  for k := 1 to n do water[k] := 0;

  { count water from the sky }
  for k := 1 to n do AddWater(k, wsky[k]);

  end; {Waterfall}



{the main program}
var k: LongInt;
begin

  { read the input data }
  ReadLn(n);
  for k := 1 to n do begin
    ReadLn(x1[k], y1[k], x2[k], y2[k]);
    end;

  Broom;
  
  Waterfall;
  
{ for k := 1 to n do
    WriteLn('Segment ',k,': top = ',wsky[k],', next = ',next[k]);
}   
  for k := 1 to n do
    WriteLn(water[k]);

  end.
