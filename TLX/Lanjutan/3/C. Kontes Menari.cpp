#include <bits/stdc++.h>
using namespace std;

string s;
long long n,r,y,ju,a[100010],nilai[5000010],in,ans,jur,ta;
bool used[100010];

struct apa
{
	int d;
	char t;
}tari[100010];

void binser(int x){
	int low=1,hi=in,mid;
	while(low<=hi){
		mid=(low+hi)/2;
		if(nilai[mid]<=x){
			ans=mid;					
			low=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}

void tes(){
	ta=0;
	char p,q;
	long long sum=0;
	int k=0;
	for(int i=1;i<=r;i++){
		k=tari[a[i]].d;
		p=tari[a[i-1]].t;
		q=tari[a[i]].t;
			if(p=='P'){
				k=k*2;
			}
			if(p=='L'){
				k=k/2;
			}
			k=k+ta;
			if(q=='Y'){
				ta=y;
			}
		sum+=k;	
	}
	in++;
	nilai[in]=sum;
}

void permutasi(int deep){
	if(deep>r){
		tes();
	}
	else{
		for(int i=1;i<=n;i++){
			if(!used[i]){
				used[i]=true;
				a[deep]=i;
				permutasi(deep+1);
				used[i]=false;
			}
		}
	}
}

int main(){
	getline(cin, s);
	cin>>n>>r>>y>>ju;
	for(int i=1;i<=n;i++){
		cin>>tari[i].d>>tari[i].t;
	}
	permutasi(1);
	sort(nilai+1,nilai+1+in);
	for(int i=1;i<=ju;i++){
		ans=0;
		cin>>jur;
		binser(jur);
		cout<<in-ans<<endl;
		
	}
	return 0;
}