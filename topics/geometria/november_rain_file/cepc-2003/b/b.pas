(*
   Solution of problem BUNDLING
   Written by Lukasz Kowalik, 20.10.2003
  
   Method: Dynamic programming. For succesive i=1..N the program 
   finds solution for instructions 1..i. For every i, we
   check what happens if the last bundle contains 1, 2 or 3 
   instructions. The number of bundles and the number of stops 
   depend on already computed solutions for i-1, i-2, i-3 respectively. 
   We choose the best option.
   
*)

const
  MaxN = 100000;

type
  TInsType = 'A'..'J';

var
  n, t : LongInt;

  Profile : array [1..3, TInsType, TInsType, TInsType, -1..2] of Boolean;
  (* Profile [3, X,   Y,   Z, s] = True when there is a template XYZ with stop after s-th instruction
       (in this case s = -1, 0, 1 or 2)
     Profile [2, X,   Y, 'A', s] = True when there is a template containing X before Y with stop after s-th of these instructions
       (in this case s = -1, 0, 1 or 2)
     Profile [1, X, 'A', 'A', s] = True when there is a template containing X
       (in this case s = -1, 0 or 1)
     In all of these cases s = -1 indicates there is no stop in the template,
                           s = 0  indicates there is stop before first instruction.
  *)


  Ins : array[1..MaxN] of TInsType;
  Dep : array[1..MaxN] of LongInt;

  i, j : LongInt;

  (* MinBun [i]: minimal number of bundles needed for instructions 1..i
     MinSt  [i]: minimal number of stops needed for instructions 1..i when there is MinBun[i] bundles used.
     LastSt [i]: position of the last stop for instr. 1..i in bundling with performance MinBun [i], MinSt[i] *)
  MinBun, MinSt, LastSt  : array[0..MaxN] of LongInt;

procedure ReadData;
var
  c1, c2, c3 : TInsType;
  Stop : 0..2;
begin
  for i := 1 to 3 do
    for c1 := Low (TInsType) to High (TInsType) do
      for c2 := Low (TInsType) to High (TInsType) do
        for c3 := Low (TInsType) to High (TInsType) do
          for j := -1 to 2 do
            Profile [i, c1, c2, c3, j] := False;

  ReadLn (t, n);
  for i := 1 to t do
    begin
      Read (c1, c2, c3);
      ReadLn (Stop);

      case Stop of
        0:
        begin
          Profile [3, c1, c2, c3, -1] := True;
          Profile [3, c1, c2, c3, 0] := True;

          Profile [2, c1, c2, 'A', -1] := True;
          Profile [2, c2, c3, 'A', -1] := True;
          Profile [2, c1, c3, 'A', -1] := True;
          Profile [2, c1, c2, 'A', 0] := True;
          Profile [2, c2, c3, 'A', 0] := True;
          Profile [2, c1, c3, 'A', 0] := True;

          Profile [1, c1, 'A', 'A', -1] := True;
          Profile [1, c2, 'A', 'A', -1] := True;
          Profile [1, c3, 'A', 'A', -1] := True;
          Profile [1, c1, 'A', 'A', 0] := True;
          Profile [1, c2, 'A', 'A', 0] := True;
          Profile [1, c3, 'A', 'A', 0] := True;
        end;
        1:
        begin
          Profile [3, c1, c2, c3, 1] := True;

          Profile [2, c1, c2, 'A', 1] := True;
          Profile [2, c2, c3, 'A', 0] := True;
          Profile [2, c1, c3, 'A', 1] := True;

          Profile [1, c1, 'A', 'A', 1] := True;
          Profile [1, c2, 'A', 'A', 0] := True;
          Profile [1, c3, 'A', 'A', 0] := True;
        end;
        2:
        begin
          Profile [3, c1, c2, c3, 2] := True;

          Profile [2, c1, c2, 'A', 2] := True;
          Profile [2, c2, c3, 'A', 1] := True;
          Profile [2, c1, c3, 'A', 1] := True;

          Profile [1, c1, 'A', 'A', 1] := True;
          Profile [1, c2, 'A', 'A', 1] := True;
          Profile [1, c3, 'A', 'A', 0] := True;
        end;
      end;
    end;

  for i := 1 to n do
    ReadLn (Ins [i], Dep [i]);


end;

(* function Try checks if we break any dependencies when
   the last bundle contains Len instructions and stops
   are placed after instructions S1 and S2, possibly
   S2 = 0 or S1 = S2 = 0.

   If no dependencies are broken we check whether the
   achieved performance (number of bundles and stops) is
   so far the best
*)
function Try (Pos, Len, S1, S2 : LongInt) : Boolean;
var
  NoDep : Boolean;
  NewStops : 0..2;
  LastStop : LongInt;
  q : 0..2;
begin
  NoDep := True;
  for q := 0 to Len - 1 do
    if not (
            (Dep [Pos - q] <= LastSt [Pos - Len]) or
            ((Dep [Pos - q] <= S1) and (Pos - q > S1)) or
            ((Dep [Pos - q] <= S2) and (Pos - q > S2))
           ) then
      NoDep := False;

  if S2 = 0 then
    if S1 = 0 then
    begin
      NewStops := 0;
      LastStop := LastSt [Pos - Len];
    end
    else
    begin
      NewStops := 1;
      LastStop := S1;
    end
  else
  begin
    NewStops := 2;
    LastStop := S2;
  end;

  if NoDep then
  begin
    if  (MinBun [Pos - Len] + 1 < MinBun [Pos]) or
       ((MinBun [Pos - Len] + 1 = MinBun [Pos]) and (MinSt  [Pos - Len] + NewStops < MinSt [Pos])) or
       ((MinBun [Pos - Len] + 1 = MinBun [Pos]) and (MinSt  [Pos - Len] + NewStops = MinSt [Pos]) and (LastStop > LastSt [Pos])) then
      begin
        MinBun [Pos] := MinBun [Pos - Len] + 1;
        MinSt  [Pos] := MinSt  [Pos - Len] + NewStops;
        LastSt [Pos] := LastStop;
      end;
    end;

  Try := NoDep;
end;

(* proc. Update updates MinBun [Pos], MinSt[Pos], LastSt [Pos].*)
procedure Update (Pos, Len : LongInt);
var
  It1, It2, It3 : TInsType;
  NoDep : Boolean;
  k : LongInt;
begin
  It1 := Ins [Pos - Len + 1];
  It2 := 'A';
  It3 := 'A';
  if Len > 1 then
  begin
    It2 := Ins [Pos - Len + 2];
    if Len = 3 then
      It3 := Ins [Pos];
  end;

  (* try without stops *)
  if not (Profile [Len, It1, It2, It3, -1] and Try (Pos, Len, 0, 0)) then
  begin
    (* try with one stop *)
    NoDep := False;
    k := 2;
    repeat
      if Profile [Len, It1, It2, It3, k] then
        NoDep := Try (Pos, Len, Pos - Len + k, 0);
      k := k - 1;
    until NoDep or (k = -1);

    if not NoDep then
    begin
      (* try with two stops *)
      k := 2;
      repeat
        if Profile [Len, It1, It2, It3, k] then
          NoDep := Try (Pos, Len, Pos - Len, Pos - Len + k);
        k := k - 1;
      until NoDep or (k = 0);
    end;
  end;
end;

begin
  ReadData;

  for i := 1 to n do
  begin
    MinBun [i] := MaxN + 2;
    MinSt [i] := MaxN + 2;
    LastSt [i] := 0;
  end;

  MinBun [0] := 0;
  MinSt [0] := 0;
  LastSt [0] := 0;

  Update (1, 1);
  if n >= 2 then
  begin
    Update (2, 1);
    Update (2, 2);
  end;

  for i := 3 to n do
    for j := 1 to 3 do
       Update (i, j);

  WriteLn (MinBun [n], ' ', MinSt [n]);
end.
