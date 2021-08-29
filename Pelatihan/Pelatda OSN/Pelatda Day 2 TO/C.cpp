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

priority_queue <int> pq;

int x,jml,n,k,ans,mins;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		pq.push(a);
	}
	if(n>=k){
		while(k>1){
			pq.pop();
			k--;
		}
		cout<<pq.top()<<endl;
		return 0;
	}
	jml=n;
	mins=1e9+1;
	while(jml<k){
		x=pq.top(); pq.pop();
		if(x==1){
			cout<<"-1"<<endl;
			return 0;	
		} 
		if(x%2==1){
			pq.push(x/2);
			pq.push(x/2 + 1);
		}
		else{
			pq.push(x/2);
			pq.push(x/2);	
		}
		mins=min(mins,x/2);
		jml++;
	}
	cout<<mins<<endl;
	return 0;
}