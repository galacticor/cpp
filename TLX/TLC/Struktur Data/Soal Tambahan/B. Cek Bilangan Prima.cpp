#include <bits/stdc++.h>
using namespace std;

int x;
bool p;

int main(){
	while(cin>>x){
		p=false;
		if(x<=1){
			p=true;
		}
		else{
			for(int i=2;i*i<=x;i++){
				if(x%i==0){
					p=true;
				}
			}
		}
		if(p){
			cout<<"TIDAK"<<endl;
		}
		else{
			cout<<"YA"<<endl;
		}
	}
}