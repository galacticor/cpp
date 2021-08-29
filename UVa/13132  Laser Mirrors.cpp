#include <bits/stdc++.h>
using namespace std;

int x,t;

int phi(int n)
{
    int result = n;
    for (int p=2; p*p<=n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0){
                n /= p;
            }
            result -= result / p;
        }
    }
    if (n > 1){
        result -= result / n;
    }
    return result;
}
 

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>x;
		cout<<phi(x)<<endl;
	}
	
	return 0;

}