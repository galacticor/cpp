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


// function [L,U]=lu(A)
//   %Input matrix A
//   %output matrices L & U
//   [n,n]=size(A);
//   L=eye(n); % an identity matrix of order nxn
//   for k=1:n-1
//     L(k+1:n,k)=A(k+1:n,k)/A(k,k); %assumed A(k,k)!=0
//     for i=k+1:n
//       A(i,k:n)=A(i,k:n)-L(i,k)*A(k,k:n);
//     end
//   end
//   U=triu(A);



void binser(int x ){
	int low=1,hi=n,mid;
	while (low<=hi){
		mid=(low+hi)/2;
		if(a[mid]>x){					//UNTUK MENCARI NILAI TERKECIL YANG >X
			ans=mid;
			hi=mid-1;
		}
		else{
			low=mid+1;
		}
	}
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int t, c, h, o;
    cin >> t;
    while(t--){
        cin >> c >> h >> o;

    }


    
}
