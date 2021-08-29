#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

priority_queue<int> ki;
priority_queue<int,vector<int>,greater<int>> ka;
double median;
int n,a;

void find_median(int x){
	if(ki.size()>ka.size()){
		if(x<median){
			ka.push(ki.top());
			ki.pop();
			ki.push(x);
		}
		else{
			ka.push(x);
		}
		median=(ka.top()+ki.top())/2.0;
	}
	else if(ki.size()<ka.size()){
		if(x>median){
			ki.push(ka.top());
			ka.pop();
			ka.push(x);
		}
		else{
			ki.push(x);
		}
		median=(ka.top()+ki.top())/2.0;
	}
	else if(ka.size()==ki.size()){
		if(x<median){
			ki.push(x);
			median=ki.top()/1.0;
		}
		else{
			ka.push(x);
			median=ka.top()/1.0;
		}
		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>n;
	median=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		find_median(a);
		cout<<setprecision(1)<<fixed<<median<<endl;
	}

	return 0;
}