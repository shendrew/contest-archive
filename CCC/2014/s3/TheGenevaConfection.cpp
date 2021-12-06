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
using namespace std;

#define f first
#define s second
#define ll long long

int t;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=n-1; i>=0; i--)
        {
            cin >> v[i];
        }
        
        int pre=0, i=0;
        stack<int> stk;
        while (1)
        {
            if (stk.size() && stk.top()==pre+1)
            {
                pre++;
                stk.pop();
                continue;
            }
            if (i==n || pre==n)
            {
                break;
            }
            if (v[i]==pre+1)
            {
                pre++;
            }
            else
            {
                stk.push(v[i]);
            }
            i++;
        }

        if (pre==n)
        {
            cout << "Y" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }

    return 0;
}

/*
2
4
2
3
1
4
4
4
1
3
2
*/