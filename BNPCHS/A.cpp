#include <bits/stdc++.h>
#define se second
#define fi first
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll>pll;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;
typedef vector <pll> vpll;
const int mod=100000000+7;

int tc, temp=1;

int main() {
	cin>>tc;
	while(tc--) {
		int a,b;
		cin>>a>>b;
		b++;
		int temp1=a%b;
		if(temp1==0) cout<<"Kasus #"<<temp<<": ya"<<endl;
		else cout<<"Kasus #"<<temp<<": tidak"<<endl;
		temp++;
	}
	return 0;
}