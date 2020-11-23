/* TP2 Programmation logique - L2 info */


/* Trajets possibles en tram, train, voiture ou metro */

enTram(universite, patinoire).
enTram(universite,gareLeMans).
enTram(universite, antares).

enTrain(gareLeMans,montparnasse).
enTrain(gareLeMans,laval).
enTrain(gareLeMans,nantes).

enVoiture(antares,angers).
enVoiture(angers,nantes).
enVoiture(patinoire,laval).
enVoiture(laval,rennes).

enMetro(montparnasse,tourEiffel).
enMetro(montparnasse,museeLouvre).



trajet(X,Y,K):- enTram(X,Y).
trajet(X,Y,K):- enTrain(X,Y).
trajet(X,Y,K):- enVoiture(X,Y).
trajet(X,Y,K):- enMetro(X,Y).

voyage(X,Y,K):- trajet(X,Y,_).
voyage(X,Y,K):- trajet(X,Z,K2), voyage(Z,Y,K+K2).

?- voyage(universite,X).
X = patinoire ;
X = gareLeMans ;
X = antares ;
X = laval ;
X = rennes ;
X = montparnasse ;
X = laval ;
X = nantes ;
X = tourEiffel ;
X = museeLouvre ;
X = rennes ;
X = angers ;
X = nantes ;

?- voyage(X,nantes).
X = gareLeMans ;
X = angers ;
X = universite ;
X = universite ;
X = antares ;


