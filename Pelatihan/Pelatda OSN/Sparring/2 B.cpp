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

//std::map<ll, value> map;
int n,k,val[205],pangkat,tot[5];
ll sum,a[1500],fact[205],invfac[205];

void rec(int x,ll sum){
	//cout<<x<<" "<<sum<<endl;
	if(sum>k-1){
		return;
	}
	if(x>n){
		a[sum]++;
		a[sum]%=MOD;
		return;
	}
	rec(x+1,sum);
	rec(x+1,sum*val[x]);
}

ll dnc(int x,int y){
	int temp;
	if(y==0) return 1;
	if(y%2==1)temp=x;
	else temp=1;

	ll t=dnc(x,y/2)%MOD;
	return ((t*t)%MOD * temp)%MOD;
}

bool cek(int x){
	//pangkat=0;
	int temp=1;
	while(temp<x){
		pangkat++;
		temp*=2;
	}
	return temp==x;
}

void init(int x){
	fact[0]=1;
	invfac[0]=1;
	for(int i=1;i<=x;i++){
		fact[i]=(fact[i-1]*i)%MOD;
		invfac[i]=dnc(fact[i],MOD-2)%MOD;
	}
}

ll combin(int x,int y){
	return (((fact[x]*invfac[y])%MOD * invfac[x-y])%MOD);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string sub;
	cin>>sub;
	cin>>n>>k;
	for(int i=0;i<=n;i++){
		cin>>val[i];
		if(sub[4]=='4'){
			tot[val[i]]++;
		}
	}
	//if(cek(8))cout<<"haha"<<endl;
	//cout<<val[3]<<endl;
	if(sub[4]=='4'){
		init(n+1);
		for(int i=0;i<k;i++){
			if(i==0){
				cout<<(dnc(2,n)-1+MOD)%MOD<<endl;
			}
			else if(i==1){
				cout<<(dnc(2,tot[1])-1+MOD)%MOD<<endl;
			}
			else{
				pangkat=0;
				if(cek(i)){
					cout<<(combin(tot[2],pangkat)*dnc(2,tot[1]))%MOD<<endl;
				}
				else{
					cout<<"0"<<endl;
				}
			}
		}
	}
	else{
		rec(1,val[0]);
		for(int i=0;i<k;i++){
			cout<<a[i]<<endl;
		}
	}


	return 0;
}