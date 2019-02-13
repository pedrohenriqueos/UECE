#include<bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cout << "Quantidade de cidades: " << '\n';
	cin >> N;
	int A[N][N],dist[N],a,fila[N+1],prox=0,fim=0;
	cout << "Matriz de indicação se existe caminho: " << '\n';
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> A[i][j];
	cout << "Cidade de partida: " << '\n';
	cin >> a;
	
	memset(dist,63,sizeof(dist));
	dist[a]=0;
	while(true){
		for(int i=0;i<N;i++)
			if(A[a][i] and (dist[i]>(dist[a]+A[a][i]))){
				dist[i]=dist[a]+A[a][i];
				fila[fim++]=i;
				if(fim==(N+1))
					fim=0;
			}
		if(prox!=fim){
			a=fila[prox++];
			if(prox==(N+1)) prox=0;
		}else
			break;
	}
	for(int i=0;i<N;i++){
		if(dist[i]==0x3f3f3f3f)
			dist[i]=N;
		cout << dist[i] << " ";
	}
	cout << '\n';
}
