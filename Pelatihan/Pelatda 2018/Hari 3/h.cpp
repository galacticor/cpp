#include <bits/stdc++.h>
using namespace std;

struct name
{
	int x;
	int y;
	int z;
	int idx;
}box;

bool cmp(name a,name b){
	return a.x>b.x || (a.x==b.x && a.y<b.z) || (a.x==b.x && a.y==b.y && a.z<b.z); 
}

bool pl(name a,name b){
	return a.x==a.x
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>temp[1]>>temp[2]>>temp[3];
		sort(temp+1,temp+3);
		box[i].x=temp[1];
		box[i].y=temp[2];
		box[i].z=temp[3];
	}
	sort(box+1,box+n+1,cmp);
	ans=box[n].x/2;

	ans=(x[n]+x[n-1])/2;
	cout<<ans<<endl;

	return 0;
}
