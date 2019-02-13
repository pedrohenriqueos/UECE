//Travelling salesman problem - Prim
#include<bits/stdc++.h>
using namespace std;
#define MAXN 20 //Quantidade de nós
int N,dist[MAXN],cor[MAXN],custo[MAXN][MAXN],ponto[MAXN];
vector< pair<int,int> > G[MAXN];
vector<int> MST[MAXN],Pre;

void dfs(int v){
	Pre.push_back(v);
	cor[v]=1;
	for(int u:MST[v])
		if(!cor[u])
			dfs(u);
}
void prim(int v){
	int _mst=0;
	memset(cor,0,sizeof cor);
	memset(dist,63,sizeof dist);
	dist[v]=0;
	priority_queue< pair<int,int> > pq;
	pq.push(make_pair(0,v));
	while(!pq.empty()){
		int u= pq.top().second;
		pq.pop();
		if(cor[u]) continue;
		cor[u]=1;
		for(pair<int,int> w:G[u])
			if(dist[w.second]>w.first and !cor[w.second]){
				ponto[w.second]=u;
				dist[w.second]=w.first;
				pq.push(make_pair(-w.first,w.second));
			}
	}
}

int main(){
	freopen("intsp","r",stdin);//Abre sozinho o arquivo de entradas
	memset(ponto,-1,sizeof ponto);
	N=20;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin >> custo[i][j];
			G[i].push_back(make_pair(custo[i][j],j));
		}
	prim(0);
	int out=INT_MAX;
	vector<int> Saida;
	for(int i=0;i<N;i++)
		if(ponto[i]!=-1){
			MST[ponto[i]].push_back(i);
			MST[i].push_back(ponto[i]);
		}
	for(int i=0;i<N;i++){//Aproximação do menor caminho ótimo
		int parc=0;
		memset(cor,0,sizeof cor);
		Pre.clear();
		dfs(i);
		Pre.push_back(i);
		if(Pre.size()==(N+1)){
			for(int i=1;i<Pre.size();i++)
				parc+=custo[Pre[i-1]][Pre[i]];
			if(out>parc)
				out=parc,Saida=Pre;
		}
	}
	cout << "Solucao do Caixeiro Viajante " << out << "\n\n";
	cout << "Circuito:";
	for(int i=0;i<Saida.size();i++)
		cout << " " << Saida[i];
	cout << '\n';
}
