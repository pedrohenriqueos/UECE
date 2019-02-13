#include<bits/stdc++.h>
using namespace std;

typedef struct _pilha pilha;

struct _pilha{
	int info;
	pilha *prox;
	_pilha(int a){
		info=a;
		prox=NULL;
	}
};
pilha *root;
void push(int valor){//basta passar a raiz sempre
	pilha *a;
	pilha *p;
	p=root;
	a=NULL;
	while(p!=NULL){
		a=p;
		p=p->prox;
	}
	if(a==NULL)
		root=new _pilha(valor);
	else
		a->prox=new _pilha(valor);
}

bool empty(){
	return root==NULL;
}

void pop(){
	pilha *a,*p;
	p=root;
	a=NULL;
	while(p->prox!=NULL){
		a=p;
		p=p->prox;
	}
	if(a==NULL)
		root=NULL;
	else
		a->prox=NULL;
}

int top(){
	pilha *a,*p;
	p=root;
	a=NULL;
	while(p->prox!=NULL){
		a=p;
		p=p->prox;
	}
	return p->info;
}
void pushv(int pilha[],int *topo,int valor){
	pilha[*topo]=valor;
	*topo=*topo+1;
}
void popv(int *topo){
	*topo=*topo-1;
}
int topv(int pilha[],int topo){
	return pilha[topo-1];
}
bool emptyv(int topo){
	return topo==0;
}
int main(){
	int pilhaA[10],topoA=0;
	push(10);
	pushv(pilhaA,&topoA,10);
	push(5);
	pushv(pilhaA,&topoA,5);
	push(1);
	pushv(pilhaA,&topoA,1);
	while(!empty()){
		cout << top() << " ";
		pop();
	}
	cout << '\n';
	while(!emptyv(topoA)){
		cout << topv(pilhaA,topoA) << " ";
		popv(&topoA);
	}
	cout << '\n';
}
