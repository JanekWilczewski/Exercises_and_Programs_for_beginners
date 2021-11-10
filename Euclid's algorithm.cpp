//Euclid's algorithm

#include <iostream>
using namespace std;

void zamien(int &x, int&y){
 int t=x; x=y; y=t;
}

int main()
{
  int x,y;
  cin >> x;
  cin >> y;
   if(x>y) zamien(x,y);
    while(x!=0){c
      y= y%x;
      if(x>y) zamien(x,y);
    }
    cout << y << endl;

 return 0;
}
