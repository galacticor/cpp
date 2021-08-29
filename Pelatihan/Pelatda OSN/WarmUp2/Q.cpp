#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;

double db[100005],ans;
int a[100005],n,m,t;

bool cek(double x){
	int j=0;
	for(int i=1;i<=m;i++){
		if(i==1){
			j++;
			db[j]=a[i]+x;
		}
		else{
			if(a[i]-x>db[j]){
				j++;
				db[j]=a[i]+x;
			}
		}
	}
	if(j>n){
		return false;
	}
	else return true;

}

void binser(){
	double lo=0,hi=1e7,mid;
	while(fabs(lo-hi)>1e-9){
		mid=(lo+hi)/2.0;
		if(cek(mid)){
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

	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>m;
		ans=-1;
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+m);
		binser();
		cout<<fixed<<setprecision(1);
		cout<<ans<<endl;
	}

	return 0;
}