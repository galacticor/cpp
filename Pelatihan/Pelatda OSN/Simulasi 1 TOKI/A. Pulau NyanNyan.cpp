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

int pulau[5][5]; 

char ubah(int x){
	int temp=x%4;
	if(temp=0){
		return 's';
	}
	if(temp=1){
		return 'p';
	}
	if(temp=0){
		return 'g';
	}
	if(temp=0){
		return 'd';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>s;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int i=1;i<=3;i++){
			for(int j=1;j<=3;j++){
				cin>>pulau[i][j];
			}
		}

	}
	

	return 0;
}