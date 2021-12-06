#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
using namespace std;

#define f first
#define s second
int t;

int main()
{
    cin >> t;
    while (t--)
    {
        int n, comp=0, id;
        string str;
        cin >> n >> str;
        vector<int> ans(n);
        stack<int> zero, one;
        for (int i=0; i<n; i++)
        {
            if (!(str[i]-'0'))
            {
                if (!one.size())
                {
                    comp++;
                    id=comp;
                }
                else
                {
                    id=one.top();
                    one.pop();
                }
                zero.push(id);
            }
            else
            {
                if (!zero.size())
                {
                    comp++;
                    id=comp;
                }
                else
                {
                    id=zero.top();
                    zero.pop();
                }
                one.push(id);
            }
            ans[i]=id;
        }

        cout << comp << endl;
        for (auto &i: ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
4
4
0011
6
111111
5
10101
8
01010000
*/