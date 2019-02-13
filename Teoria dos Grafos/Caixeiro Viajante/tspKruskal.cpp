//Travelling salesman problem - Kruskal //FEITO
#include<bits/stdc++.h>
using namespace std;
#define MAXN 20
int N,mst,pai[MAXN],cor[MAXN],custo[MAXN][MAXN];
vector<int> Pre,MST[MAXN],Saida;
int find(int x){
	return (pai[x]==x?x:pai[x]=find(pai[x]));
}

void join(int a,int b){
	a=find(a),b=find(b);
	pai[a]=b;
}

void dfs(int v){
	Pre.push_back(v);
	cor[v]=1;
	for(int u:MST[v])
		if(!cor[u])
			dfs(u);
}

int main(){
	freopen("intsp","r",stdin);//Abre sozinho o arquivo de entradas
	priority_queue< pair<int,pair<int,int> > > pq;
	N=20;
	for(int i=0;i<N;i++){
		pai[i]=i;
		for(int j=0;j<N;j++)
			cin >> custo[i][j],pq.push(make_pair(-custo[i][j],make_pair(i,j)));
	}
	while(!pq.empty()){
		pair<int,pair<int,int> > k = pq.top();
		pq.pop();
		if(find(k.second.first)!=find(k.second.second)){
			MST[k.second.first].push_back(k.second.second);
			MST[k.second.second].push_back(k.second.first);
			join(k.second.first,k.second.second);
			mst+=(-k.first);
		}
	}
	int out=INT_MAX;
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
