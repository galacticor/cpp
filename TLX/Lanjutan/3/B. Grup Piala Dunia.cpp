#include <bits/stdc++.h>
using namespace std;

int t,n,input[100],score[100];
bool valid;

void rec(int x,int y){
	bool sama=true;
	int next_x,next_y;
	if(x==n){
		for(int i=1;i<=n;i++){
			if(score[i]!=input[i]){
				sama=false;
			}
		}
		if(sama){
			valid=true;
		}
	}
	else{
		if(y==n){
			next_x=x+1;
			next_y=x+2;
		}
		else{
			next_x=x;
			next_y=y+1;
		}
		score[x]+=3;
		rec(next_x,next_y);
		score[x]-=3;

		score[x]++;
		score[y]++;
		rec(next_x,next_y);
		score[x]--;
		score[y]--;

		score[y]+=3;
		rec(next_x,next_y);
		score[y]-=3;
	}	
}

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		valid=false;
		for(int j=1;j<=n;j++){
			cin>>input[j];
		}
		rec(1,2);
		if(valid){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}

	return 0;
}