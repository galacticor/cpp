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

int prefix[503][103][103],n,m,temp,size,ans,q,t,a,xawal,xakhir,yawal,yakhir;

bool cek(int x,int ki,int at,int ka,int bw){
	temp=prefix[x][ka][bw]-prefix[x][ki-1][bw]-prefix[x][ka][at-1]+prefix[x][ki-1][at-1];
	if(size%2==1){
		if(temp>=size/2+1) return true;
		else return false;
	}
	else{
		if(temp>=size/2) return true;
		else return false;
	}
}

void binser(int ki,int at,int ka,int bw){
	int lo=1,hi=500,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(cek(mid,ki,at,ka,bw)){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	while(t--){
		cin>>n>>m>>q;
		memset(prefix,0,sizeof(prefix));
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a);
				for(int k=1;k<=500;k++){
					prefix[k][i][j]=prefix[k][i-1][j]+prefix[k][i][j-1]-prefix[k][i-1][j-1];
					if(k==a){
						prefix[k][i][j]++;
					}
				}
			}
		}
		for(int k=2;k<=500;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					prefix[k][i][j]+=prefix[k-1][i][j];
				}
			}
		}
		for(int i=1;i<=q;i++){
			cin>>xawal>>yawal>>xakhir>>yakhir;
			scanf("%d%d%d%d",&xawal,&yawal,&xakhir,&yakhir);
			size=(xakhir-xawal+1)*(yakhir-yawal+1);
			binser(xawal,yawal,xakhir,yakhir);
			printf("%d\n",ans );
		}
	}

	return 0;
}