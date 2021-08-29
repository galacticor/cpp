#include <bits/stdc++.h>
using namespace std;

int n,sum,a[200],jum;

int main(){
	bool p=false;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		jum+=a[i];
	}
	if(jum!=0){
		cout<<"YES"<<endl;
		cout<<"1"<<endl<<"1"<<" "<<n<<endl;
	}
	else{
		for(int i=2;i<=n;i++){
			if(sum[i]!=0){
				temp=i;
				p=true;
				break;
			}
			if(p){
				cout<<"YES"<<endl;
				cout<<"2"<<endl;
				cout<<"1"<<" "<<temp<<endl;
				cout<<temp+1<<" "<<cout<<n<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
		}

	}
	
	
	return 0;

}