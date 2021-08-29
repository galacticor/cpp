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

int maks[1005],mins[1005],xmax,t,n,ansmaks;
string s;
vi v[1005];

void tes(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	cin>>s;
}

void maksimal(int x){
	int a,b,k=0;
	if(x%2==0){
		for(int i=1;i<=x;i+=2){
			a=maks[i];
			b=maks[i+1];
			tes(a,b);
			k++;
			if(s==">"){
				maks[k]=a;
				v[a].push_back(b);
			}
			else{
				maks[k]=b;
				v[b].push_back(a);
			}
		}
		for(int i=k+1;i<=x;i++){
			maks[i]=0;
		}
		xmax=k;
	}
	else{
		for(int i=2;i<=x;i+=2){
			a=maks[i-1];
			b=maks[i];
			tes(a,b);
			k++;
			if(s==">"){
				maks[k]=a;
				v[a].push_back(b);
			}
			else{
				maks[k]=b;
				v[b].push_back(a);
			}
		}
		maks[k+1]=maks[x];
		for(int i=k+2;i<=x;i++){
			maks[i]=0;
		}
		xmax=k+1;
	}
}

int main(){
		cin>>n;
		if(n%2==0){
			int k=0;
			for(int i=1;i<=n;i+=2){
				tes(i,i+1);
				k++;
				if(s==">"){
					maks[k]=i;
					v[i].push_back(i+1);
				}
				else{
					maks[k]=i+1;
					v[i+1].push_back(i);
				}
			}
			xmax=k;
			while(xmax>1){
				maksimal(xmax);
			}
		}
		else{
			int k=0;
			for(int i=2;i<n;i+=2){
				tes(i-1,i);
				k++;
				if(s==">"){
					maks[k]=i-1;
					v[i-1].push_back(i);
				}
				else{
					maks[k]=i;
					v[i].push_back(i-1);
				}
			}
			maks[k+1]=n;
			xmax=k+1;
			while(xmax>1){
				maksimal(xmax);
			}
		}
		ansmaks=maks[1];
		for(int i=0;i<v[ansmaks].size();i++){
			maks[i+1]=v[ansmaks][i];
			//cout<<maks[i+1]<<endl;
		}
		xmax=(int)v[ansmaks].size();
		//cout<<xmax<<endl;
		while(xmax>1){
			maksimal(xmax);
		}
		cout<<"! "<<maks[1]<<endl;
	return 0;
}