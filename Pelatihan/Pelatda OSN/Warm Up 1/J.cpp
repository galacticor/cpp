#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

std::priority_queue<int> pq;
int n,a,k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		pq.push(-1*a);
	}
	int k=1;
	while(!pq.empty()){
		if(-1*pq.top()>=k){
			pq.pop();
		}
		k++;
	}
	cout<<k<<endl;
	return 0;
}