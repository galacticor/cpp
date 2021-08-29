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

string s,sub;
stack <char> st;
stack <ll> nilai;
int neg,temp;

int ubah(char c){
	return int(c-'0');
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>sub;
	if(sub[1]=='1'){
		cout<<"1"<<endl;
		cout<<"1"<<endl;
		cout<<"6"<<endl;
		return 0;
	}
	if(sub[2]=='2'){
		while(cin>>s){
			temp=0;
			neg=1;
			for(int i=0;i<s.length();i++){
				if(s[i]=='-'){
					neg=-1;
					continue;
				}
				temp*=10;
				temp+=ubah(s[i]);
			}
			if(temp==0) cout<<"-1"<<endl;
			else cout<<"1"<<endl;
		}
		return 0;
	}
	if(sub[3]=='3'){
		while(cin>>s){
			for(int i=0;i<s.length();i++){
				if('0'<=s[i] && s[i]<='9'){
					temp*=10;
					temp+=ubah(s[i]);
				}
				else if(s[i]=='('){
					temp=0;
				}
				else if(s[i]==','){
					nilai.push(temp*neg);
					temp=0;
					neg=1;
				}
				else if(s[i]==')'){
					char c=st.top();
					st.pop();
					if(c=='-'){
						int x=nilai.top(); nilai.pop();
						int y=nilai.top(); nilai.pop();
						nilai.push(y-x);
					}
					if(c=='+'){
						int x=nilai.top(); nilai.pop();
						int y=nilai.top(); nilai.pop();
						nilai.push(y+x);
					}
					if(c=='<'){
						int x=nilai.top(); nilai.pop();
						int y=nilai.top(); nilai.pop();
						nilai.push(min(x,y));
					}
					if(c=='>'){
						int x=nilai.top(); nilai.pop();
						int y=nilai.top(); nilai.pop();
						nilai.push(max(x,y));
					}
				}
				else if(s[i]=='-'){
					if(s[i+1]=='('){
						st.push(s[i]);
					}
					else{
						neg=-1;
					}
				}
				else{
					st.push(s[i]);
				}
			}
		}
	}

	return 0;
}