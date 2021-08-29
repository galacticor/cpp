#include <bits/stdc++.h>
using namespace std;

int n,m,bb[1010],sp[1010],k,sum;
bool p;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>bb[i];
	}
	for(int i=1;i<=m;i++){
		cin>>sp[i];
	}
	sort(bb+1,bb+n+1);
	sort(sp+1,sp+m+1);
	for(int i=1;i<=n;i++){
		p=false;
		while(!p && sp[k]<bb[i]+2 && k<=m){
			if(bb[i]==sp[k] || bb[i]+1==sp[k]){
				k++;
				p=true;
				sum++;
			}
			else{
				k++;
			}
		}
	}
	cout<<sum<<endl;
	return 0;

}