#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

bool p[100010];
int a[100010];
int n,k;


void kombinasi(int deep){
	if(deep>k){
		for(int i=1;i<=k;i++){
			cout<<a[i];
			if(i<k){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	else{
		for(int i=a[deep-1]+1;i<=n;i++){
			if(!p[i]){
				//p[i]=true;
				a[deep]=i;
				permutasi(deep+1);
			//	p[i]=false;
			}
		}
	}
}

void permutasi(int deep){
	if(deep>k){
		for(int i=1;i<=k;i++){
			cout<<a[i];
			if(i<k){
				cout<<" ";
			}
		}
		cout<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!p[i]){
				p[i]=true;
				a[deep]=i;
				permutasi(deep+1);
				p[i]=false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	a[0]=0;
	permutasi(1);
	return 0;
}