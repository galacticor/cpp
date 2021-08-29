#include <bits/stdc++.h>
using namespace std;
 
string skecil,sbesar,sangka,str[10010];
char c[100][100],cbesar[100],ckecil[100],cangka[100];
int xb,xk,xa;
 
void ubah(string s){
	skecil="";
	sbesar="";
	sangka="";
	for(int i=0;i<s.length();i++){
		if(('a'<=s[i]) && (s[i]<='z')){
			skecil+=s[i];
		}
		if(('A'<=s[i]) && (s[i]<='Z')){
			sbesar+=s[i];
		}
		if(('0'<=s[i]) && (s[i]<='9')){
			sangka+=s[i];
		}
	} 
}
string s;
int main(){
	cin>>s;
	s = s + "-"; //
	int q=1;
	for(int i=0;i<s.length();i++){
		if(s[i]!='-'){
			str[q]+=s[i];
		}
		else{
			q++;
		}
	}
	for(int i=1;i<q;i++){ //
		ubah(str[i]);
		str[i]="";
		str[i]=sbesar+skecil+sangka;
		cout<<str[i];
		if(i<q-1){ //
			cout<<"-";
		}
		else{
			cout<<endl;
		}
	}
	for(int i=1;i<q;i++){
		//sort(c[i],c[i]+str[i].length()-1,cmp);
		xb=0;
		xk=0;
		xa=0;
		for(int j=0;j<=str[i].length()-1;j++){
			//cout<<c[i][j]<<" ";
			if(('A'<=str[i][j]) && (str[i][j]<='Z')){
				xb++;
				cbesar[xb]=str[i][j];
			}
			if(('a'<=str[i][j]) && (str[i][j]<='z')){
				xk++;
				ckecil[xk]=str[i][j];
			}
			if(('0'<=str[i][j]) && (str[i][j]<='9')){
				xa++;
				cangka[xa]=str[i][j];
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
		if(i<q-1){ //
			cout<<"-";
		}
		else{
			cout<<endl;
		}
	}

	return 0;
}