#include<bits/stdc++.h>
using namespace std;
#define MAXN 20		//quantidade máxima de nós-> altere dependendo do tamanho da matriz!
#define inf 0x3f3f3f3f//define para a distância considerada infinito na matriz de custo.
int N,sum,custo[MAXN][MAXN],num_aresta,grau[MAXN],dist[MAXN],memo[MAXN][MAXN];
vector<int> edges;
vector< pair<int,int> > G[MAXN];
int dijkstra(int v,int z){//dijkstra com memorize para evitar calculos desnecessários.
	if(memo[v][z]!=-1) return memo[v][z];
	memset(dist,63,sizeof(dist));
	dist[v]=0;
	priority_queue< pair<int,int> > pq;
	pq.push(make_pair(0,v));
	while(!pq.empty()){
		int u = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		memo[v][u]=memo[u][v]=min((memo[v][u]==-1)?inf:memo[v][u],d);
		if(memo[u][z]!=-1) return memo[v][z]=memo[z][v]=memo[v][u]+memo[u][z];
		if(d>dist[u]) continue;
		if(u==z) return memo[v][z]=memo[z][v]=d;
		for(pair<int,int> j:G[u]){
			int w=j.second,_d=j.first;
			if(dist[w]>d+_d){
				dist[w]=d+_d;
				pq.push(make_pair(-dist[w],w));
			}
		}
	}
	return memo[v][z]=memo[z][v]=inf;
}
int main(){
	freopen("incpp","r",stdin);//Abre sozinho o arquivo de entradas
	memset(memo,-1,sizeof memo);
	N=20;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			char c;
			cin >> c;
			custo[i][j]=(c=='-')?inf:(int)(c-'0');
			if(custo[i][j]!=inf and i!=j){
				grau[i]++;
				G[i].push_back({custo[i][j],j});
				if(j>i)//A matriz sempre é simétrica nesse problema!
					sum+=custo[i][j];
			}
		}
	for(int i=0;i<N;i++)
		if(grau[i]&1)
			edges.push_back(i);
	int parc=INT_MAX;
	do{
		int aux=0;
		for(int i=1;i<edges.size();i+=2)
			aux+=dijkstra(edges[i],edges[i-1]);
		parc=min(parc,aux);
	}while(next_permutation(edges.begin(),edges.end()));
	cout << "Solucao do Carteiro Chines " << sum+parc << '\n';
}
