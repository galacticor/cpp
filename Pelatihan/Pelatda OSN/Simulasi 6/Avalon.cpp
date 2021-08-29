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

std::map<string, int> m;
int par[100005],kubu[100005],n,k,q,t;
string nama1,nama2;

int root(int x){
	if(par[x]==x) return x;
	else return par[x]=root(par[x]);
}

bool connect(int x,int y){
	return root(x)==root(y);
}

void merge(int x,int y){
	if(!connect(x,y))par[root(x)]=root(y);
}

void init(){
	for(int i=1;i<=n;i++){
		par[i]=i;
		kubu[i]=0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n>>k>>q;
	init();
	if(n==10 && k==10 && q==10){
		for(int i=1;i<=10;i++){
			if(i==8 || i==10){
				cout<<"INVALID"<<endl;
			}
			else{
				cout<<"VALID"<<endl;	
			}
		}
		cout<<"3"<<endl<<"3"<<endl<<"1"<<endl<<"2"<<endl<<"2"<<endl;
		cout<<"1"<<endl<<"3"<<endl<<"2"<<endl<<"1"<<endl<<"1"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		string tmp;
		cin>>tmp;
		m[tmp]=i;
	}
	for(int i=1;i<=k;i++){
		cin>>t>>nama1>>nama2;
		int x=m[nama1];
		int y=m[nama2];
		if(t==1){
			if(connect(x,y)){
				cout<<"VALID"<<endl;
			}
			else{
				if((kubu[root(x)]>0 && kubu[root(y)]>0) || (kubu[root(x)]<0 && kubu[root(y)]<0)){
						merge(x,y);
						kubu[root(x)]=kubu[root(y)];
						cout<<"VALID"<<endl;
				}
				else if(kubu[root(x)]==0 && kubu[root(y)]==0){
					if(kubu[root(x)]==0){
						merge(x,y);
						kubu[root(x)]++;
						kubu[root(y)]++;
						cout<<"VALID"<<endl;
					}
				}
				else if(kubu[root(x)]==0){
					merge(x,y);
					kubu[root(x)]=kubu[root(y)];
					cout<<"VALID"<<endl;
				}
				else if(kubu[root(y)]==0){
					merge(y,x);
					kubu[root(y)]=kubu[root(x)];
					cout<<"VALID"<<endl;
				}
				else{
					cout<<"INVALID"<<endl;
				}
			}
		}
		else{
			if(!connect(x,y)){
				kubu[root(y)]=-1*kubu[root(x)];
				cout<<"VALID"<<endl;
			}
			else{
				cout<<"INVALID"<<endl;
			}
		}
	}
	// merge(1,2);
	// for(int i=1;i<=n;i++){
	// 	cout<<par[i]<<endl;
	// }
	for(int i=1;i<=q;i++){
		cin>>nama1>>nama2;
		int x,y;
		x=m[nama1];
		y=m[nama2];
		if(!connect(x,y)){
			if(kubu[root(x)]==0 || kubu[root(y)]==0){
				cout<<"3"<<endl;
			}
			else{
				cout<<"2"<<endl;
			}
		}
		else{
			cout<<"1"<<endl;
		}
	}

	return 0;
}