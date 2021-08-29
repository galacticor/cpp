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

int N, arr[100005], T, ki[100005], ka[100005], prefix[100005];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>T;

	while(T--){
		cin>>N;
		memset(ki,0,sizeof(ki));
		memset(ka,0,sizeof(ka));
		for (int i = 0; i < N; i++){
			cin>>arr[i];
		}
		for (int i = 1; i < N; i++){
			if (arr[i-1] == 1)
				ki[i] = ki[i-1] + 1;
			else
				ki[i] = ki[i-1];
		}
		for (int i = N-1; i >= 0; i--){
			if (arr[i+1] == 1)
				ka[i] = ka[i+1] + 1;
			else
				ka[i] = ka[i+1];
		}
				
		for (int i = 1; i < N; i++){
			ki[i] = ki[i-1] + ki[i];
		}
		for (int i = N-1; i >= 0; i--){
			ka[i] = ka[i+1] + ka[i];
		}
		
		for (int i = 0; i < N; i++){
			cout<<ki[i]+ka[i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}