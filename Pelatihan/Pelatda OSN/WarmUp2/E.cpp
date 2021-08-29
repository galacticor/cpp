#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

struct name
{
	int idx,jml;
}team[110];

std::vector<int> v[110];

int meja[110],m,n;

bool cmp(name a,name b){
	return a.jml>b.jml;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(cin>>m>>n && m!=0 && n!=0){
		memset(meja,0,sizeof(meja));
		for(int i=0;i<110;i++){
			v[i].clear();
		}
		memset(team,0,sizeof(team));
		bool p=false;
		for(int i=1;i<=m;i++){
			cin>>team[i].jml;
			team[i].idx=i;
		}
		sort(team+1,team+m+1,cmp);
		for(int i=1;i<=n;i++){
			cin>>meja[i];
		}
		for(int i=1;i<=m;i++){
			int a=team[i].jml;
			int b=team[i].idx;
			int j=1;
			while(a>0 && j<=n){
				if(meja[j]>0){
					a--;
					meja[j]--;
					v[b].push_back(j);
				}
				j++;
			}
			if(a>0){
				cout<<"0"<<endl;
				p=true;
				break;
			}
		}
		if(p){
			continue;
		}
		cout<<"1"<<endl;
		for(int i=1;i<=m;i++){
			for(int j=0;j<v[i].size();j++){
				cout<<v[i][j];
				if(j<v[i].size()-1) cout<<" ";
			}
			cout<<endl;
		}
	}


	return 0;
}