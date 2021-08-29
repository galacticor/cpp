#include <bits/stdc++.h>
using namespace std;

int n,a[200],sum[200],sum1,ans,k,res[1000];
bool p, visited[200];

int gcd(int x,int y){
	if(y==0) return x;
	else return gcd(y, x%y);
}

int lcm(int x,int y){
	return x/gcd(x,y) * y;
}

void dfs(int x){
	if(!visited[x]){
		visited[x]=true;
		sum1++;
		dfs(a[x]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(sum[i]>1){
			p=true;
		}
	}
	if(p){
		cout<<"-1"<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			sum1=0;
			if(!visited[i]){
				dfs(i);
				k++;
				if(sum1%2==0){
					res[k]=sum1/2;
				}
				else res[k]=sum1;
			}
		}
		ans=1;
		for(int i=1;i<=k;i++){
			ans=lcm(ans,res[i]);
		}
		cout<<ans<<endl;
	}


	return 0;
}