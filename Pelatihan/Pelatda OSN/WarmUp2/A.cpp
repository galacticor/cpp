#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;

ld a[50][50],h,ans,total;
int n,m;

ld cek(ld x){
	ld sum=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(x>a[i][j]){
				sum+=(x-a[i][j]);
				total++;
			}
		}
	}
	return sum;
}

void binser(){
	ld lo=9e-18,hi=9e19,mid,temp;
	while(fabs(lo-hi)>1e-10){
		total=0.0;
		mid=(lo+hi)/2.0;
		if(cek(mid)>h/100.0){
			hi=mid;
		}
		else{
			lo=mid;
		}
	}
	ans=lo;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=0;
	while(cin>>m>>n && m!=0 && n!=0){
		t++;
		total=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		cin>>h;
		binser();
		cout<<fixed<<setprecision(2);
		cout<<"Region "<<t<<endl;
		cout<<"Water level is "<<ans<<" meters."<<endl;
		cout<<(100*total)/(m*n)<<" percent of the region is under water."<<endl;
	}

	return 0;
}