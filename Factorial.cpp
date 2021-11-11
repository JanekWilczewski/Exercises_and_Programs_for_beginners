//Factorial

#include <iostream>
using namespace std;

int main()
{
// s - score
    int i,s,n;
     i=1;
     s=1;
    cout << "Enter the number: ";
    cin >> n;
     if (n==0){
        cout << s;
     }else{
      while(i<n){
        i+=1;
        s=s*i;
      } cout << n << " factorial is " << s;
     }
return 0;
}
