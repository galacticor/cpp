#include <bits/stdc++.h>
using namespace std;

int a,b,ans,l,r,c,sq[505][505],ans1;

void binser1(int x,int y){
	int low=1,hi=b,mid;
	while (low<=hi){
		mid=(low+hi)/2;
		if(sq[x][mid]>=y){
			ans1=mid;
			hi=mid-1;
		}
		else{
			low=mid+1;
		}
	}
}

bool cek(int x){
	for(int i=1;i<=a-x+1;i++){
		ans1=0;
		binser1(i,l);
		if(sq[i][ans1]>=l && sq[i+x-1][ans1+x-1]<=r && i+x-1<=a && ans1+x-1<=b){
			return true;
		}
	}
	return false;
}

void binser(){
	int low=1,hi=500,mid;
	while(low<=hi){
		mid=(low+hi)/2;
		if(cek(mid)){
			ans=mid;
			low=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
	if(cek(ans)==false){
		ans=0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin>>a>>b && a!=0 && b!=0){
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				cin>>sq[i][j];
			}
		}
		cin>>c;
		for(int i=1;i<=c;i++){
			ans=0;
			cin>>l>>r;
			binser();
			cout<<ans<<endl;
			
		}
		cout<<"-"<<endl;

	}

	return 0;
}