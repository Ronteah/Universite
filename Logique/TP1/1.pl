entree(crudités,6,100).
entree(taboulé,8,150).
entree(avocat,5,200).
plat(couscous,12,400).
plat(risotto,10,300).
plat(lasagnes,12,500).
dessert(glace,6,200).
dessert(fruits,5,100).
dessert(gateau,8,300).

menu(E,Pl,P,C):- entree(E,Pe,Ce), plat(Pl,Ppl,Cpl), P is Ppl + Pe, C is Cpl + Ce.
menu(D,Pl,P,C):- dessert(D,Pd,Cd), plat(Pl,Ppl,Cpl), P is Ppl + Pd, C is Cpl + Cd.











menu(E,Pl,P,C).
menu(avocat,gateau,_,_).
menu(glace,A,B,C).
menu(A,couscous,B,C).
menu(X,Y,C,_), C =< 18, C >= 18.
menu(X,Y,C,_), C =< 16.
menu(X,risotto,C,_), C =< 16.
menu(X,Y,_,C), C =< 580, C >= 480.
menu(_,_,A,C), C =< 550.