#include <bits/stdc++.h>
using namespace std;

struct product
{
	int bed;
	int kap;
	int room;
	int price;
	int indx;
	string name;
} hotel[100];

int t,m,n,x,peop,req,res,temp1,temp2;
bool p;
char typ;

bool cmp(product a,product b){
	return a.price<b.price || ((a.price==b.price)&&(a.bed>b.bed)) || ((a.price==b.price)&&(a.bed==b.bed)&&(a.indx<b.indx));
}

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m;
		for(int j=1;j<=n;j++){
			cin>>hotel[j].bed>>hotel[j].kap>>hotel[j].room>>hotel[j].price>>hotel[j].name;
			hotel[j].indx=j;
		}
		sort(hotel+1,hotel+n+1,cmp);
		cout<<"Case #"<<i<<":"<<endl;
		for(int j=1;j<=m;j++){
			cin>>typ>>peop>>req;
			p=false;
			if(peop%req==0){
				x=peop/req;
			}
			else{
				x=peop/req+1;
			}
			if(typ=='A'){
				int k=1;
				while(k<=n && !p){
					if(hotel[k].bed>=20 && hotel[k].bed<=35){
						if(hotel[k].kap>=req && hotel[k].kap*hotel[k].room>=peop && hotel[k].room>=x){
							res=hotel[k].price*x;
							cout<<res<<" "<<hotel[k].name<<endl;
							p=true;
						}
					} 
					k++;
				}
			}
			if(typ=='B'){
				int k=1;
				while(k<=n && !p){
					if(hotel[k].bed>=36 && hotel[k].bed<=48){
						if(hotel[k].kap>=req && hotel[k].kap*hotel[k].room>=peop && hotel[k].room>=x){
							res=hotel[k].price*x;
							cout<<res<<" "<<hotel[k].name<<endl;
							p=true;
						}
					}
					k++; 
				}
			}
			if(typ=='C'){
				int k=1;
				while(k<=n && !p){
					if(hotel[k].bed>=49 && hotel[k].bed<=62){
						if(hotel[k].kap>=req && hotel[k].kap*hotel[k].room>=peop && hotel[k].room>=x){
							res=hotel[k].price*x;
							cout<<res<<" "<<hotel[k].name<<endl;
							p=true;
						}
					} 
					k++;
				}
			}
			if(!p){
				cout<<"no-hotel"<<endl;
			}
		}
	}
	return 0;
}