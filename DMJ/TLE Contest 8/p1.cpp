#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

ll a[100010],ta[100010],n;

long double m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>ta;
		if(a==0){
			if(ta!=0){
				cout<<"no"<<endl;
				return 0;	
			}
			else continue;
		}
		m=y/x;
		if(i>1){
			if(m!=temp){
				cout<<"no"<<endl;
				return 0;
			}
		}
		temp=m;
	}
	cout<<"yes"<<endl;
	return 0;
}