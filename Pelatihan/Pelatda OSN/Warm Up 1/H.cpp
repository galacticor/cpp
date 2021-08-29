#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

struct name
{
	int idx,val;	
}a[1000];

string s[1000];
int sum,n,m,t;

bool cmp(name a,name b){
	return a.val<b.val||(a.val==b.val && a.idx<b.idx);
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>t;
	for(int tc=1;tc<=t;tc++){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>s[i];
			sum=0;
			for(int j=0;j<n;j++){
				for(int k=j+1;k<n;k++){
					if(s[i][j]>s[i][k]) sum++;
				}
			}
			a[i].idx=i;
			a[i].val=sum;
		}
		sort(a+1,a+m+1,cmp);
		for(int i=1;i<=m;i++){
			cout<<s[a[i].idx]<<endl;
		}
		if(tc<t){
			cout<<endl;
		}
	}

	return 0;
}