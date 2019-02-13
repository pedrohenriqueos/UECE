//Travelling salesman problem - DP // FEITO
#include<bits/stdc++.h>
using namespace std;
#define MAXN 20 //Como a solução é com programação dinâmica, a quantidade de nós tem que ser pequena para o calculo do menor caminho ser viável, e ainda possui a limitação de 31 da bitmask
int N,dist[MAXN][MAXN],memo[1<<(MAXN)][MAXN];
//Sem a matriz memo(memorize), a solução seria complete search que deixaria o algoritmo em O(n!)
int tsp(int bitmask,int id){//O((2^n)*(n^2))
	if(memo[bitmask][id]!=-1)
		return memo[bitmask][id];
	if(bitmask==((1<<N)-1))
		return dist[id][0];
	int ans=INT_MAX;
	for(int i=0;i<N;i++)
		if(!(bitmask&(1<<i)))
			ans=min(ans,tsp((bitmask|(1<<i)),i)+dist[id][i]);
	return memo[bitmask][id]=ans;
}
int main(){
	freopen("intsp","r",stdin);//Abre sozinho o arquivo de entradas
	memset(memo,-1,sizeof memo);
	memset(dist,63,sizeof dist);
	N=20;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin >> dist[i][j];
	int out=tsp(1,0);
	cout << "Solucao do Caixeiro Viajante " << out << "\n\n";
}
