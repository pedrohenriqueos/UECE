#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	while(getline(cin,str)){
		if(str=="q") break;
		int topo=0;
		double pilha[100],num=0.0;
		for(int i=0;i<str.size();i++){
			if(str[i]>='0' and str[i]<='9')
				num=num*10+(int)(str[i]-'0');
			else if(str[i]==' ' and str[i-1]>='0' and str[i-1]<='9'){
				pilha[topo++]=num;
				num=0;
			}else if(str[i]=='+' or str[i]=='-' or str[i]=='/' or str[i]=='*'){
				double k=0,c=0;
				if(topo>=2){
				topo-=2;
				k=pilha[topo];
				c=pilha[topo+1];
				}else if(topo==1){
					topo--;
					k=pilha[topo];
				}
				if(str[i]=='+')
					pilha[topo++]=k+c;
				else if(str[i]=='-')
					pilha[topo++]=k-c;
				else if(str[i]=='*')
					pilha[topo++]=k*c;
				else
					pilha[topo++]=k/c;
			}	
		}
		cout << pilha[topo-1] << '\n';
	}

}
