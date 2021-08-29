#include<bits/stdc++.h>
using namespace std;

string str;
double ans;
double k[1010],s[1010];
int N;

double to_radian(double a){
	return (a/10 * acos(-1)) / 180;
}

void rec(int n,double sud,double kec){
	if(n==N){
		if(sud<1800){
			ans=max(ans,fabs(2*kec*kec*9.8*sin(to_radian(sud))*cos(to_radian(sud))));
		}
	}
	else{
		rec(n+1,sud+s[n],max(kec,k[n]));//ambil
 		rec(n+1,sud,kec);//tidak
	}
}

int main() {
	cin>>str;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>k[i]>>s[i];
	}
	rec(0,0.0,0.0);
	cout<<fixed;
	cout<<setprecision(12);
	cout<<ans<<endl;
	return 0;
}