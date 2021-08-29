#include <bits/stdc++.h>
using namespace std;

struct product
{
	int bed;
	int kap;
	int room;
	int price;
	string name;
} hotel[100];

int t,m,n,x,peop,req,res,temp1,temp2;
bool p;
char typ;

bool cmp(product a,product b){
	return a.price<b.price || ((a.price==b.price)&&(a.bed>b.bed));
}

int main(){
	cin>>t;
	for(int i=1;i<=n;i++){
		cin>>n>>m;
		for(int j=1;j<=n;j++){
			cin>>hotel[j].bed>>hotel[j].kap>>hotel[j].room>>hotel[j].price>>hotel[j].name;
		}
		sort(hotel+1,hotel+n+1,cmp);
		cout<<"Case #"<<i<<":"<<endl;
		for(int j=1;j<=m;j++){
			cin>>typ>>peop>>req;
			if(peop%req==0){
				x=peop/req;
			}
			else{
				x=peop/req+1;
			}
			if(typ=='A'){
				for(int k=1;k<=n;k++){
					if(20<=hotel[k].bed && hotel[k].bed<=35){
						if(hotel[k].kap>=req && hotel[k].kap*hotel[k].room>=peop && hotel[k].kap>=x){
							res=hotel[k].price*x;
							cout<<res<<" "<<hotel[k].name<<endl;
							p=true;
						}
					} 
				}
			}
			if(typ=='B'){
				for(int k=1;k<=n;k++){
					if(36<=hotel[k].bed && hotel[k].bed<=48){
						if(hotel[k].kap>=req && hotel[k].kap*hotel[k].room>=peop && hotel[k].kap>=x){
							res=hotel[k].price*x;
							cout<<res<<" "<<hotel[k].name<<endl;
							p=true;
						}
					} 
				}
			}
			if(typ=='C'){
				for(int k=1;k<=n;k++){
					if(49<=hotel[k].bed && hotel[k].bed<=62){
						if(hotel[k].kap>=req && hotel[k].kap*hotel[k].room>=peop && hotel[k].kap>=x){
							res=hotel[k].price*x;
							cout<<res<<" "<<hotel[k].name<<endl;
							p=true;
						}
					} 
				}
			}
			if(!p){
				cout<<"no-hotel"<<endl;
			}
		}
	}
	return 0;
}