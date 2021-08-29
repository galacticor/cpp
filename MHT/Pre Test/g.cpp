#include <iostream>
using namespace std;

int i,k,l,m,n,d,a[1000010],res;

int main(){
	cin>>k>>l>>m>>n>>d;
	i=1;
	while(i<=d){
		if(i%k==0){
			a[i]++;
		}
		if(i%l==0){
			a[i]++;
		}
		if(i%m==0){
			a[i]++;
		}
		if(i%n==0){
			a[i]++;
		}
		if(a[i]==0){
			res++;
		}
		i++;
	}
	cout<<d-res<<endl;
	return 0;
}
