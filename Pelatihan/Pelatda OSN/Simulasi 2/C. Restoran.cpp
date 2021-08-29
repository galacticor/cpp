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

int ans,n,l,b,a[100005];

bool cek(int x){
	int sum=0;
	int temp;
	for(int i=1;i<=n-x+1;i++){
		temp=a[i+ x/2 -1];
        sum=0;
		for(int j=i;j<=i+x-1;j++){
			sum+=abs(a[j]-temp);
		}
        if(sum>b) return false;
	}
	return true;
}

void binser(){
	int lo=1,hi=n,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(cek(mid)){
			ans=mid;
			lo=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>l>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	binser();
	cout<<ans<<endl;
	return 0;
}