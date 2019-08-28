likes(tan,phuoc).
likes(phuoc,tan).
likes(thai,phuoc).
dating(X,Y):-likes(X,Y),likes(Y,X).
friendzone(X,Y):- likes(X,Y);likes(Y,X).
