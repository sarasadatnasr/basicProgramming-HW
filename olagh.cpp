#include <iostream>
using namespace std;

int main()
{
        int t, a, b, olagh = 0, gav = 0;

        cin >> t >> a >> b;

        while(true)
        {
            if(t > 0)
            {
                t -= 1;
                t -= a;
                olagh++;
            }

            else
            {
                break;
            }

            if(t > 0)
            {
                t -= 1;
                t -= b;
                gav++;
            }

            else
            {
                break;
            }
        }

        cout << olagh << " " << gav << endl;
}
