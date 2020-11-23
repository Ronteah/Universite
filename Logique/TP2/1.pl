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

gluten(taboulé).
gluten(couscous).
gluten(lasagnes).
gluten(gateau). 


menu_sans_gluten(X,Pl,P,C):- menu(X,Pl,P,C), \+gluten(X), \+gluten(Pl).






menu_sans_gluten(A,B,C,D).