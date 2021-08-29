#include <iostream>
#include <algorithm>
using namespace std;

void binser(int x ){
	int low=1,hi=n,mid;
	while (low<=hi){
		mid=(low+hi)/2;
		if(a[mid]>x){					//UNTUK MENCARI NILAI TERKECIL YANG >X
			ans=mid;
			hi=mid-1;
		}
		else{
			low=mid+1;
		}
	}
}

void binser1(int x){
	int low=1,hi=n,mid;
	while(low<=hi){
		mid=(low+hi)/2;
		if(a[mid]<=x){
			ans=mid;					//UNTUK MENCARI NILAI TERBESAR YANG <=X
			low=mid+1;
		}
		else{
			hi=mid-1;
		}
	}
}


void binsermurni(int x){
	int low=1,hi=n,mid;
	while(low<=hi){
		mid=(low+hi)/2;
		if(a[mid]==x){
			ans=mid;
			break;
		}											//UNTUK MENCARI LETAK NILAI ==X
		else if(x<a[mid]){
			hi=mid-1;
		}
		else if(x>a[mid]){
			low=mid+1;
		}
	}
}
