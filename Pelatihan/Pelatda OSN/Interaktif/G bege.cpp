#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<int> vi;
//const int MOD=1000000007;

std::map<pii, bool> m;
string s;
bool udah=false;
int arah;
//pii last;
si dx[4]={0,1,0,-1};
si dy[4]={1,0,-1,0};

void pergi(int x,int y){
	cout<<"GO";
	if(x==-1){
		cout<<" UP"<<endl;
	}
	else if(x==1){
		cout<<" DOWN"<<endl;
	}
	else if(y==1){
		cout<<" RIGHT"<<endl;
	}
	else{
		cout<<" LEFT"<<endl;
	}
	cin>>s;
}

bool tanya(int x,int y){
	cout<<"LOOK";
	if(x==-1){
		cout<<" UP"<<endl;
	}
	else if(x==1){
		cout<<" DOWN"<<endl;
	}
	else if(y==1){
		cout<<" RIGHT"<<endl;
	}
	else{
		cout<<" LEFT"<<endl;
	}
	cin>>s;
	if(s=="UNSAFE")return true;
	else return false;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//if(!udah)cout<<"haha"<<endl;
	while(!udah){
		//arah++;
		arah%=4;
		if(tanya(dx[arah],dy[arah])){
			arah++;
			continue;
		}
		else{
			pergi(dx[arah],dy[arah]);
			if(s=="YES"){
				udah=true;
				return 0;
			}
			else{
				arah+=3;
				arah%=4;
			}
		}
	}

	return 0;
}