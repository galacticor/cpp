#include <bits/stdc++.h>
using namespace std;

int a[300][300],r,c,kiri,kanan,atas,bawah,p,sum;
string kode,s[20010];

void quad(int kiri, int kanan, int atas, int bawah, string kode){
	int one=0;
	for(int i=atas;i<=bawah;i++){
		for(int j=kiri;j<=kanan;j++){
			if(a[i][j]==1){
				one++;
			}
		}
	}
	if(one==(kanan-kiri+1)*(bawah-atas+1)){
		sum++;
		s[sum]="1"+kode;
	}
	else if(one==0){
		
	}
	else{
		quad(kiri,(kiri+kanan)/2,atas,(atas+bawah)/2,kode+"0");
		quad((kiri+kanan)/2+1,kanan,atas,(atas+bawah)/2,kode+"1");
		quad(kiri,(kiri+kanan)/2,(atas+bawah)/2+1,bawah,kode+"2");
		quad((kiri+kanan)/2+1,kanan,(atas+bawah)/2+1,bawah,kode+"3");
	}
}

int main(){
	cin>>r>>c;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>a[i][j];
		}
	}
	p=1;
	while(!((p>=r) && (p>=c))){
		p*=2;
	}
	quad(1,p,1,p,"");
	cout<<sum<<endl;
	for(int i=1;i<=sum;i++){
		cout<<s[i]<<endl;
	}
}