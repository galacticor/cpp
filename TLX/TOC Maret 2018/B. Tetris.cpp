#include <bits/stdc++.h>
using namespace std;

int a,b,n,y,k,z;
string s;

int main(){
	cin>>n>>a>>b;
	int x;
	y=a/2;
	z=b/2;
	if((a+b)<2*n || a>2*n || b>2*n || (y+z)<n || (a+b)>3*n){
		cout<<"TIDAK MUNGKIN"<<endl;
	}
	else{
		if(a<b){
			for(int i=1;i<=b;i++){
				s=s+"R";
			}
			for(int i=1;i<=a;i++){
				s=s+"S";
			}
			if((a+b)>2*n){
				if(b%2==0){
					x=a+b-2*n;
					k=0;
					while(x>0 && k<s.length()){
						s.insert(k,"S");
						k=k+3;
						x--;
					}
				}
				else{
					x=a+b-2*n-1;
					k=0;
					while(x>0 && k<s.length()){
						s.insert(k,"S");
						k=k+3;
						x--;
					}
				}
			}
		}
		else{
			for(int i=1;i<=a;i++){
				s=s+"S";
			}
			for(int i=1;i<=b;i++){
				s=s+"R";
			}
			if((a+b)>2*n){
				if(a%2==0){
					x=a+b-2*n;
					k=0;
					while(x>0 && k<s.length()){
						s.insert(k,"R");
						k=k+3;
						x--;
					}
				}
				else{
					x=a+b-2*n-1;
					k=0;
					while(x>0 && k<s.length()){
						s.insert(k,"R");
						k=k+3;
						x--;
					}
				}
			}
		}
	}
	for(int i=0;i<=a+b-1;i++){
		cout<<s[i];
	}
	cout<<endl;
	return 0;

}