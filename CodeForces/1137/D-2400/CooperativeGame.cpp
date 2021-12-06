#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
#include <string>
#include <string.h>
#include <iomanip>
#include <functional>
using namespace std;

#define f first
#define s second
#define ll long long

int main()
{
    int move=1;
    bool met=false;
    while (!met)
    {
        if (move==1)
        {
            cout << "next 1" << endl;
        }
        else
        {
            cout << "next 0 1" << endl;
        }

        int n;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            string str;
            cin >> str;
            if (str=="01" && move==2)
            {
                met=true;
            }
        }
        move^=3;
    }

    while (1)
    {
        cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
        
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            string str;
            cin >> str;
        }
        if (n==1)
        {
            break;
        }
    }

    cout << "done" << endl;

    return 0;
}