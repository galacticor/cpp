#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

int t,n,k;
char a[100005];
string s;

void solvekecil(){
	int temp=n;
	stack<char> st;
	for(int i=0;i<s.length();i++){
		while(!st.empty() && temp>0 && s[i]<st.top()){
			st.pop();
			temp--;
		}
		st.push(s[i]);
	}
	temp=n;
	int k=0;
	while(!st.empty()){
		k++;
		a[k]=st.top();
		st.pop();
	}
	for(int i=k;i>k-s.length()+n;i--){
		cout<<a[i];
	}
	cout<<endl;
}

void solvegede(){
	int temp=n;
	stack<char> st;
	for(int i=0;i<s.length();i++){
		while(!st.empty() && temp>0 && s[i]>st.top()){
			st.pop();
			temp--;
		}
		st.push(s[i]);
	}
	int k=0;
	while(!st.empty()){
		k++;
		a[k]=st.top();
		st.pop();
	}
	for(int i=k;i>k-s.length()+n;i--){
		cout<<a[i];
	}
	cout<<endl;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s>>n;
		solvekecil();
		solvegede();
	}

	return 0;
}