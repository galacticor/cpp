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

int maks[100],mins[100],xmax,xmin,t,n;
string s;

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
			}
			else{
				maks[k]=b;
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
			}
			else{
				maks[k]=b;
			}
		}
		maks[k+1]=maks[x];
		for(int i=k+2;i<=x;i++){
			maks[i]=0;
		}
		xmax=k+1;
	}
}

void minimal(int x){
	int a,b,k=0;
	if(x%2==0){
		for(int i=1;i<=x;i+=2){
			a=mins[i];
			b=mins[i+1];
			tes(a,b);
			k++;
			if(s=="<"){
				mins[k]=a;
			}
			else{
				mins[k]=b;
			}
		}
		for(int i=k+1;i<=x;i++){
			mins[i]=0;
		}
		xmin=k;
	}
	else{
		for(int i=2;i<=x;i+=2){
			a=mins[i-1];
			b=mins[i];
			tes(a,b);
			k++;
			if(s=="<"){
				mins[k]=a;
			}
			else{
				mins[k]=b;
			}
		}
		mins[k+1]=mins[x];
		for(int i=k+2;i<=x;i++){
			mins[i]=0;
		}
		xmin=k+1;
	}
}

int main(){
	cin>>t;
	for(int co=1;co<=t;co++){
		cin>>n;
		if(n%2==0){
			int k=0;
			for(int i=1;i<=n;i+=2){
				tes(i,i+1);
				k++;
				if(s==">"){
					maks[k]=i;
					mins[k]=i+1;
				}
				else{
					maks[k]=i+1;
					mins[k]=i;
				}
			}
			xmax=k;
			xmin=k;
			while(xmax>1){
				maksimal(xmax);
			}
			while(xmin>1){
				minimal(xmin);
			}
		}
		else{
			int k=0;
			for(int i=2;i<=n;i+=2){
				tes(i-1,i);
				k++;
				if(s==">"){
					maks[k]=i-1;
					mins[k]=i;
				}
				else{
					maks[k]=i;
					mins[k]=i-1;
				}
			}
			maks[k+1]=n;
			mins[k+1]=n;
			xmax=k+1;
			xmin=k+1;
			while(xmax>1){
				maksimal(xmax);
			}
			while(xmin>1){
				minimal(xmin);
			}
		}
		cout<<"! "<<mins[1]<<" "<<maks[1]<<endl;
	}
	return 0;
}