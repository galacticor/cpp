#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;

int n,q,sum[100010],x,a;
ll ki,ka,anski,anska,tempki,tempka,prefix[105][100010];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>q;
	for(ll i=1;i<=n;i++){
		cin>>a;
		sum[a]++;
		for(int j=0;j<=99;j++){
			prefix[j][i]=sum[j];
		}
	}
	for(ll i=1;i<=q;i++){
		cin>>ki>>ka>>x;
		tempki=(ki-1)/n;
		tempka=ka/n;
		anski=prefix[x][n]*tempki+prefix[x][(ki-1)%n];
		anska=prefix[x][n]*tempka+prefix[x][ka%n];
		cout<<anska-anski<<endl;
	}

	return 0;
}