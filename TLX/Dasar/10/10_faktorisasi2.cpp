#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
 int bil, I, J;
 cout << "input bilangan = ";
 cin >> bil;
 for (I=2; I<=bil; I++)
 {
  if (bil%I==0)
  {
   if (I==2)
   {
    cout << I << "  ";
   }
   else
   {
    for (J=2; J<=I-1; J++)
    {
     if (I%J==0)
     {
      goto selesai;
     }
    }
    cout << I << "  ";
   }
   selesai;
  }
 }
}
