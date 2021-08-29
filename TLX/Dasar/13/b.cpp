#include <iostream>
using namespace std;

int j,n;
string s[100010],temp;

int main(){
	cin>>n;
	for(int i=0;i<=n-1;i++){
		cin>>s[i];
		j=i;
		if(j==0){
			cout<<"1"<<endl;
		}
		else{
			while(j>0 && s[j]<s[j-1] ){
				temp=s[j];
				s[j]=s[j-1];
				s[j-1]=temp;
				j--;
			}
			cout<<j+1<<endl;
		}
	}
	return 0;
}
