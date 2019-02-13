%Entidade1
homem(pedro).
homem(thiago).
%Entidade2
mulher(maria).
mulher(claudia).
%Relacoes
humano(X) :- homem(X).
humano(X) :- mulher(X).
mortal(X) :- humano(X). 
