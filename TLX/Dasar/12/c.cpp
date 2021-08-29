#include <iostream>
using namespace std;

int n,m,mid,ans;
string a[100010],s,b[100010];

void binser(string x){
	int low=1,hi=n;
	while(low<=hi){
		mid=(low+hi)/2;
		if(a[mid]==x){
			ans=mid;
			break;
		}											//UNTUK MENCARI LETAK NILAI ==X
		else if(x<a[mid]){
			hi=mid-1;
		}
		else if(x>a[mid]){
			low=mid+1;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>s;
		ans=-1;
		binser(s);
		if(ans<1){
			cout<<"NIHIL"<<endl;
		}
		else{
			cout<<b[ans]<<endl;
		}
		
	}
}
