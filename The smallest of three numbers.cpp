// Algorithm that calculates the smallest of three numbers

#include <iostream>
using namespace std;

int main()
{
  float a,b,c;
  cout << "Enter the first number: ";
  cin >> a;
  cout << "Enter the first number: ";
  cin >> b;
  cout << "Enter the first number: ";
  cin >> c;

  if(a<b){
    if(a<c){
        cout << a << " is lowest";
    }else{
      cout << c << " is lowest";
    }
  }else if(b<c){
    cout << b << " is lowest";
   }


return 0;
}

