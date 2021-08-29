#include <iostream>
using namespace std;

char c;
int n,xa,xb,xc,xd,xe,xf,xg,xh,xi,xj,xk,xl,xm,xn,xo,xp,xq,xr,xs,xt,xu,xv,xw,xx,xy,xz;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c=='A' || c=='a'){
			xa++;
		}
		if(c=='B' || c=='b'){
			xb++;
		}
		if(c=='C' || c=='c'){
			xc++;
		}
		if(c=='D' || c=='d'){
			xd++;
		}
		if(c=='E' || c=='e'){
			xe++;
		}
		if(c=='F' || c=='f'){
			xf++;
		}
		if(c=='G' || c=='g'){
			xg++;
		}
		if(c=='H' || c=='h'){
			xh++;
		}
		if(c=='I' || c=='i'){
			xi++;
		}
		if(c=='J' || c=='j'){
			xj++;
		}
		if(c=='K' || c=='k'){
			xk++;
		}
		if(c=='L' || c=='l'){
			xl++;
		}
		if(c=='M' || c=='m'){
			xm++;
		}
		if(c=='N' || c=='n'){
			xn++;
		}
		if(c=='O' || c=='o'){
			xo++;
		}
		if(c=='P' || c=='p'){
			xp++;
		}
		if(c=='Q' || c=='q'){
			xq++;
		}
		if(c=='R' || c=='r'){
			xr++;
		}
		if(c=='S' || c=='s'){
			xs++;
		}
		if(c=='T' || c=='t'){
			xt++;
		}
		if(c=='U' || c=='u'){
			xu++;
		}
		if(c=='V' || c=='v'){
			xv++;
		}
		if(c=='W' || c=='w'){
			xw++;
		}
		if(c=='X' || c=='x'){
			xx++;
		}
		if(c=='Y' || c=='y'){
			xy++;
		}
		if(c=='Z' || c=='z'){
			xz++;
		}
	}
	if(xa!=0 && xb!=0 && xc!=0 && xd!=0 && xe!=0 && xf!=0 && xg!=0 && xh!=0 && xi!=0 && xj!=0 && xk!=0 && xl!=0 && xm!=0 && xn!=0 && xo!=0 && xp!=0 && xq!=0 && xr!=0 && xs!=0 && xt!=0 && xu!=0 && xv!=0 && xw!=0 && xx!=0 && xy!=0 && xz!=0){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
