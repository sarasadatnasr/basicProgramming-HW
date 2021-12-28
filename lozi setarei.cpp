#include <iostream>

using namespace std;

int main()
{
    int n;
    
    cin >> n;
    int space = n - 1;
    for (int i = 0; i < n; i++)
    {

        if(i%2 == 0) {
            for (int j = 0;j < space/2; j++)
                cout << " ";
            for (int j = 0; j <= i; j++)
                cout << "*";
            for (int j = 0;j <space; j++)
                cout << " ";
            for (int j = 0; j <= i; j++)
                cout << "*";
            cout << endl;
            cout << endl;
        }
        space--;
    }
    space = 1;
    for (int i = n-1; i > 0; i--)
    {
        if(i%2 != 0) {
            for (int j = 0; j < space/2; j++)
                cout << " ";
            for (int j = 0;j < i;j++)
                cout << "*";

            for (int j = 0;j <space; j++)
                cout << " ";
            for (int j = 0; j <= i-1; j++)
                cout << "*";

            cout << endl;
            cout << endl;
        }
        space++;
    }
    return 0;
}


