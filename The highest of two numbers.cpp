#include <iostream>
using namespace std;

int main()
{
    int b;
    int a;
     cout << "Enter first number: ";
     cin >> a;
     cout << "Enter second number: ";
     cin >> b;
      if (a>b){
        cout << a << " - is higher!" << endl;
     }else if (a==b){
         cout << "The same numbers" << endl;
        }else{
            cout << b << " - is higher!" << endl;
        }

    return 0;
}
