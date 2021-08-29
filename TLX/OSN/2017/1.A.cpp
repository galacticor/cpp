#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int sd,sm,n;
ll res,memo[2010][2010],p[300010],k[300010],l[300010];
string s;

priority_queue<ll> pq;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	res=0;
	cin>>s;
	cin>>n>>sd>>sm;
	p[n]=sm;
	for(int i=1;i<n;i++){
		cin>>p[i]>>k[i]>>l[i];
	}
	for(int i=1;i<=n;i++){
		if(sd<p[i]){
			while(!pq.empty() && sd<p[i]){
				res+=-1*pq.top();
				pq.pop();
				sd++;
			}
			if(sd<p[i]){
				cout<<"-1"<<endl;
				return 0;
			}
		}
		if(i<n){
			if(k[i]<l[i]){
				pq.push(-1*(l[i]-k[i]));
				res+=k[i];
			}
			else {
				res+=l[i];
				sd++;
			}
		}
	}
	cout<<res<<endl;
	
	return 0;
}