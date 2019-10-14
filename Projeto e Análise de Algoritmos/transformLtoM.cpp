#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> Map;
int32_t main(){
	int n,m,u,v,d;
	cin >> n >> m;
	vector<array<int,3>> List;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&u,&v,&d);
		Map[{min(u,v),max(u,v)}] = d;
	}
	printf("%d\n",n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=1)
				printf(" ");
			if(i==j)
				printf("0");
			else if(Map.count({min(i,j),max(i,j)}))
				printf("%d",Map[{min(i,j),max(i,j)}]);
			else
				printf("-1");
		}
		printf("\n");
	}
}
