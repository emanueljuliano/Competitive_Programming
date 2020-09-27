program ShoVer;
{$R-}

const MaxN = 250000;

var Breakpoints: array [0 .. MaxN, 0 .. 1] of LongInt;
    Sorted: array [0 .. MaxN] of LongInt;

    n: LongInt;
    best_len, best_b, best_e: LongInt;
    best_dir: Char;

procedure ReadData;
var i: LongInt;
    c: Char;
    x,y: LongInt;
begin
  Readln(n);
  Breakpoints[0, 0] := 0; Breakpoints[0, 1] := 0;
  x := 0; y := 0;
  for i:=1 to n do begin
    Read(c);
    case c of
      'N': Inc(y);
      'E': Inc(x);
      'S': Dec(y);
      'W': Dec(x)
    end;
    Breakpoints[i, 0] := x; Breakpoints[i, 1] := y
  end
end;

procedure Sort(coord: Byte);
var i: LongInt;

function IsSmaller(a, b: LongInt) : Boolean;
begin
  if Breakpoints[a, coord] < Breakpoints[b, coord] then
    IsSmaller := True
  else
  if Breakpoints[a, coord] > Breakpoints[b, coord] then
    IsSmaller := False
  else
    IsSmaller := Breakpoints[a, 1 - coord] < Breakpoints[b, 1 - coord]
end;

procedure QuickSort(l, r: LongInt);
var i, j, x, y: LongInt;
begin
  i := l; j := r; x := Sorted[(l+r) DIV 2];

{  x := Sorted[l + Trunc(Random * (r - l + 1))];}

  repeat
    while IsSmaller(Sorted[i], x) do i := i + 1;
    while IsSmaller(x, Sorted[j]) do j := j - 1;
    if i <= j then
    begin
      y := Sorted[i]; Sorted[i] := Sorted[j]; Sorted[j] := y;
      i := i + 1; j := j - 1;
    end;
  until i > j;
  if l < j then QuickSort(l, j);
  if i < r then QuickSort(i, r);
end;

begin
  for i := 0 to n do
    Sorted[i] := i;
  QuickSort(0, n);
end;

procedure Solve(coord: Byte);
var i, len, b, e: LongInt;
begin 
  Sort(coord);
  for i := 1 to n do
    if (Breakpoints[Sorted[i - 1], coord] = Breakpoints[Sorted[i], coord]) then
      begin
        len := Abs(Breakpoints[Sorted[i - 1], 1 - coord] -
                   Breakpoints[Sorted[i], 1 - coord]);
        if Sorted[i - 1] < Sorted[i] then begin
          b := Sorted[i - 1]; e := Sorted[i]
        end 
        else begin
          b := Sorted[i]; e := Sorted[i - 1]
        end;
        if (b + 1 <> e) and 
           ((len < best_len) or
            (len = best_len) and (b < best_b) or
            (len = best_len) and (b = best_b) and (e > best_e)) then
          begin
            best_len := len;
            best_b := b;
            best_e := e
          end
      end
end;

begin
  ReadData;
  best_len := n;
  Solve(0);
  Solve(1);
  if Breakpoints[best_b, 0] = Breakpoints[best_e, 0] then
    if Breakpoints[best_b, 1] < Breakpoints[best_e, 1] then
      best_dir := 'N'
    else
      best_dir := 'S'
  else
    if Breakpoints[best_b, 0] < Breakpoints[best_e, 0] then
      best_dir := 'E'
    else
      best_dir := 'W';
  Writeln(best_len, ' ', best_b, ' ', best_e, ' ', best_dir)
end.
