#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int n=a+b+c;
        if (a+b+c>=9 && n%9==0 && a>=(n/9) && b>=(n/9) && c>=(n/9))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
