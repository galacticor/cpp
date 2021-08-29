#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int n,s,e,sum,ans,x;
priority_queue<int> pq;

struct name
{
	int baik,jahat,beda;	
}pilih[100010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>s>>e;
	sum=s;
	for(int i=1;i<=n;i++){
		cin>>pilih[i].baik>>pilih[i].jahat;
		x=pilih[i].jahat+pilih[i].baik;
		pq.push(x);
		sum-=pilih[i].baik;
	}
	ans=n;
	while(sum<e){
		sum+=pq.top();
		pq.pop();
		ans--;
	}
	cout<<ans<<" "<<sum<<endl;

	return 0;
}