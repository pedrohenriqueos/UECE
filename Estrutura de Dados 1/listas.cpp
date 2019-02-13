#include<iostream>
#include<stdlib.h>
using namespace std;
#define inf 0x3f3f3f3f
typedef struct cel celula;
struct cel{
	int info;
	celula *prox;
};
celula* cria_lst(celula *ini){//cria uma lista encadeada
	ini=(celula *)malloc(sizeof(celula));
	ini->prox = NULL;
	return ini;
}
celula *insere_lst(int val, celula *p){//insere elementos na lista
	celula *nova;
	nova = new celula [1];
	p->prox = nova;
	nova->info = val;
	nova->prox = NULL;
	return nova;//retorno para salvar a posição do próximo elemento na lista
}
celula* busca_lst(int val,celula *ini){//busca elemento na lista
	celula *p;
	p=ini->prox;
	while(p!=NULL && p->info!=val)
		p=p->prox;
	return p;
}

celula* buscaremove_lst(int val,celula* ini){
	celula *ant = NULL; // ponteiro para elemento anterior
	celula *p = ini; // ponteiro para percorrer a lista
	while (p != NULL && p->info != val) {
		ant = p;
		p = p->prox;
	}
	if (p == NULL) return ini; // não achou: retorna lista original
	/* retira elemento da lista */
	if (ant == NULL) // retira elemento do inicio da lista
		ini = p->prox;
	else // retira elemento do meio da lista
		ant->prox = p->prox;
	free (p);
	return ini;
}
celula* Interseccao(celula *ini3,celula *ini1,celula *ini2){
	celula *p1,*p2,*p3,*psave;
	p3=ini3;
	psave=ini2->prox;
	for(p1=ini1->prox;p1!=NULL;p1=p1->prox)
		for(p2=psave;p2!=NULL;p2=p2->prox)
			if(p1->info==p2->info){
				p3=insere_lst(p1->info,p3);
				psave=p2->prox;
				break;
			}
		
	return ini3;
}
celula* remove(int k, celula *ini){
	celula *p,*ant;
	ant=NULL;
	p=ini;
	for(p=ini->prox;p!=NULL;p=p->prox){
		k--;
		if(k==0 or p->prox==NULL){ 
			if (ant == NULL)
				ini = p;
			else
				ant->prox =p->prox;	
			break;
		}
		ant=p;
	}
	return ini;
}

celula* remove_elemento(int x,celula *ini){
	celula *p,*ant;
	ant=NULL;
	p=ini;
	if(p==NULL)
		return ini;
	for(;p!=NULL;p=p->prox){
		if(p->info==x){
			if (ant == NULL)
				ini = p;
			else
				ant->prox =p->prox;
			break;
		}
		ant=p;
	}
	return ant;
}

celula *busca_remove(int x,celula *ini){
	celula *p,*ant;
	ant=NULL;
	for(p=ini;p!=NULL;p=p->prox){
		if(p->info==x){
			if (ant == NULL){
				ant = p->prox;
				ant->info = p->prox->info;
			}else
				ant->prox=p->prox;
			break;
		}
		ant=p;
	}
	return ini;
}

void percorre_lst(celula *ini){//mostra todos os elementos da lista, partindo do inicio.
	celula *p;
	for(p=ini;p!=NULL;p=p->prox)
		cout << p->info << " ";
	cout << "\n\n";
}

void percorre_lstsem(celula *ini){//mostra todos os elementos da lista, partindo do inicio.
	celula *p;
	for(p=ini;p!=NULL;p=p->prox)
		cout << p->info << " ";
	cout << "\n\n";
}


celula *insere_lstsem(int val, celula *p,celula *ant){//insere elementos na lista
	celula *nova;
	nova = new celula [1];
	if(ant!=NULL)
		ant->prox = nova;
	p=nova;
	nova->info = val;
	nova->prox = NULL;
	return nova;//retorno para salvar a posição do próximo elemento na lista
}

int main(){
	celula *p,*copia, *busca;//É necessário ter sempre um ponteiro para o inicio da lista e outro para a próxima posição da lista
	celula *p2,*copia2,*p3,*copia3;
	celula *sem,*sem1,*sem2,*sem3;
	sem3=NULL;
	sem2=NULL;
	sem2= insere_lstsem(23,sem1,sem2);
	sem=sem2;
	sem2= insere_lstsem(45,sem1,sem2);
	sem2= insere_lstsem(42,sem1,sem2);
	sem3= busca_remove(23,sem);
	cout << sem3->info << '\n';
	percorre_lstsem(sem3);
	//celula *k;	
	//for(k=sem;k!=NULL;k=k->prox)
	//	cout << k->info << " ";
	//cout << "\n\n";
	/*
	p = cria_lst(p);
	p2 = cria_lst(p2);
	p3 = cria_lst(p3);
	copia = p;//Guarda o inicio da lista
	copia2 = p2;
	copia3 = p3;
	p= insere_lst(23,p);
	p= insere_lst(45,p);
	p= insere_lst(42,p);
	p= insere_lst(5,p);
	p2= insere_lst(23,p2);
	p2= insere_lst(10,p2);
	copia = remove(6,copia);
	cout << "Elementos da lista: \n";
	percorre_lst(copia);

	copia = buscaremove_lst(45,copia);
	cout << "Elementos da lista atualizados: \n";
	percorre_lst(copia);
	
	busca = busca_lst(42,copia);
	cout << "Local  de memória do elemento buscado:\n";
	cout << busca <<"\n\n";//quando acha, existe local na memória.
	busca = busca_lst(10,copia);
	cout << "Local  de memória do elemento que não existe da lista:\n";
	cout << busca << '\n';//quando não acha o local é 0, pois não foi encotrado.
	*/
	return 0;
}
