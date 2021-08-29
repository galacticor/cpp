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

int n,k,a[100005];
bool done;

struct name
{
	int powe,idx;	
}keraj[100005];

bool cmp(name a,name b){
	return a.powe>b.powe;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k;
	for(int i=1;i<=k;i++){
		cin>>keraj[i].powe;
		keraj[i].idx=i;
	}
	sort(keraj+1,keraj+k+1,cmp);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	done=false;
	int ans=0;
	while(!done){
		done=true;
		ans++;
		for(int i=1;i<=k;i++){
			int x=keraj[i].idx;
			int y=keraj[i].powe;
			for(int j=1;j<=n;j++){
				//cout<<a[j]<<endl;
				if(j>1 && a[j]==x && a[j-1]!=x ){
					//cout<<"a"<<endl;
					for(int k=j-1;k>=max(1,j-y);k--){
						//cout<<k<<endl;
						int jarak=j-k;
						cout<<jarak<<' '<<a[k]<<" ";
						int temp;
						for(int l=1;l<=k;l++){
							if(keraj[l].idx==a[k]){
								temp=l;
								break;
							}
						}
						if(jarak<=y-keraj[temp].powe) a[k]=a[j];
						cout<<a[k]<<endl;
					}
					done=false;
				}
				if(a[j]==x && a[j+1]!=x){
					//cout<<"a"<<endl;
					for(int k=j+1;k<=min(n,j+y);k++){
						int jarak=k-j;
						int temp;
						for(int l=1;l<=k;l++){
							if(keraj[l].idx==a[k]){
								temp=l;
								break;
							}
						}
						if(jarak<=y-keraj[temp].powe) a[k]=a[j];
					}
					done=false;
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	cout<<ans<<endl;
	return 0;
}