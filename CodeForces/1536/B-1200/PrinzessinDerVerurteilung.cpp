#include <iostream>
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
int t;
string ss;

string add(int n)
{
    if (n>0)
    {
        string newChar=add((n-1)/26);
        ss+='a'+((n-1)%26);
    }
    return ss;
}

int main()
{
    vector<string> v;
    for (int i=1; i<20000; i++)
    {
        ss="";
        v.push_back(add(i));
    }
    cin >> t;
    while (t--)
    {
        int n;
        string str, ans;
        cin >> n >> str;
        for (auto &i: v)
        {
            ans=i;
            if (str.find(i) == string::npos)
            {
                break;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

/*
3
28
qaabzwsxedcrfvtgbyhnujmiklop
13
cleanairactbd
10
aannttoonn
*/