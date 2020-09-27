{ Solution of problem FOOTBALL }
{ Author: Pawe³ Wolff          }
{ Date  : 2003.10.24           }


{
  Description of the algorithm:

  This is a straightfoward solution which simulates (in some way) drawing
  of Eric's polygon. It works on a non-directed graph that represents
  the structure of the ball. The graph consists of 32 vertices: 20 of them
  represent hexagons and other 12 represent pentagons. There is an edge
  in this graph between two vertices iff vertices represent adjoining pieces
  of the ball. Moreover, the edges outgoing from every vertex are put in
  a cyclic order. For every chosen vertex this order is the same as
  the order of adjoining pieces, moving counter-clockwise.
  
  We move through the vertices of the graph, starting from any vertex
  which represents a hexagon. The idea is to go through all vertices
  on the boundary of the green part of the graph
  (i.e. all pieces on the boundary of the green part of the ball).
  Meanwhile we cut off all edges connecting the current vertex with those
  outside the green part of the graph. In the end we meet the vertex
  we started from. Now, we have our green part of the graph separated
  from the rest. It remains to visit (e.g. by DFS algorithm) all the 
  green vertices counting how many of them represent hexagons or pentagons.
}


program football;

const
  BLACK_PIECES = 12;
  WHITE_PIECES = 20;
  MAX_DEG = 6;
  MAX_POLYGON_VERTICES = 60;
  CUT = 0; { stands for edges removed from the graph; (see below) }

  { graph representing a structure of the ball }
  ball: array [-BLACK_PIECES..WHITE_PIECES] of array [0..MAX_DEG - 1] of integer =

     { here go descriptions of pentagons,
       indexed with the negative numbers: -12..-1 }
    (( 16, 17, 18, 19, 20,  0),
     ( 15, 14, 13, 12, 11,  0),
     ( 10,  1,  2, 16, 20,  0),
     ( 15, 11,  1, 10,  9,  0),
     (  8,  9, 10, 20, 19,  0),
     ( 14, 15,  9,  8,  7,  0),
     (  6,  7,  8, 19, 18,  0),
     ( 13, 14,  7,  6,  5,  0),
     (  4,  5,  6, 18, 17,  0),
     ( 12, 13,  5,  4,  3,  0),
     (  2,  3,  4, 17, 16,  0),
     ( 11, 12,  3,  2,  1,  0),
     
     { it doesn't describe any vertex... }
     (  0,  0,  0,  0,  0,  0),

     { here go descriptions of hexagons,
       indexed with the positive numbers: 1..20 }
     (-10, 10, -9, 11, -1,  2),
     ( -1,  3, -2, 16,-10,  1),
     ( -2,  2, -1, 12, -3,  4),
     ( -3,  5, -4, 17, -2,  3),
     ( -4,  4, -3, 13, -5,  6),
     ( -5,  7, -6, 18, -4,  5),
     ( -6,  6, -5, 14, -7,  8),
     ( -7,  9, -8, 19, -6,  7),
     ( -8,  8, -7, 15, -9, 10),
     ( -9,  1,-10, 20, -8,  9),
     ( -1,  1, -9, 15,-11, 12),
     ( -3,  3, -1, 11,-11, 13),
     ( -5,  5, -3, 12,-11, 14),
     ( -7,  7, -5, 13,-11, 15),
     ( -9,  9, -7, 14,-11, 11),
     ( -2, 17,-12, 20,-10,  2),
     ( -4, 18,-12, 16, -2,  4),
     ( -6, 19,-12, 17, -4,  6),
     ( -8, 20,-12, 18, -6,  8),
     (-10, 16,-12, 19, -8, 10));
     
     
type
  TColor = (white, black);

  TPiece =
    record
      color: TColor;
      visited: boolean;
      deg: integer;
    end;

var
  { here we put additional data about vertices of the graph }
  pieces: array [-BLACK_PIECES..WHITE_PIECES] of TPiece;

  { number of vertices of the polygon }
  n: integer;

  { description of the polygon }
  a: array [1..MAX_POLYGON_VERTICES] of integer;
  
  { these variables will contain the result }
  b, w, g: integer;


procedure BuildFootballGraph;
{ builds football graph }
var
  i: integer;
begin
  for i := -BLACK_PIECES to -1 do
    begin
      pieces[i].color := black;
      pieces[i].visited := false;
      pieces[i].deg := 5;
    end;

  for i := 1 to WHITE_PIECES do
    begin
      pieces[i].color := white;
      pieces[i].visited := false;
      pieces[i].deg := 6;
    end;
end;


procedure DFS(p: integer);
{ procedure (using DFS) counts number of white, black and green vertices,
  where p is one of the vertices of the graph which belong to the green part
  of the ball }
var
  i: integer;
begin
  if not pieces[p].visited then
    begin
      pieces[p].visited := true;
      Inc(g);
      if pieces[p].color = white then
        Dec(w)
      else { pieces[p].color = black }
	Dec(b);

      { visits adjoined pieces }
      for i := 0 to pieces[p].deg - 1 do
        if ball[p][i] <> CUT then
          DFS(ball[p][i]);
    end;
end;


procedure CutOffEdge(var p, e: integer);
begin
  ball[p][e] := CUT;
  e := (e + 1) mod pieces[p].deg;
end;


procedure FollowEdge(var p, e: integer);
var
  i, q: integer;
begin
  q := ball[p][e];

  i := 0;
  while ball[q][i] <> p do
    Inc(i);

  p := q;
  e := (i + 1) mod pieces[q].deg;
  CutOffEdge(p, e);
end;


procedure Solve;
var
  i: integer;
  piece, edge: integer;
begin
  piece := 1;
  edge := 0;
  
  for i := 1 to n do
    if a[i] = 1 then
      CutOffEdge(piece, edge)
    else { a[i] = 2 }
      FollowEdge(piece, edge);

  w := 20;
  b := 12;
  g := 0;

  DFS(piece);
end;



var
  i: integer;
  
begin
  BuildFootballGraph;
  Readln(n);
  for i := 1 to n do
    Read(a[i]);
  Solve;
  Writeln(b, ' ', w, ' ', g);
end.
