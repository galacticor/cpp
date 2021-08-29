#include <iostream>
using namespace std;

int n,m,x,y,temp;
int a[100010],b[100010];
char p,q;

void swap1(int g,int h){
	int temp;
	temp=g;
	g=h;
	h=temp;
	a[y]=g;
	b[x]=h;
}

void swap(int g,int h){
	int temp;
	temp=g;
	g=h;
	h=temp;
	a[x]=g;
	b[y]=h;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>p>>x>>q>>y;
		if((p=='A')&&(q=='B')){
			swap(a[x],b[y]);
		}
		else if((p=='B')&&(q=='A')){
			swap1(a[y],b[x]);
		}
		else if((p=='A')&&(q=='A')){
			temp=a[x];
			a[x]=a[y];
			a[y]=temp;
		}
		else{
			temp=b[x];
			b[x]=b[y];
			b[y]=temp;
		}
	}
	for(int i=1;i<n;i++){
		cout<<a[i]<<' ';
	}
	cout<<a[n]<<endl;
	for(int i=1;i<n;i++){
		cout<<b[i]<<' ';
	}
	cout<<b[n]<<endl;
	return 0;
}
