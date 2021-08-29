#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
 
int t,n,d,m[110],ans;
char s[110],c;
bool p[110];
 
bool cek(int x){
	memset(p,false,sizeof(p));
	int pos=0,a;
	int maks=-1;
	for(int i=1;i<=n+1;i++){
		if(s[i]=='B'){
			if(m[i]-pos>x){
				i--;
				if(pos==m[i]){
					return false;
				}
				else{
					pos=m[i];
					if(s[i]=='S'){
						p[i]=true;
					}
				}
			}
			else{
				pos=m[i];
				continue;
			}
		}
		else{
			if(m[i]-pos>x){
				i--;
				if(pos==m[i]){
					return false;
				}
				else{
					pos=m[i];
					if(s[i]=='S'){
						p[i]=true;
					}
				}
			}
			else{
				continue;
			}
		}
	}
	pos=d;
	for(int i=n;i>=0;i--){
		if(p[i]){
			continue;
		}
		else{
			a=pos-m[i];
			pos=m[i];
			maks=max(a,maks);
		}
	}
	if(maks<=x){
		return true;
	}
	else return false;
}
 
void binser(){
	int lo=1,hi=1e9,mid;
	while(lo<=hi){
		mid=(lo+hi)/2;
		if(cek(mid)){
			ans=mid;
			hi=mid-1;
		}
		else{
			lo=mid+1;
		}
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>s[i]>>c>>m[i];
		}
		s[n+1]='B';
		m[n+1]=d;
		m[0]=0;
		binser();
 
		cout<<"Case "<<tc<<": "<<ans<<endl;
	}
 
	return 0;
}