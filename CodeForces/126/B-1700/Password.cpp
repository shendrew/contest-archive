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
using namespace std;

#define f first
#define s second
#define ll long long
string str, ans="";

int main()
{
    cin >> str;
    int n=str.size();
    for (int i=n-2; i>=1; i--)
    {
        if (str.substr(0, i)==str.substr(n-i, i))
        {
            if (str.substr(1, n-2).find(str.substr(0, i))!=string::npos)
            {
                ans=str.substr(0, i);
                break;
            }
        }
    }

    if (ans=="")
    {
        cout << "Just a legend" << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}

/*
fixprefixsuffix
*/