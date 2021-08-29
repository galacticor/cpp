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

int par[40005],n,m,k;
std::vector<pair<pii,int> > batu,beton,ans;

int root(int a){
	if(par[a]==a) return a;
	else return par[a]=root(par[a]);
}

bool connect(int a,int b){
	return root(a)==root(b);
}

void merge(int a,int b){
	int x=root(a);
	int y=root(b);
	if(x!=y){
		par[x]=y;

	}
}
void init(){
	for(int i=1;i<=n;i++){
		par[i]=i;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen ("masuk.txt","r",stdin);

	cin>>n>>m>>k;
	init();
	int stone=0;
	int tot=0,cnt=0;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(c==1){
			beton.push_back({{a,b},c});
		}
		else{
			batu.push_back({{a,b},c});
			stone++;
		}
	}
	if(stone<k){
		cout<<"no solution"<<endl;
		return 0;
	}
	for(int i=0;i<(int)beton.size();i++){
		int a=beton[i].fi.fi;
		int b=beton[i].fi.se;
		int c=beton[i].se;
		if(!connect(a,b)){
			//cout<<a<<" "<<b<<endl;
			merge(a,b);
			//ans.push_back({{a,b},c});
			tot++;
		}
	}
	for(int i=0;i<(int)batu.size();i++){
		int a=batu[i].fi.fi;
		int b=batu[i].fi.se;
		int c=batu[i].se;

		if(!connect(a,b)){
			//cout<<a<<" "<<b<<endl;
			merge(a,b);
			ans.push_back({{a,b},c});
			cnt++;
			tot++;
		}
	}
	//cout<<tot<<" "<<cnt<<endl;
	if(tot!=n-1 || cnt>k){
		cout<<"no solution"<<endl;
		return 0;
	}
	tot=0;

	if(cnt<k){
		init();
		for(int i=0;i<(int)ans.size();i++){
			int a=ans[i].fi.fi;
			int b=ans[i].fi.se;
			if(!connect(a,b)){
				tot++;
				//cout<<a<<" "<<b<<endl;
				merge(a,b);
			}
		}
		for(int i=0;i<(int)batu.size();i++){
			int a=batu[i].fi.fi;
			int b=batu[i].fi.se;
			int c=batu[i].se;
			if(!connect(a,b)){
				//cout<<a<<" "<<b<<endl;
				cnt++;
				tot++;
				merge(a,b);
				ans.push_back({{a,b},c});
			}
			if(cnt>=k) break;
		}
		if(cnt<k){
			cout<<"no solution"<<endl;
			return 0;
		}
		
	}
	for(int i=0;i<(int)beton.size();i++){
		int a=beton[i].fi.fi;
		int b=beton[i].fi.se;
		int c=beton[i].se;
		if(!connect(a,b)){
			merge(a,b);
			ans.push_back({{a,b},c});
			tot++;
		}
	}
	// if(tot!=n-1){
	// 	cout<<"no solution"<<endl;
	// 	return 0;
	// }
	for(int i=0;i<(int)ans.size();i++){
		cout<<ans[i].fi.fi<<" "<<ans[i].fi.se<<" "<<ans[i].se<<endl;
	}

	return 0;
}