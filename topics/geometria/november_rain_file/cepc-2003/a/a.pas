const
  NoTeams = 62;

type 
  Submissions = array [1..NoTeams,'A'..'I'] of integer;
  SubmissionTimes = array['A'..'I'] of longint;

  OneLine = string[20];
  TeamId = array [1..6] of char;
  Teams = array[1..NoTeams + 1] of TeamId;
		
function find_team(var t: Teams; var last_team: integer; var id : TeamId): integer;
var
  i: integer;
begin
  t[last_team + 1] := id; i := 1;
  while  id <> t[i] do Inc(i);
  if i > last_team then Inc(last_team);
  find_team := i
end;	
		
var
  line: OneLine;
  c,d: char;
  time: longint;
  i,j: integer;
  s: Submissions;
  stimes: SubmissionTimes;
  t: Teams;
  tnr: integer;
  id: TeamId;
  n: integer;
  sol: array['A'..'I'] of integer;
  stars: array['A'..'I'] of integer;

begin	
  for i := 1 to NoTeams do
    for c := 'A' to 'I' do
      s[i,c] := 0; 
	
  for c := 'A' to 'I' do
  begin
    sol[c] := 0;	
    stars[c] := 0
  end;		

  tnr := 0;
  
  readln(n);

  for j := 1 to n do
  begin
      time := 0; read(c);
      while c <> ' ' do
      begin
        time := 10*time + (ord(c) - ord('0'));
        if not eoln then read(c) else c := ' '
      end;	
      i := 0;
      repeat 
	Inc(i);
	read(id[i])
      until id[i] = ' ';
      while i < 6 do
      begin
	Inc(i); id[i] := ' '
      end;		
      i := find_team(t,tnr,id);
      read(c); read(d); readln(d);
      if s[i,c] >= 0 then
      begin
        Inc(s[i,c]);
        if d = 'A' then
        begin
	  Inc(sol[c]); stars[c] := s[i,c] + stars[c];
	  stimes[c] := stimes[c] + time;
	  s[i,c] := -1
	end
      end
  end;
	
  for c := 'A' to 'I' do
  begin
    write(c,' ',sol[c]);
    if  (sol[c] > 0) then
      write(' ', stars[c]/sol[c] :0:2, ' ', stimes[c]/sol[c] :0:2);
    writeln
  end
end.				
