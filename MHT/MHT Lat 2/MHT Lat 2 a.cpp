#include <iostream>
#include <iomanip>
using namespace std;

double y;
int x;

int main(){
	cin>>x>>y;
	if((0<x<=2000)&&(0<=y<=2000)){
		if((x%5!=0)or(x>=y)){
			cout<<fixed<<setprecision(2);
			cout<<y<<endl;
		}
		else{
			y=y-x-0.50;
			cout<<fixed<<setprecision(2);
			cout<<y<<endl;
		}
		return 0;
	}
}
