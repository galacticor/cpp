#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int a,b,c,temp1,temp2,temp3,t,z;

bool cek(int x){
	int p;
	p=sqrt(x);
	if(p*p==x){
		return true;
	}
	else return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>a>>b>>c;
		bool p=false,q=false;
		for(int i=-100;i<=100;i++){
			for(int j=-100;j<=100;j++){
				z=a-i-j;
				if(i!=j && j!=z && i!=z && i*j*z==b && i*i+j*j+z*z==c){
					cout<<i<<" "<<j<<" "<<z<<endl;
					p=true;
					q=true;
					break;
				}
			}
			if(p) break;
		}
		if(q) continue;
		cout<<"No solution."<<endl;
	}

	return 0;
}