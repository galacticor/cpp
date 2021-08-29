#include <bits/stdc++.h>
using namespace std;

int t,n,a[200010],ap[200010],ora[200010],suma,sumo;
string s;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		s="NO";
		for(int j=1;j<=2*n-1;j++){
				cin>>ap[j]>>ora[j];
			}
			for(int j=1;j<=2*n-1;j++){
				suma=suma+ap[j];
				sumo=sumo+ora[j];
			}
			if(suma%2==0 && sumo%2==0){
				for(int j=1;j<=2*n-1;j++){
					if(ap[j]>=suma/2 && ora[j]>=sumo/2){
						a[j]++;
					}
				}
			}
			else if(suma%2==0 && suma%2!=0){
				for(int j=1;j<=2*n-1;j++){
					if(ap[j]>=suma/2 && ora[j]>=sumo/2+1){
						a[j]++;
					}
				}
			}
			else if(sumo%2==0 && sumo%2!=0){
				for(int j=1;j<=2*n-1;j++){
					if(ap[j]>=suma/2+1 && ora[j]>=sumo/2){
						a[j]++;
					}
				}
			}
			else{
				for(int j=1;j<=2*n-1;j++){
					if(ap[j]>=suma/2+1 && ora[j]>=sumo/2+1){
						a[j]++;
					}
				}
			}
			for(int j=1;j<=2*n-1;j++){
				if(a[j]>0){
					s="YES";
				}
			}
			if(s=="YES"){
				cout<<"YES"<<endl;
				for(int j=1;j<=2*n-1;j++){
					if(a[j]>0){
						cout<<j<<" ";
					}
				}
				cout<<endl;
			}
			else{
				cout<<"NO"<<endl;
			}
	}
	return 0;
}