investidor(dependentes(pedro,1),quantidade_poupada(pedro,20000),ganho(pedro,40000,'estavel')).
investidor(dependentes(ricardo,1),quantidade_poupada(ricardo,20000),ganho(ricardo,100000,'estavel')).
investidor(dependentes(joao,4),quantidade_poupada(joao,45000),ganho(joao,90000,'estavel')).
investidor(dependentes(erica,1),quantidade_poupada(erica,20000),ganho(erica,100000,'instavel')).
%Relacoes
poupança(X,Y) :- investidor(dependentes(X,Z),quantidade_poupada(X,Q),_),maior_que((Q/Z),15000,Y).
min_poupança(X,Y) :- investidor(dependentes(X,Z),_,_),Y is 15000*Z.
renda(X,Z) :- investidor(dependentes(X,Q),_,ganho(X,S,V)),maior_que(S,(45000+(12000*Q)),Z),V = 'estavel'.
renda(X,Z) :- investidor(_,_,ganho(X,_,V)),V = 'instavel', Z = 'inadequado'.
min_renda(X,Y) :- investidor(dependentes(X,Z),_,_), Y is 45000 + (12000*Z).
maior_que(X,Y,'adequado') :- X>=Y.
maior_que(X,Y,'inadequado') :- X<Y.
investimento(X,'poupança') :- poupança(X,Y), Y = 'inadequado'.
investimento(X,'açoes') :- poupança(X,Y), Y = 'adequado', renda(X,Z),Z='adequado'.
investimento(X,'combinação') :- renda(X,Y), Y = 'inadequado',poupança(X,Z),Z='adequado'.
