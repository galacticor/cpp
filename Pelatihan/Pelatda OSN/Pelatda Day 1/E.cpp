#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;

bool vis[50];
int n,a[50];
vi ans;

int isprime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

void rec(int deep){
	if(deep>n){
		if(isprime(a[1]+a[n])){
			for(int i=1;i<=n;i++){
				cout<<a[i];
				if(i<n){
					cout<<" ";
				}
			}
			cout<<endl;	
		}
		else return;
	}
	else{
		for(int i=1;i<=n;i++){
			if(!vis[i] && isprime(a[deep-1]+i)){
				vis[i]=true;
				a[deep]=i;
				rec(deep+1);
				vis[i]=false;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
	while(cin>>n){
		if(t>1) cout<<endl;
		a[1]=1;
		vis[1]=true;
		cout<<"Case "<<t++<<":"<<endl;
		rec(2);
	}

	return 0;
}