//Travelling salesman problem - Christofides algorithm //FEITO ?
#include<bits/stdc++.h>
using namespace std;
#define MAXN 20
int N,mst,pai[MAXN],cor[MAXN],custo[MAXN][MAXN],grau[MAXN],dist[MAXN],distF[MAXN][MAXN],sum;
vector<int> Pre,MST[MAXN],Saida,vertices;

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
void adcAresta(int p,int d,int c,int u){
	Arestas.push_back(_Aresta(p,d,c,u));
	MST[p].push_back(Arestas.size()-1);
	Arestas.push_back(_Aresta(d,p,c,u));
	MST[d].push_back(Arestas.size()-1);
}
int find(int x){
	return (pai[x]==x?x:pai[x]=find(pai[x]));
}
void join(int a,int b){
	a=find(a),b=find(b);
	pai[a]=b;
}

void reset(int v){
	for(int u:MST[v])
		if(Arestas[u].u){
			Arestas[u].u=Arestas[u^1].u=0;
			reset(Arestas[u].d);
		}
}
void dfs(int v){
	Pre.push_back(v);
	for(int u:MST[v])
		if(!Arestas[u].u){
			Arestas[u].u=Arestas[u^1].u=1;
			dfs(Arestas[u].d);
		}
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
		for(int j:MST[u]){
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
	return make_pair(0x3f3f3f3f,out);
}

int main(){
	freopen("intsp","r",stdin);//Abre sozinho o arquivo de entradas
	priority_queue< pair<int,pair<int,int> > > pq;
	N=20;
	for(int i=0;i<N;i++){
		pai[i]=i;
		for(int j=0;j<N;j++){
			cin >> custo[i][j];
			distF[i][j]=custo[i][j];
			if(j>i)//Matriz sempre é simétrica
				pq.push(make_pair(-custo[i][j],make_pair(i,j)));
		}
	}
	while(!pq.empty()){
		pair<int,pair<int,int> > k = pq.top();
		pq.pop();
		if(find(k.second.first)!=find(k.second.second)){
			grau[k.second.first]++;
			grau[k.second.second]++;
			adcAresta(k.second.first,k.second.second,-k.first,0);
			join(k.second.first,k.second.second);
			mst+=(-k.first);
		}
	}
	for(int i=0;i<N;i++)
		if(grau[i]&1)
			vertices.push_back(i);
	/*Marcação da alteração*/
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				distF[i][j]=min(distF[i][j],distF[i][k]+distF[k][j]);
	priority_queue<pair<int,pair<int,int> > > pq2;
	for(int i=0;i<N;i++)
		for(int j=i+1;j<N;j++)
			pq2.push({-distF[i][j],{i,j}});
	vector<int> usados;
	int output=0;
	while(!pq2.empty()){
		int val=-pq2.top().first;
		pair<int,int> ponto=pq2.top().second;
		pq2.pop();
		if(find(vertices.begin(),vertices.end(),ponto.first)!=vertices.end() and 
		   find(vertices.begin(),vertices.end(),ponto.second)!=vertices.end() and 
		   find(usados.begin(),usados.end(),ponto.first)==usados.end() and
		   find(usados.begin(),usados.end(),ponto.second)==usados.end()){
				usados.push_back(ponto.first),usados.push_back(ponto.second);
				adcAresta(ponto.first,ponto.second,val,0);
				output+=val;
		}
	}
	/*Marcação da alteração*/
	/*
	pair<int,vector< vector<int> > > Ot;
	Ot.first=0x3f3f3f3f;
	do{ // O ideal seria verificar todos os caminhos, porém existe 16 vertices de grau impar
		int aux=0; //deixando a complexidade desse algoritmo inviável... O(16!*complexidade da dijkstra)
		vector< vector<int> > Parc;
		for(int i=1;i<vertices.size();i++){
			pair<int,vector<int> > k= dijkstra(vertices[i-1],vertices[i]);
			aux+=k.first;
			Parc.push_back(k.second);
		}
		if(Ot.first>aux)
			Ot=make_pair(aux,Parc);
	}while(next_permutation(vertices.begin(),vertices.end()));
	vector< vector<int> > Aux=Ot.second;
	for(int i=0;i<Aux.size();i++)
		for(int u:Aux[i])
			adcAresta(Arestas[u].p,Arestas[u].d,Arestas[u].c,Arestas[u].u);*/
	sum=0x3f3f3f3f;
	for(int id=0;id<N;id++){
		Pre.clear();
		if(id)
			reset(id-1);
		dfs(id);
		set<int> S;
		int parc=0;
		vector<int> ParcS;
		for(int i=0;i<Pre.size();i++)
			if(S.find(Pre[i])==S.end()){
				ParcS.push_back(Pre[i]);
				S.insert(Pre[i]);
			}
		ParcS.push_back(Pre[0]);
		for(int i=1;i<ParcS.size();i++)
			parc+=custo[ParcS[i-1]][ParcS[i]];
		if(sum>parc and ParcS.size()==(N+1))
			sum=parc,Saida=ParcS;
	}
	cout << "Solucao do Caixeiro Viajante " << sum << "\n\n";
	cout << "Circuito:";
	for(int i=0;i<Saida.size();i++)
		cout << " " << Saida[i];
	cout << '\n';
}
