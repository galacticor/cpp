#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;

int ans,a[200010];
string s1,s2,temps;

bool cek(int x){
	int j=0;
	for(int i=1;i<=x;i++){
		temps[a[i]-1]='A';
	}
	for(int i=0;i<=temps.length()-1;i++){
		if(j<s2.length()){
			if(s2[j]==temps[i]){
				j++;
			}	
		}
	}
	temps=s1;
	if(j<s2.length()){
		return false;
	}
	else{
		return true;
	}
}

void binser(){
	int low=1,hi=s1.length(),mid;
	while(low<=hi){
		mid=(low+hi)/2;
		if(!cek(mid)){
			ans=mid;
			hi=mid-1;
		}
		else{
			low=mid+1;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>s1>>s2;
	temps=s1;
	for(int i=1;i<=s1.length();i++){
		cin>>a[i];
	}
	binser();
	cout<<ans-1<<endl;
	
	return 0;
}