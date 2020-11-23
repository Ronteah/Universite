/* TP1 Programmation logique - L2 info */


/* Relations de famille */

/* Liste des femmes */
femme(lyarra).
femme(minisa).

femme(catelyn).
femme(lysa).
femme(wylla).

femme(sansa).
femme(arya).


/* Liste des hommes */
homme(rickard).
homme(hoster).

homme(ned).
homme(benjen).
homme(edmure).
homme(jon_arryn).
homme(tyrion).

homme(jon_snow).
homme(bran).
homme(robert).


/* Relations mere-enfant */
mere(lyarra,ned).
mere(lyarra,benjen).
mere(minisa,lysa).
mere(minisa,edmure).
mere(minisa,catelyn).

mere(catelyn, sansa).
mere(catelyn,arya).
mere(catelyn,bran).
mere(wylla,jon_snow).
mere(lysa,robert).


/* Relations pere-enfant */
pere(rickard,ned).
pere(rickard,benjen).
pere(hoster,lysa).
pere(hoster,edmure).
pere(hoster,catelyn).

pere(ned, jon_snow).
pere(ned, sansa).
pere(ned,arya).
pere(ned,bran).
pere(jon_arryn,robert).


/* Couples maries */
conjoints(lyarra, rickard).
conjoints(hoster,minisa).
conjoints(catelyn,ned).
conjoints(jon_arryn,lysa).
conjoints(sansa, tyrion).



parent(X,Y):- mere(X,Y).
parent(X,Y):- pere(X,Y).

grand_mere(X,Y):- mere(X,Mere), parent(Mere,Y).

grand_pere(X,Y):- pere(X,Pere), parent(Pere,Y).

soeur(X,Y):- pere(P,Y), pere(P,X), mere(M,Y), mere(M,X), femme(X), X \= Y.
frere(X,Y):- pere(P,Y), pere(P,X), mere(M,Y), mere(M,X), homme(X), X \= Y.

cousine(X,Y):- parent(Px,X), parent(Py,Y), frere(Px,Py), femme(X).
cousine(X,Y):- parent(Px,X), parent(Py,Y), soeur(Px,Py), femme(X).

cousin(X,Y):- parent(Px,X), parent(Py,Y), frere(Px,Py), homme(X).
cousin(X,Y):- parent(Px,X), parent(Py,Y), soeur(Px,Py), homme(X).

tante(X,Y):- parent(Py,Y), soeur(X,Py).
oncle(X,Y):- parent(Py,Y), frere(X,Py).

belle_fille(X,Y):- femme(X), parent(Y,Ey), conjoints(X,Ey).
gendre(X,Y):- homme(X), parent(Y,Ey), conjoints(X,Ey).

demi_soeur(X,Y):- pere(P,Y), pere(P,X), mere(My,Y), mere(Mx,X), femme(X), My \= Mx.
demi_soeur(X,Y):- pere(Py,Y), pere(Px,X), mere(M,Y), mere(M,X), femme(X), Py \= Px.

demi_frere(X,Y):- pere(P,Y), pere(P,X), mere(My,Y), mere(Mx,X), homme(X), My \= Mx.
demi_frere(X,Y):- pere(Py,Y), pere(Px,X), mere(M,Y), mere(M,X), homme(X), Py \= Px.



grand_pere(X,Y).
grand_mere(X,Y).
soeur(X,Y).
frere(X,Y).
cousine(X,Y).
cousin(X,Y).
tante(X,Y).
oncle(X,Y).
belle_fille(X,Y).
gendre(X,Y).
demi_frere(X,Y).
demi_frere(X,Y).