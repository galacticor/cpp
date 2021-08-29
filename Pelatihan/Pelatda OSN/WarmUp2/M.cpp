#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

ll a,b,c,d,e,m[10];
bool p;

void f(int x,ll y){
	if(x==5 && y==23){
		p=true;
		return;
	}
	else if(x<5){
		x++;
		f(x,y*m[x-1]);
		f(x,y+m[x-1]);
		f(x,y-m[x-1]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin>>a>>b>>c>>d>>e && a!=0 && b!=0 && c!=0 && d!=0 && e!=0){
		p=false;
		m[0]=a;
		m[1]=b;
		m[2]=c;
		m[3]=d;
		m[4]=e;
		sort(m,m+5);
		do{
			f(1,m[0]);
			//cout<<m[0]<<" "<<m[1]<<" "<<m[2]<<" "<<m[3]<<" "<<m[4]<<endl;
		}while(next_permutation(m,m+5));
		if(p) {
			cout<<"Possible"<<endl;
		}
		else cout<<"Impossible"<<endl;
	}

	return 0;
}