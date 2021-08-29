#include <iostream>
using namespace std;

int n,x,x25,x50,x100;

int main(){
	cin>>n;
	string s="YES";
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x==25){
			x25++;
		}
		else if(x==50){
			if(x25>0){
				x25--;
				x50++;
			}
			else{
				s="NO";
			}
		}
		else if(x==100){
			if(x25!=0 && x50!=0){
				x25--;
				x50--;
				x100++;
			}
			else if(x50<1){
				if(x25>=3){
					x25-=3;
					x100++;
				}
				else{
					s="NO";
				}
			}
			else{
				s="NO";
			}
		}
	}
	cout<<s<<endl;
	return 0;
}
