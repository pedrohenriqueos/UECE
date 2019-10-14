#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> Map;
int32_t main(){
	int n,val;
	scanf("%d",&n);
	vector<array<int,3>> List;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&val);
			if(val>0 and j>i)
				List.push_back({i,j,val});
		}
	printf("%d %d\n",n,(int)List.size());
	for(auto a:List)
		printf("%d %d %d\n",a[0],a[1],a[2]);
}
