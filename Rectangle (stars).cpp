// Algorithm that creates a rectangle from stars

#include <iostream>
using namespace std;

int main()
{
    int n,m,i,j;
    cout << "Enter the width of the rectangle: ";
    cin >> n;
    cout << "Enter the length of the rectangle: ";
    cin >> m;

    for(i=0; i<m; i+=1)
    {
      for(j=0; j<n; j+=1)
        {
            cout <<"*";
        }
        cout <<endl;
    }

return 0;
}
