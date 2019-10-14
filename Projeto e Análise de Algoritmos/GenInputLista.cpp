#include<bits/stdc++.h>
using namespace std;


struct rnd{
	mt19937_64 rng;
	const double EPS = 1e-9;
	rnd(unsigned _seed){
		rng.seed(_seed);
	}
	template<class T>
	T range(T l,T r){
		return (T)((rng()%((int)(r-l)+1))+(int)l);
	}
	template<class T>
	vector<T> vet(int n,T l,T r){
		vector<T> ans(n);
		for(auto &a:ans)
			a = range(l,r);
		return ans;
	}
	double drange(double l,double r){
		int l1 = log10(l), r1 = log10(r),a;
		double s;
		do{
			do{
				a = rng();
			}while(a<EPS);
			int a1 = log10(a);
			int grau = range(l1,r1);
			s = ((double)a)/((double)(pow(10,a1-grau)));
		}while(s-r>EPS or l-s>EPS);
		return s;
	}
	vector<double> dvet(int n,double l,double r){
		vector<double> ans(n);
		for(auto &a:ans)
			a = drange(l,r);
		return ans;
	}
};
int pai[100002],sz[100002];
int find(int x){
	return ((pai[x]==x)?x:pai[x] = find(pai[x]));
}

void join(int a,int b){
	a = find(a),b = find(b);
	if(a==b) return ;
	if(sz[a]>sz[b])
		pai[b] = a , sz[a]+=sz[b];
	else
		pai[a] = b , sz[b]+=sz[a];
}

int32_t main(){
	rnd gen(chrono::steady_clock::now().time_since_epoch().count());
	int n = 100000;
	for(int i=1;i<=n;i++)
		pai[i] = i,sz[i] = 1;
	long long m = gen.range((n-1LL),min(1LL*n*(n+1LL)/2LL,1000000LL));
	cout << n << " " << m << '\n';
	vector<array<int,3>> In;
	int cnt=n-1;
	set<pair<int,int>> S;
	while(m){
		int u = gen.range(1,n);
		int v = gen.range(1,n);
		if(u==v)
			continue;
		if(find(u)==find(v))
			if(cnt>0)
				continue;
		if(S.find({min(u,v),max(u,v)})!=S.end()) continue;
		S.insert({min(u,v),max(u,v)});
		join(u,v);
		int d = gen.range(5, 15);
		In.push_back({min(u,v),max(u,v),d});
		m--,cnt--;
	}
	for(auto in:In)
		cout << in[0] << " " << in[1] << " " << in[2] << '\n';
}
