#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int,int> vii;

int c,h,o,ans,temp;
string s;
stack <int> st;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>s;
	temp=0;
	st.push(0);
	for(int i=0;i<s.length();i++){
		if(s[i]==')'){
			temp=st.top(); st.pop();
			if('1'<=s[i+1] && s[i+1]<='9'){
				st.top()+=temp*(int)(s[i+1]-'0');
			}
			else st.top()+=temp;
		}
		else if(s[i]=='('){
			st.push(0);
		}
		else if(s[i]=='C'){
			if('1'<=s[i+1] && s[i+1]<='9'){
				st.top()+=12*(int)(s[i+1]-'0');
			}
			else st.top()+=12;
		}
		else if(s[i]=='H'){
			if('1'<=s[i+1] && s[i+1]<='9'){
				st.top()+=1*(int)(s[i+1]-'0');
			}
			else st.top()++;
		}
		else if(s[i]=='O'){
			if('1'<=s[i+1] && s[i+1]<='9'){
				st.top()+=(16*(int)(s[i+1]-'0'));
			}
			else st.top()+=16;
		}
		else{
			continue;
		}
	}
	cout<<st.top()<<endl;
	return 0;
}