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
const int MOD=1000000007;

mt19937 rnd(time(0));
int n,f,x,mas,nxt,id,ans=-1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>f>>x;
        ans=-1; id=f;
	for(int i=1;i<=1000;i++){
		int tebak=rnd()%n + 1;
		cout<<"? "<<tebak<<endl;
		cin>>mas>>nxt;
		if(mas>ans && mas<x){
			ans=mas;
			id=nxt;
		}
	}
	for(int i=1;i<1000;i++){
		if(id==-1){
			break;
		}
		cout<<"? "<<id<<endl;
		cin>>mas>>nxt;
		if(mas>=x){
			cout<<"! "<<mas<<endl;
		}
                id=nxt;
	}

	cout<<"! "<<"-1"<<endl;

	return 0;
}