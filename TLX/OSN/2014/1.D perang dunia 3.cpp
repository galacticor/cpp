#include <bits/stdc++.h>
using namespace std;

long long n,musuh[1000010],ans,awal,power,total,xmax;
string s;
int main(){
	cin>>s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>musuh[i];
		if(musuh[i]>xmax){
			xmax=musuh[i];
		}
	}
	if((s=="0..56") || (s=="0..6")){
		ans=1000000000;
		for(int awal=2000001;awal>=xmax;awal-=2){
			total =0;
			for(int i=1;i<=n;i++){
				power=awal;
				while(power>musuh[i]){
					power/=2;
				}
				power*=2;
				total+=(power-musuh[i]);
			}
			ans=min(ans,total);
		}
	}
	else{
		ans=1000000000;
		for(int awal=1;awal<=xmax+1;awal+=2){
			total =0;
			for(int i=1;i<=n;i++){
				power=awal;
				while(power<musuh[i]){
					power*=2;
				}
				total+=(power-musuh[i]);
			}
			ans=min(ans,total);
		}
	}
	
	cout<<ans<<endl;
	return 0;
}