#include <bits/stdc++.h>
using namespace std;
 
int n,p,q,k,ans,z1,z2,x,a[1010],y;
string s,s1;
bool z,b[1010];


int main(){
	cin>>s1>>x;
	cin>>n>>k>>q;
	p=0;
	if(x==1 || x==3 || x==4){
		for(int i=1;i<=n;i++){
			cout<<"1 "<<i<<endl;
			cin>>s;
			if(s=="bisajadi"){
				p++;
				a[p]=i;
			}
		}
		cout<<p;
		for(int i=1;i<=p;i++){
			cout<<" "<<a[i];
		}
		cout<<endl;
		cin>>s;
		if(s=="ya"){
			return 0;
		}
	}
	else if(x==5){
		int low=1,hi=n,mid;
		ans=0;
		while(low<=hi){
			mid=(low+hi)/2;
			cout<<"1 "<<mid<<endl;
			cin>>s;
			if(s=="bisajadi"){
				ans=mid;					//UNTUK MENCARI NILAI TERBESAR YANG <=X
				low=mid+1;
			}
			else if(s=="ya"){
				return 0;
			}
			else{
				hi=mid-1;
			}
		}
		cout<<ans;
		for(int i=1;i<=ans;i++){
			cout<<" "<<i;
		}
		cout<<endl;
		cin>>s;
		if(s=="ya"){
			return 0;
		}
	}
	else{
		p=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				cout<<"2 "<<i<<" "<<j<<endl;
				cin>>s;
				if(s=="ya"){
					return 0;
				}
				else if(s=="tidak"){
					z2=true;
					b[i]=true;
					b[j]=true;
				}
			}
		}
		if(z2){
			for(int i=1;i<=n;i++){
				if(b[i]){
					p++;
				}
			}
			cout<<n-p;
			for(int i=1;i<=n;i++){
				if(!b[i]){
					cout<<" "<<i;
				}
			}
			cout<<endl;
			cin>>s;
			if(s=="ya"){
				return 0;
			}
		}
		else{
			cout<<n;
			for(int i=1;i<=n;i++){
				cout<<" "<<i;
				
			}
			cout<<endl;
			cin>>s;
			if(s=="ya"){
				return 0;
			}
			else{
				for(int i=1;i<=n;i++){
					cout<<n-1;
					for(int j=1;j<=n;j++){
						if(j!=i){
							cout<<" "<<j;
						}
					}
					cout<<endl;
					cin>>s;
					if(s=="ya"){
						return 0;
					}
				}
			}	
		}
	}
	return 0;
}