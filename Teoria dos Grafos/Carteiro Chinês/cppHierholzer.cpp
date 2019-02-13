//Chinese Postman problem - FEITO
#include<bits/stdc++.h>
using namespace std;
#define MAXN 20		//quantidade máxima de nós-> altere dependendo do tamanho da matriz de custo!
#define inf 0x3f3f3f3f//define para a distância considerada infinito na matriz de custo.
int N,sum,custo[MAXN][MAXN],num_aresta,grau[MAXN],dist[MAXN];
vector<int> vertices,Ord;
struct _Aresta{
	int p,c,d,u;
	_Aresta(int _p,int _d,int _c,int _u){
		p=_p;
		c=_c;
		d=_d;
		u=_u;
	}
};
typedef struct _Aresta Aresta;
vector<Aresta> Arestas;
vector<int> G[MAXN];
void adcAresta(int p,int d,int c,int u){
	Arestas.push_back(_Aresta(p,d,c,u));
	G[p].push_back(Arestas.size()-1);
	Arestas.push_back(_Aresta(d,p,c,u));
	G[d].push_back(Arestas.size()-1);
}
vector<int> Circuito(int a){//O(E+V)
	stack<int> vertices;
	vector<int> circuito;
	vertices.push(a);
	int atual_v=a;
	while(!vertices.empty()){
		if(grau[atual_v]){
			vertices.push(atual_v);
			int usada;
			do{
				usada= G[atual_v].back();
				G[atual_v].pop_back();
			}while(Arestas[usada].u);
			grau[Arestas[usada].p]--;
			grau[Arestas[usada].d]--;
			Arestas[usada].u=Arestas[usada^1].u=1;
			atual_v=Arestas[usada].d;
		}else{
			circuito.push_back(atual_v);
			atual_v=vertices.top();
			vertices.pop();
		}
	}
	reverse(circuito.begin(),circuito.end());
	return circuito;
}

pair<int,vector<int> > dijkstra(int v,int z){
	memset(dist,63,sizeof(dist));
	dist[v]=0;
	priority_queue< pair<int,pair<int,vector<int> > > > pq;
	vector<int> _A;
	pq.push(make_pair(0,make_pair(v,_A)));
	while(!pq.empty()){
		int u = pq.top().second.first;
		int d = -pq.top().first;
		vector<int> Parc= pq.top().second.second;
		pq.pop();
		if(d>dist[u]) continue;
		if(u==z) return make_pair(d,Parc);
		for(int j:G[u]){
			int w=Arestas[j].d,_d=Arestas[j].c;
			if(dist[w]>d+_d){
				dist[w]=d+_d;
				vector<int> _Parc=Parc;
				_Parc.push_back(j);
				pq.push(make_pair(-dist[w],make_pair(w,_Parc)));
			}
		}
	}
	vector<int> out;
	return make_pair(inf,out);
}
int main(){
	freopen("incpp","r",stdin);//Abre sozinho o arquivo de entradas
	N=20;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			char c;
			cin >> c;
			custo[i][j]=(c=='-')?inf:(int)(c-'0');
			if(custo[i][j]!=inf and i!=j){
				grau[i]++;
				if(j>i){//A matriz sempre é simétrica nesse problema!
					adcAresta(i,j,custo[i][j],0);
					sum+=custo[i][j];
				}
			}
		}
	for(int i=0;i<N;i++)
		if(grau[i]&1)
			vertices.push_back(i);
	int parc=INT_MAX;
	vector< vector<int> > Caminhos;
	do{
		vector< vector<int> > auxV;
		int aux=0;
		for(int i=1;i<vertices.size();i+=2){
			pair<int,vector<int> > k=dijkstra(vertices[i],vertices[i-1]);
			aux+=k.first;
			auxV.push_back(k.second);
		}
		if(parc>aux){
			parc=aux;
			Caminhos=auxV;
		}
	}while(next_permutation(vertices.begin(),vertices.end()));
	for(int i=0;i<Caminhos.size();i++)
		for(int k1:Caminhos[i]){
			grau[Arestas[k1].p]++;
			grau[Arestas[k1].d]++;
			adcAresta(Arestas[k1].p,Arestas[k1].d,Arestas[k1].c,Arestas[k1].u);
		}
	Ord=Circuito(0);
	cout << "Solucao do Carteiro Chines " << sum+parc << "\n\n";
	cout << "Circuito:";
	for(int i=0;i<Ord.size();i++)
		cout << " " << Ord[i];
	cout << '\n';	
}
