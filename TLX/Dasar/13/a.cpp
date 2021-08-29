#include <iostream>
#include <algorithm>
using namespace std;

int n,x,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
string s,s1[1010],s2[1010],s3[1010],s4[1010],s5[1010],s6[1010],s7[1010],s8[1010],s9[1010],s10[1010];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		x=s.length();
		if(x==1){
			x1++;
			s1[x1]=s;
		}
		if(x==2){
			x2++;
			s2[x2]=s;
		}
		if(x==3){
			x3++;
			s3[x3]=s;
		}
		if(x==4){
			x4++;
			s4[x4]=s;
		}
		if(x==5){
			x5++;
			s5[x5]=s;
		}
		if(x==6){
			x6++;
			s6[x6]=s;
		}
		if(x==7){
			x7++;
			s7[x7]=s;
		}
		if(x==8){
			x8++;
			s8[x8]=s;
		}
		if(x==9){
			x9++;
			s9[x9]=s;
		}
		if(x==10){
			x10++;
			s10[x10]=s;
		}
	}
	sort(s1+1,s1+x1+1);
	sort(s2+1,s2+x2+1);
	sort(s3+1,s3+x3+1);
	sort(s4+1,s4+x4+1);
	sort(s5+1,s5+x5+1);
	sort(s6+1,s6+x6+1);
	sort(s7+1,s7+x7+1);
	sort(s8+1,s8+x8+1);
	sort(s9+1,s9+x9+1);
	sort(s10+1,s10+x10+1);
	
	for(int i=1;i<=x1;i++){
		cout<<s1[i]<<endl;
	}
	for(int i=1;i<=x2;i++){
		cout<<s2[i]<<endl;
	}
	for(int i=1;i<=x3;i++){
		cout<<s3[i]<<endl;
	}
	for(int i=1;i<=x4;i++){
		cout<<s4[i]<<endl;
	}
	for(int i=1;i<=x5;i++){
		cout<<s5[i]<<endl;
	}
	for(int i=1;i<=x6;i++){
		cout<<s6[i]<<endl;
	}
	for(int i=1;i<=x7;i++){
		cout<<s7[i]<<endl;
	}
	for(int i=1;i<=x8;i++){
		cout<<s8[i]<<endl;
	}
	for(int i=1;i<=x9;i++){
		cout<<s9[i]<<endl;
	}
	for(int i=1;i<=x10;i++){
		cout<<s10[i]<<endl;
	}
	return 0;
}
