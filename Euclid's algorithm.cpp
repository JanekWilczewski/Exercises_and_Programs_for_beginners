//Euclid's algorithm

#include <iostream>
using namespace std;

void change(int &x, int&y){
 int t=x; x=y; y=t;
}

int main()
{
  int x,y;
  cout << "Enter the first number: ";
  cin >> x;
  cout << "Enter the second number: ";
  cin >> y;
   if(x>y) change(x,y);
    while(x!=0){
      y= y%x;
      if(x>y) change(x,y);
    }
    cout << y << endl;

 return 0;
}
