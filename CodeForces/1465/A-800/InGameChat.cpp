#include <iostream>
#include <string>
using namespace std;

int t;
int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int n, count=0;
        string s;
        cin >> n >> s;
        for (int j=n-1; j>=0; j--)
        {
            if (s.substr(j,1)==")")
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count>n-count)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
