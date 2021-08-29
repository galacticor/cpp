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

void tanya(int x,int y){
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
}

void back(int xi,int yi,int xj,int yj){
	if(udah)return;
	if(0<xj && 0<yj){
		if(m.find({xj,yj})==m.end()){
			//cout<<"wawa"<<endl;
			tanya(xj-xi,yj-yi);
			if(s=="UNSAFE"){
				m[{xj,yj}]=1;
				return;
			}
			else{
				pergi(xj-xi,yj-yi);
				if(s=="YES"){
					udah=true;
					return;
				}
				else{
					back(xj,yj,xj+1,yj);
					back(xj,yj,xj,yj+1);
					back(xj,yj,xj-1,yj);
					back(xj,yj,xj,yj-1);
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//if(!udah)cout<<"haha"<<endl;
	back(1,1,1,2);
	back(1,1,2,1);
	

	return 0;
}