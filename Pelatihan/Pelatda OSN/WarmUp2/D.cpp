#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

struct name
{
	int ki,ka;
}a[10005];

bool cmp(name a,name b){
	return a.ki<b.ki;
}

int l,g,ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin>>l>>g && l && g){
		bool p=false;
		ans=0;
		memset(a,0,sizeof(a));
		for(int i=0;i<g;i++){
			int x,y;
			cin>>x>>y;
			a[i].ki=x-y;
			a[i].ka=x+y;
		}
		int batas=0,maks;
		int i=0;
		sort(a,a+g,cmp);
		while(batas<l && i<g){
			maks=batas;
			while(a[i].ki<=batas && i<g){
				if(a[i].ka>maks){
					maks=a[i].ka;
				}
				i++;
			}
			if(maks==batas){
				p=true;
				break;
			}
			ans++;
			batas=maks;
		}
		if(batas<l) cout<<"-1"<<endl;
		else cout<<g-ans<<endl;
	}

	return 0;
}