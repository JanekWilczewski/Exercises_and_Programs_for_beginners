// Algorithm that calculates whether a given year is leap year or not

#include <iostream>
using namespace std;

int main()
{
  char x;
  do{

     int year;
      cout << "Enter the year: ";
      cin >> year;
     if ((year%4==0 && year%100==0) || (year%400==0)){
         cout << "Leap year";
     }else{
     cout << "No leap year" << endl;}

   cout << endl << "Close? (y/n): ";
   cin >> x;
  } while (x!='y');
}



