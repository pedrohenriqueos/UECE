//URI - 1200 - Operações em ABP I
#include<bits/stdc++.h>
using namespace std;

typedef struct Node no;
struct Node{
	int info;
	no *esq;
	no *dir;
	Node(int a){
		info=a;
		esq=dir=NULL;
	}
};

void adc_no(no *root, int a){
	if((root->info)>a){
		if(root->esq==NULL)
			root->esq= new Node(a);
		else
			adc_no(root->esq,a);
	}else{
		if(root->dir==NULL)
			root->dir= new Node(a);
		else
			adc_no(root->dir,a);
	}
}

void preordem(no* root){
	cout << " " << (root->info);
	if(root->esq!=NULL)
		preordem(root->esq);
	if(root->dir!=NULL)
		preordem(root->dir);
}
void posordem(no* root){
	if(root->esq!=NULL)
		posordem(root->esq);
	if(root->dir!=NULL)
		posordem(root->dir);
	cout << " " << root->info;
}
void inordem(no* root){
	if(root->esq!=NULL)
		inordem(root->esq);
	cout << " " << root->info;
	if(root->dir!=NULL)
		inordem(root->dir);
}
int main(){
	int T,N,a,caso=1;
	cin >> T;
	while(T--){
		no *root;
		root=NULL;
		cin >> N;
		for(int i=0;i<N;i++){
			cin >> a;
			if(root==NULL)
				root= new Node(a);
			else
				adc_no(root,a);
		}
		cout << "Case " << caso++ << ":\n";
		cout << "Pre.:";
		preordem(root);
		cout << "\nIn..:";
		inordem(root);
		cout << "\nPost:";
		posordem(root);
		cout << "\n\n"; 
	}
}
