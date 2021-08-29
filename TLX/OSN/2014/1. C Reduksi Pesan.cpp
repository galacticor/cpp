#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

string sub;
char c[100005];
int n,q,x,y,k,anskiri,anskanan,ans;
struct name
{
	char cr;
	int ki,ka;
}haha[100005];

void binserkiri(int x){
	int lo=1,hi=k,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(haha[mid].ka>=x){
			anskiri=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}

void binserkanan(int x){
	int lo=1,hi=k,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(haha[mid].ki<=x){
			anskanan=mid;
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

	cin>>sub;
	cin>>n>>q;
	k=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(i==1){
			k++;
			haha[k].cr=c[i];
			haha[k].ki=i;
		}
		else if(c[i]!=c[i-1]){
			haha[k].ka=i-1;
			k++;
			haha[k].cr=c[i];
			haha[k].ki=i;
		}
		if(i==n){
			haha[k].ka=i;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		string stemp="";
		binserkanan(y);
		binserkiri(x);
		ans=anskanan-anskiri+1;
		cout<<ans;
		if(ans<10){
			for(int j=anskiri;j<=anskanan;j++){
				stemp+=haha[j].cr;
			}
			cout<<" "<<stemp;
		}
		cout<<endl;
	}

	return 0;
}