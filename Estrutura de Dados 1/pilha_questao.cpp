#include<bits/stdc++.h>
using namespace std;

int main(){
	string pilha[100],aux="",a;
	int topo=0;
	getline(cin,a);
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]==' '){
			pilha[topo++]=aux;
			aux="";
		}else{
			aux+=a[i];
		}
	}
	pilha[topo++]=aux;
	while(topo--){
		cout << pilha[topo] << ' ';
	}
	cout << '\n';
}	
