#include <iostream>
using namespace std;

string s,a,b,c,d,e,f,g,h,res;
int n;
bool p;

int main(){
	a="vaporeon";b="jolteon";c="flareon";d="espeon";e="umbreon";f="leafeon";g="glaceon";h="sylveon";
	cin>>n;
	cin>>s;
	p=true;
	if(n==6){
		cout<<d<<endl;
	}
	else if(n==8){
		cout<<a<<endl;
	}
	else{
		if(s[0]=='j'){
			cout<<b;
			p=false;
		}if(s[0]=='f'){
			cout<<c;
			p=false;
		}if(s[0]=='u'){
			cout<<e;
			p=false;
		}if(s[0]=='l'){
			cout<<f;
			p=false;
		}if(s[0]=='g'){
			cout<<g;
			p=false;
		}if(s[0]=='s'){
			cout<<h;
			p=false;
		}
		if(p){
			if(s[1]=='o'){
			cout<<"jolteon";
			p=false;
			}if(s[1]=='m'){
				cout<<"umbreon";
				p=false;
			}if(s[1]=='e'){
				cout<<"leafeon";
				p=false;
			}if(s[1]=='y'){
				cout<<"sylveon";
				p=false;
			}if(s[1]=='l'){
				if(s[3]=='r'){
					cout<<"flareon";
				}
				if(s[3]=='c'){
					cout<<"glaceon";
				}
				p=false;
			}
			if(p){
				if(s[2]=='l'){
					if(s[3]=='t'){
						cout<<b;
					}
					if(s[3]=='v'){
						cout<<h;
					}
					p=false;
				}if(s[2]=='a'){
					if(s[3]=='r'){
						cout<<c;
					}
					if(s[3]=='f'){
						cout<<f;
					}
					if(s[3]=='c'){
						cout<<g;
					}
					p=false;
				}if(s[2]=='b'){
					cout<<"umbreon";
					p=false;
				}
				if(p){
					if(s[3]=='t'){
						cout<<b;
					}if(s[3]=='f'){
						cout<<f;
					}if(s[3]=='c'){
						cout<<g;
					}if(s[3]=='v'){
						cout<<h;
					}
				}
			}
		}
	}
	cout<<endl;
	return 0;
}
