//URI - 1256 - Tabelas Hash
#include<bits/stdc++.h>
using namespace std;

typedef struct _list List;

struct _list{
	int info;
	List* prox;
	_list(int a){
		info=a;
		prox=NULL;
	}
};

void adc_elemento(List *root,int a){
	List *k=root;
	List *p=NULL;
	while(k!=NULL){
		p=k;
		k=k->prox;
	}
	p->prox=new _list(a);
}
int T,N,H,a;
int main(){
	int caso=1;
	cin >> T;
	while(T--){
		cin >> H >> N;
		List* vet[H];
		for(int i=0;i<H;i++)
			vet[i]=NULL;
		while(N--){
			cin >> a;
			if(vet[a%H]==NULL)
				vet[a%H]=new _list(a);
			else
				adc_elemento(vet[a%H],a);
		}
		if(caso!=1)
			cout << '\n';
		caso++;
		for(int i=0;i<H;i++){
			cout << i;
			for(List* a=vet[i];a!=NULL;a=a->prox){
				cout << " -> " << a->info;
			}
			cout << " -> \\\n";
		}
	}

}
