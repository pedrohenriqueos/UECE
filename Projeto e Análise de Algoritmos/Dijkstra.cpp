#include<bits/stdc++.h>
using namespace std;

//Limite para matriz é 1000 devido a entrada dos dados
//Limite dizendo apenas as arestas existentes vai pra 100000
const int MAXV = 1e5+1;
const int INF = 1e9;
vector< pair<int,int> > Grafo[MAXV];
int dist[MAXV],Quant[MAXV];
int vertices;//quantidade de vértices
char *file;
int sizefile;

int dijkstra(int b, int e){
	for(int i=0;i<MAXV;i++)
		dist[i] = INF;
	priority_queue < pair<int,int> > pq;
	dist[b] = 0;
	pq.push(make_pair(0,b));
	Quant[b] = 1;
	int quantidade = 1;
	while(!pq.empty()){
		int d = -pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(!Quant[u])
			Quant[u] = 1,quantidade++;
		if(u == e){
			cout << "Quantidade de vertices processados: " << quantidade << "\n\n";
			return d;
		}
		for(auto &w: Grafo[u]){
			int _d = w.first;
			int _w = w.second;
			if(d + _d < dist[_w]){
				dist[_w] = d + _d;
				pq.push(make_pair(-dist[_w], _w));
			}
		}
	}
	
	return dist[e];
}

bool arquivo(int argc, char *argv[]){
	if(argc!=2){
		cout << "Execução incorreta.\nFinalizar com L para Lista de Arestas\nFinalizar com M para Matriz\nA forma correta é:\n./exec ArquivoM\nou\n./exec ArquivoL\n";
		return false;
	}
	file = argv[1];
	for(sizefile=0;file[sizefile]!='\0';sizefile++);
	
	if(file[sizefile-1]!='M' and file[sizefile-1]!='L'){
		cout << "Formato de arquivo incorreto.\nFinalizar com L para Lista de Arestas\nFinalizar com M para Matriz\nA forma correta é:\n./exec ArquivoM\nou\n./exec ArquivoL\n";
		return false;
	}
	FILE *f;
	f = freopen(file,"r",stdin);
	if(f==NULL){
		cout << "Arquivo não existente!\n";
		return false;
	}
	return true;
}

void inputs(){
	bool leitura = false;
	if(file[sizefile-1]=='M')
		leitura = true;
	cin >> vertices;
	if(leitura){//Input da forma de Matriz indicando as distâncias diretas
		int Dist;
		for(int i=1;i<=vertices;i++)
			for(int j=1;j<=vertices;j++){
				cin >> Dist;
				if(i==j) continue;
				if(Dist!=-1)
					Grafo[i].push_back({Dist,j});
			}
	}else{//Input dizendo apenas as arestas que existe
		int edges;
		cin >> edges;
		int u,v,d;
		for(int i=0;i<edges;i++){
			cin >> u >> v >> d;
			Grafo[u].push_back({d,v});
			Grafo[v].push_back({d,u});
			//Em caso da aresta ser bidirecional, colocar a aresta reversa
		}
	}
}

void exec(){
	int b = 1,e = vertices;
	int distancia = dijkstra(b,e);
	if(distancia==INF)
		cout << "Nao existe um caminho de " << b << " ate " << e << ".\n";
	else
		cout << "A distancia entre "<< b << " e " << e << " : " << distancia << '\n';
}

int32_t main(int argc, char *argv[]){

	if(!arquivo(argc,argv))
		return 0;
	inputs();
	exec();


#ifdef LOCAL_DEFINE
	cerr << "\nTime: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
