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
ll a,b;

int main() {
	scanf("%d", &tc);
	while(tc--) {
		cin>>a>>b;
		if(b<=0) {
			if(a<0) printf("Kasus #%d: Negatif\n", temp);
			else printf("Kasus #%d: Nol\n", temp);
		}
		else {
			ll temp1=a*-1;
			if(temp1==b) printf("Kasus #%d: Nol\n", temp);
			else if(temp1<b) printf("Kasus #%d: Positif\n", temp);
			else if(temp1>b) printf("Kasus #%d: Negatif\n", temp);
		}
		temp++;
	}
	return 0;
}