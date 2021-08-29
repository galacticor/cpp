#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;

string s;

int main(){
	cin>>s;
	int i=1;
	if(isupper(s[0])){
		s[0]=tolower(s[0]);
	}
		while(i<s.length()){
			if(isupper(s[i])){
				s[i]=tolower(s[i]);
				s.insert(i,"_");
			}
			else {
				if(s[i]=='_'){
					s.erase(i,1);
					s[i]=toupper(s[i]);
				}
			}
			i++;
		}
	cout<<s<<endl;
	return 0;
}
