#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

std::deque<int> d;

int a,sum,mins,ans,n,k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mins=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		d.push_back(a);
		sum+=a;
		if(d.size()==k){
			if(sum<mins){
				mins=sum;
				ans=i-k+1;
			}
			sum-=d.front();
			d.pop_front();
		}
	}
	cout<<ans<<endl;

	return 0;
}