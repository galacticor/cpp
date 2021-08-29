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

int ai[2000005],ans,n,a,b,c,d,ansa,ansb,ansc,ansd;
string s;

ll p[2000005],day=0;
bool pi,qi,ceks,bisa;

bool cek(int x){
	bisa=false;
	pi=false;
	qi=false;
	ceks=false;
	int ki=1,ka=ki;
	day++;
	for(ki=1;ki<=n-x+1;ki++){
		//cout<<ki<<" "<<ka<<endl;
		ceks=false;
		while(ka<=n){
			//cout<<ki<<" "<<ka<<endl;
			if(p[ai[ka]]!=day) p[ai[ka]]=day;
			else{
				break;
			}
			if(ka-ki+1==x){
				ceks=true;
				break;
			}
			ka++;
		}
		if(ceks){
			ceks=false;
			if(!pi){
				pi=true;
				a=ki;
				b=ka;
			}
			else{
				qi=true;
				c=ki;
				d=ka;
			}
			for(int i=ki;i<=ka;i++){
				p[ai[i]]=0;
			}
			ki=ka;
			ka++;
			
		}
		else{
			for(int i=ki;i<=ka;i++){
				p[ai[i]]=0;
				if(ai[i]==ai[ka]){
					ki=i;
					break;
				}
			}
		}
		if(pi && qi){
			bisa=true;
			break;
		}
	}
	if(bisa) return true;
	else return false;
}

void binser(){
	int lo=1,hi=(n+1)/2,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		//cout<<mid<<endl;
		if(cek(mid)){
			ansa=a; ansb=b;
			ansc=c; ansd=d;
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
	memset(p,0,sizeof(p));
	cin>>s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ai[i];
	}
	binser();
	cout<<ansa<<" "<<ansb<<" "<<ansc<<" "<<ansd<<endl;
	//cout<<ans<<endl;
	return 0;
}