//Algorithm that calculates a quadratic function

#include <iostream>
#include <math.h>
using namespace std;

double a,b,c,x1,x2,x0;
main()
{
    float a,b,c,delta,x0,x1,x2,x;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

     delta = (b*b)-4*a*c;
     x1=(-b-sqrt(delta))/(2*a);
     x2=(-b+sqrt(delta))/(2*a);
     x0 = -b/(2*a);

     if (a==0){
        if (b==0){
            if (c ==0){
              cout << "Infinite number of solutions";
            }else{
             cout << "Without solution";}
        }else{
         x = -c/b;
         cout << "x = " << x;};
     }else if(delta == 0){
         cout << "x = " << x0;
        }else if (delta > 0){
         cout << "x = " << x1 << endl;
         cout << "x = " << x2;
         }else{
          cout << "Without solution";}

    return 0;
}

