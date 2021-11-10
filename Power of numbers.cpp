//Algorithm that calculates a power of numbers

#include <iostream>
using namespace std;

int main()
{
  char x;
  do{
     int a,b,i,w;
     cout << "Enter the number: ";
     cin >> a;
     cout << "Enter the  power: ";
     cin >> b;
     i=0;
     w =1;
       while(i<b){
       w = w*a;
       i += 1;
       }cout << "Score is: " << w << endl;

    cout << "One more? y/n: ";
    cin >> x;
  }while (x!='n');
return 0;
}
