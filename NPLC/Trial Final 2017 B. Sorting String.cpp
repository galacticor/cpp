#include <bits/stdc++.h>
using namespace std;
 
string skecil,sbesar,sangka,str[10010],sans;
char c[100][100],cbesar[100],ckecil[100],cangka[100];
int xb,xk,xa;
bool p;

void ubah(string s){
	skecil="";
	sbesar="";
	sangka="";
	for(int i=0;i<s.length();i++){
		if('a'<=s[i] && s[i]<='z'){
			skecil+=s[i];
		}
		if('A'<=s[i] && s[i]<='Z'){
			sbesar+=s[i];
		}
		if('0'<=s[i] && s[i]<='9'){
			sangka+=s[i];
		}
	}
 
}
string s;
int main(){
	cin>>s;
	int q=1;
	for(int i=0;i<s.length();i++){
		if(s[i]!='-'){
		
			str[q]+=s[i];
		}
		else{
			p=true;
			q++;
		}
	}
	for(int i=1;i<=q;i++){
		ubah(str[i]);
		str[i]="";
		str[i]=sbesar+skecil+sangka;
		cout<<str[i];
		if(i<q){
			cout<<"-";
		}
		else{
			cout<<endl;
		}
		for(int j=0;j<=str[i].length()-1;j++){
			c[i][j]=str[i][j];
			//cout<<c[i][j];

		}
	}
	for(int i=1;i<=q;i++){
		//sort(c[i],c[i]+str[i].length()-1,cmp);
		xb=0;
		xk=0;
		xa=0;
		for(int j=0;j<=str[i].length()-1;j++){
			if('A'<=c[i][j] && c[i][j]<='Z'){
				xb++;
				cbesar[xb]=c[i][j];
				
			}
			if('a'<=c[i][j] && c[i][j]<='z'){
				xk++;
				ckecil[xk]=c[i][j];
			}
			if('0'<=c[i][j] && c[i][j]<='9'){
				xa++;
				cangka[xa]=c[i][j];
			}
		}
		//cout<<xb<<xk<<xa<<" ";
		sort(cbesar+1,cbesar+xb+1);
		sort(ckecil+1,ckecil+xk+1);
		sort(cangka+1,cangka+xa+1);
		for(int j=1;j<=xb;j++){
			cout<<cbesar[j];
		}
		for(int j=1;j<=xk;j++){
			cout<<ckecil[j];
		}
		for(int j=1;j<=xa;j++){
			cout<<cangka[j];
		}
		if(i<q){
			cout<<"-";
		}
		else{
			cout<<endl;
		}
	}
	if(p){
		for(int i=1;i<=q;i++){
			sans+=str[i];
			
		}
		xa=0;
		xb=0;
		xk=0;
		for(int j=0;j<=sans.length()-1;j++){
			if('A'<=sans[j] && sans[j]<='Z'){
				xb++;
				cbesar[xb]=sans[j];
				}
			if('a'<=sans[j] && sans[j]<='z'){
				xk++;
				ckecil[xk]=sans[j];
				}
			if('0'<=sans[j] && sans[j]<='9'){
				xa++;
				cangka[xa]=sans[j];
				}
			}
			sort(cbesar+1,cbesar+xb+1);
			sort(ckecil+1,ckecil+xk+1);
			sort(cangka+1,cangka+xa+1);
			for(int j=1;j<=xb;j++){
				cout<<cbesar[j];
			}
			for(int j=1;j<=xk;j++){
				cout<<ckecil[j];
			}
			for(int j=1;j<=xa;j++){
				cout<<cangka[j];
			}
			cout<<endl;
	}
	
	return 0;
}