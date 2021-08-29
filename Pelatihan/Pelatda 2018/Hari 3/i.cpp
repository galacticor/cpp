#include <bits/stdc++.h>
using namespace std;

int k,n,x[100010],temp;

struct nama
{
	int tugas;
	int briefing;
}a[100010];

bool cmp(nama a,nama b){
	return a.tugas<b.tugas || (a.tugas==b.tugas && a.briefing<b.briefing);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin>>n && n!=0){
		k++;
		temp=0;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			cin>>a[i].briefing>>a[i].tugas;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1;i<=n;i++){
			temp+=a[i].briefing;
			x[i]=temp+a[i].tugas;
		}
		sort(x+1,x+1+n);
		cout<<"Case "<<k<<": ";
		cout<<x[n]<<endl;
		
	}

	return 0;
}