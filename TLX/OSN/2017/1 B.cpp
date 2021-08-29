#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

ll k;
int n,ans,t,tmp1;
short int mem[77][3000][77],id[100];
string s,p,b;

int f(int x,int y,int z){
	if(y<0 || z<0){
		return -3e4;
	}
	else if(x<0){
		if(z==0) return 0;
		else return -3e4;
	}
	else if(z==0){
		return 0;
	}
	
	if(mem[x][y][z]!=-1){
		return mem[x][y][z];
	}
	else{
		int tmp=int(p[x]-'0')+f(x-1,y-abs(x-id[z]),z-1);;
		mem[x][y][z]=max(f(x-1,y,z),tmp);
		return mem[x][y][z];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>s;
	cin>>n>>k;
	cin>>p>>b;
	memset(mem,-1,sizeof(mem));
	
	if(k>n*(n-1) /2) k=n*(n-1)/2;
	t=0;
	for(int i=0;i<n;i++){
		if(b[i]=='1'){
			t++;
			id[t]=i;
		
		}
	}
	id[0]=-1;
	cout<<f(n-1,k,t)<<endl;
	return 0;
}