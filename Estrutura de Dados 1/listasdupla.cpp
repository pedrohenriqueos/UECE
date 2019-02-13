#include<bits/stdc++.h>
using namespace std;

typedef struct cel2 celula2;

struct cel2 {
	int info;
	celula2 *ant;
	celula2 *prox;
};
celula2* cria_lst2(celula2 *ini){//cria uma lista encadeada
	ini=(celula2 *)malloc(sizeof(celula2));
	ini->prox = NULL;
	ini->ant = NULL;
	return ini;
}

celula2* insere_lst2 (celula2* p, int val) {
	celula2 *novo;
	novo= new celula2 [1];
	novo->info = val;
	novo->prox = NULL;
	novo->ant = p;
	if(p != NULL)// verifica se lista não está vazia
		p->prox = novo;
	return novo;
}

void percoreini(celula2 *ini){
	celula2 *p;
	for(p=ini->prox;p!=NULL;p=p->prox)
		cout << p->info << " ";
	cout << "\n\n";

}

void percorefim(celula2 *ini){
	celula2 *p;
	for(p=ini;p->ant!=NULL;p=p->ant)
		cout << p->info << " ";
	cout << "\n\n";

}

int main(){
	celula2 *p,*copia;	
	p=cria_lst2(p);
	copia=p;
	p=insere_lst2(p,20);
	p=insere_lst2(p,10);
	p=insere_lst2(p,5);	
	percoreini(copia);
	percorefim(p);
}
