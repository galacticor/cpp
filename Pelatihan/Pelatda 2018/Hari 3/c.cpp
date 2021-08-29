#include <bits/stdc++.h>
using namespace std;

struct product
{
	char c;
	int frek;	
}a[50];

int t;
string s;

bool cmp(product a,product b){
	return a.frek>b.frek;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>t;
	for(int i=1;i<=t;i++){
		getline(cin,s);
		for(int j=0;j<s.length();j++){
			if(s[j]=='A' || s[j]=='a'){
				a[1].frek++;
				a[1].c='A';
			}
			if(s[j]=='B' || s[j]=='b'){
				a[2].frek++;
				a[2].c='B';
			}if(s[j]=='C' || s[j]=='c'){
				a[3].frek++;
				a[3].c='C';
			}if(s[j]=='D' || s[j]=='d'){
				a[4].frek++;
				a[4].c='D';
			}if(s[j]=='E' || s[j]=='e'){
				a[5].frek++;
				a[5].c='E';
			}if(s[j]=='F' || s[j]=='f'){
				a[6].frek++;
				a[6].c='F';
			}if(s[j]=='G' || s[j]=='g'){
				a[7].frek++;
				a[7].c='G';
			}if(s[j]=='H' || s[j]=='h'){
				a[8].frek++;
				a[8].c='H';
			}if(s[j]=='I' || s[j]=='i'){
				a[9].frek++;
				a[9].c='I';
			}if(s[j]=='J' || s[j]=='j'){
				a[10].frek++;
				a[10].c='J';
			}if(s[j]=='K' || s[j]=='k'){
				a[11].frek++;
				a[11].c='K';
			}if(s[j]=='L' || s[j]=='l'){
				a[12].frek++;
				a[12].c='L';
			}if(s[j]=='M' || s[j]=='m'){
				a[13].frek++;
				a[13].c='M';
			}if(s[j]=='N' || s[j]=='n'){
				a[14].frek++;
				a[14].c='N';
			}if(s[j]=='O' || s[j]=='o'){
				a[15].frek++;
				a[15].c='O';
			}if(s[j]=='P' || s[j]=='p'){
				a[16].frek++;
				a[16].c='P';
			}if(s[j]=='Q' || s[j]=='q'){
				a[17].frek++;
				a[17].c='Q';
			}if(s[j]=='R' || s[j]=='r'){
				a[18].frek++;
				a[18].c='R';
			}if(s[j]=='S' || s[j]=='s'){
				a[19].frek++;
				a[19].c='S';
			}if(s[j]=='T' || s[j]=='t'){
				a[20].frek++;
				a[20].c='T';
			}if(s[j]=='U' || s[j]=='u'){
				a[21].frek++;
				a[21].c='U';
			}if(s[j]=='V' || s[j]=='v'){
				a[22].frek++;
				a[22].c='V';
			}if(s[j]=='W' || s[j]=='w'){
				a[23].frek++;
				a[23].c='W';
			}if(s[j]=='X' || s[j]=='x'){
				a[24].frek++;
				a[24].c='X';
			}if(s[j]=='Y' || s[j]=='y'){
				a[25].frek++;
				a[25].c='Y';
			}if(s[j]=='Z' || s[j]=='z'){
				a[26].frek++;
				a[26].c='Z';
			}
		}
	}
	sort(a+1,a+27,cmp);
	for(int i=1;i<=26;i++){
		if(a[i].frek>0){
			cout<<a[i].c<<" "<<a[i].frek<<endl;
		}
	}

	return 0;
}