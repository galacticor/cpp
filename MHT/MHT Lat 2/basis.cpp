#include<iostream>
using namespace std;
 
void basis(int num,int div)
{
    int rem;
 
    if (num <= div-1)
    {
        cout << num;
        return;
    }
    rem = num % div;
    basis(num / div,div);
    cout << rem;
}

int main(){
	int a,b;
	cin>>a>>b;
	basis(a,b);
	cout<<endl;
}
