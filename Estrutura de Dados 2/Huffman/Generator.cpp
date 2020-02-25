#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng2(chrono::steady_clock::now().time_since_epoch().count());

int sizetxt = 100000000;

int32_t main(){
	string str="";
	for(int i=0;i<sizetxt;i++){
		str.push_back((char)(rng()%('z'-'a'+1)+(rng2()%2==0?'A':'a')));
	}
	cout << str << '\n';
}






