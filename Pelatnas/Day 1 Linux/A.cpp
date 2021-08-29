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

string kasus;
ll r1, r2;
int c1, c2;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("masuk.txt","r",stdin);

    cin>>kasus >> kasus;
    cin>>r1>>c1>>r2>>c2;

    int cnt = 0;
    for (int i = c2; i > c1; i--){
        if ((r2>>(60-i))%4 == 1) cnt++;
    }
    cnt+=(r2>>(60-c1))%2;

    ll x = r1 >> (60-c2);
    ll y = r2 >> (60-c2);

    ll ans = (y+1)/2 - x/2 + cnt - ((r2 >> (60-c2))&1);
    cout << ans << endl;

    return 0;
}