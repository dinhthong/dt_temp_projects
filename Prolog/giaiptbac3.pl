solve(A,B,C):-
D = B*B - 4*A*C,
reply(A,B,D),nl.
reply(_,_,D):-
D < 0,
write("No solution"),!.
reply(A,B,D):-
D = 0,
X = -B/(2*A),
write("X = ",X),!.
reply(A,B,D):-
X1 = (-B +sqrt(D))/(2*A),
X2 = (-B -sqrt(D))/(2*A),
write("X1 = ",X1," and X2 = ",X2).
