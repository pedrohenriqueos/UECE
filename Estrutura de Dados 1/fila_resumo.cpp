#include<bits/stdc++.h>
using namespace std;

typedef struct _fila fila;
struct _fila{
	int info;
	fila *prox;
	_fila(int a){
		info=a;
		prox=NULL;
	}
};
fila *root;

void push_back(int valor){
	fila *p, *a;
	p=root;
	a=NULL;
	while(p!=NULL){
		a=p;
		p=p->prox;
	}
	if(a==NULL)
		root=new _fila(valor);
	else
		a->prox=new _fila(valor);
}
int front(){
	return root->info;
}
void pop_front(){
	root=root->prox;
}
bool empty(){
	return root==NULL;
}

int main(){
	push_back(10);
	push_back(5);
	push_back(1);
	while(!empty()){
		cout << front() << " ";	
		pop_front();
	}
	cout << '\n';
}
