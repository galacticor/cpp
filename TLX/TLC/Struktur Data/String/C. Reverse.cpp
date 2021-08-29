#include <bits/stdc++.h>
using namespace std;

string s,temps;
int x;

int main(){
	getline(cin, s);
	temps=s;
	x=s.length()-1;
	for(int i=0;i<s.length();i++){
		temps[i]=s[x-i];
	}
	cout<<temps<<endl;
	return 0;
}