#include <iostream>
#include <iomanip>
using namespace std;

float a,b,c,d,e,f;
float x;

int main(){
	cin>>a>>b>>c>>d>>e>>f;
	x=(a+b+c+d+e+f) / 6;
	cout<<fixed<<setprecision(4);
	cout<<(a+b+c+d+e+f) / 6<<endl;
	return 0;
}
