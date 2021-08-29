#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

vector<ll> v;

ll ansatas,ansbawah,q,k,m,n,ans;

void binserbawah(ll x){
	ll lo=0, hi=v.size()-1, mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(v[mid]>=x){
			ansbawah=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}

void binseratas(ll x){
	ll lo=0, hi=v.size()-1, mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(v[mid]<=x){
			ansatas=mid;
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

	cin>>q>>k;
	for(int i=1;i<=99999;i++){
		ll bil=i;
		string s1=to_string(bil);
		string s2=s1;
		reverse(s2.begin(),s2.end());
		ll bil1=stoll(s1+s2);
		ll bil2=stoll(s1+s2.substr(1,s2.length()-1));
		if(bil1%k==0) v.push_back(bil1);
		if(bil2%k==0) v.push_back(bil2);
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=q;i++){
		cin>>m>>n;
		ansbawah=-1;
		ansatas=-1;
		binserbawah(m);
		binseratas(n);
		ans=ansatas-ansbawah+1;
		if(ansatas==-1 || ansbawah==-1){
			ans=0;
		}
		cout<<ans<<endl;
	}

	return 0;
}