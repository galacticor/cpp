#include <bits/stdc++.h>
using namespace std;
 
int ps,pb,pk,t,ans[1010][1010],p;
string s[20010];
 
void terjemah(string x,int y,int ki,int ka,int at,int bw){
	if(y<ps){
		if(x[y]=='0'){
			terjemah(x,y+1,ki,(ki+ka)/2,at,(at+bw)/2);
		}
		else if(x[y]=='1'){
			terjemah(x,y+1,(ki+ka)/2 + 1,ka,at,(at+bw)/2);
		}
		else if(x[y]=='2'){
			terjemah(x,y+1,ki,(ki+ka)/2,(at+bw)/2+1,bw);
		}
		else if(x[y]=='3'){
			terjemah(x,y+1,(ki+ka)/2+1,ka,(at+bw)/2+1,bw);
		}
	}
	else{
		for(int i=at;i<=bw;i++){
			for(int j=ki;j<=ka;j++){
				ans[i][j]=1;
			}
		}
	}
}
 
int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s[i];
	}
	cin>>pb>>pk;
	p=1;
	while(!((p>=pb) && (p>=pk))){
		p*=2;
	}
	for(int i=1;i<=t;i++){
		ps=s[i].length();
		terjemah(s[i],1,1,p,1,p);
	}
	for(int i=1;i<=pb;i++){
		for(int j=1;j<=pk;j++){
			cout<<ans[i][j];
			if(j<pk){
				cout<<" ";
			}
		}
		cout<<endl;
	}
}