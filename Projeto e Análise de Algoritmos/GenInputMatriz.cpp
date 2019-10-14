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

int32_t main(){
	rnd gen(chrono::steady_clock::now().time_since_epoch().count());
	int n = 1000;
	int D[n+1][n+1];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j){
				D[i][i] = 0;
				continue;
			}
			int exist = gen.range(1,200);
			if(exist!=1){
				D[i][j] = D[j][i] = -1;
			}else{
				int dist = gen.range(5,20);
				D[i][j] = D[j][i] = dist;
			}
		}
	}
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=1)
				printf(" ");
			printf("%d",D[i][j]);
		}
		printf("\n");
	}
}
