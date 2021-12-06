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

int n;
string str;
vector<int> v;

int main()
{
    cin >> n;
    cin.ignore();
    getline(cin, str);

    int pre=-1;
    for (int i=0; i<str.size(); i++)
    {
        if (str[i]-' '==0 || str[i]-'-'==0 || i==str.size()-1)
        {
            v.push_back(i-pre);
            pre=i;
        }
    }

    int low=0, high=str.size();
    while (low!=high)
    {
        int mid=(low+high)/2;
        int width=0, lines=1;
        bool possible=true;
        for (auto &i: v)
        {
            if (i>mid)
            {
                possible=false;
                break;
            }
            if (width+i>mid)
            {
                lines++;
                width=i;
            }
            else
            {
                width+=i;
            }
        }

        if (lines<=n && possible)
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }
    cout << low << endl;

    return 0;
}

/*
4
garage for sa-le
*/