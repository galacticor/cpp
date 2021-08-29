#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int n,ans;
string c[100010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	bool p=true;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(i>1 && c[i]!=c[i-1]){
			p=false;
		}
	}
	if(p){
		if(c[1]=="0"){
			if(n==1){
				cout<<"10"<<endl;
				return 0;
			}
			else if(n<=11){
				cout<<"100"<<endl;
				return 0;
			}
			else if(n<=111){
				cout<<"1000"<<endl;
				return 0;
			}
			else if(n<=1111){
				cout<<"10000"<<endl;
				return 0;
			}
			else if(n<=11111){
				cout<<"100000"<<endl;
				return 0;
			}
			else if(n<=111111){
				cout<<"1000000"<<endl;
				return 0;
			}
		}
		else if(c[1]=="9"){
			if(n==1){
				cout<<c[1]<<endl;
				return 0;
			}
			else if(n<=11){
				cout<<"89"<<endl;
				return 0;
			}
			else if(n<=111){
				cout<<"889"<<endl;
				return 0;
			}
			else if(n<=1111){
				cout<<"8889"<<endl;
				return 0;
			}
			else if(n<=11111){
				cout<<"88889"<<endl;
				return 0;
			}
			else if(n<=111111){
				cout<<"888889"<<endl;
				return 0;
			}
		}
		else{
			if(n==1){
				cout<<c[1]<<endl;
				return 0;
			}
			else if(n<=10){
				cout<<c[1]<<"0"<<endl;
				return 0;
			}
			else if(n<=100){
				cout<<c[1]<<"00"<<endl;
				return 0;
			}
			else if(n<=1000){
				cout<<c[1]<<"000"<<endl;
				return 0;
			}
			else if(n<=10000){
				cout<<c[1]<<"0000"<<endl;
				return 0;
			}
			else if(n<=100000){
				cout<<c[1]<<"00000"<<endl;
				return 0;
			}
		}
	}
	else{
		for(int i=1;i<=100000;i++){
			string s=to_string(i);
			int j=i;
			int k=1;
			while(s.find(c[k])!=-1 && k<=n){
				if(k==n){
					ans=i;
					cout<<ans<<endl;
					return 0;
				}
				k++;
				j++;
				s=to_string(j);
			}
			
		}
	}
	
	return 0;
}