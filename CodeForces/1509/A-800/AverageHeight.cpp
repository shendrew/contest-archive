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
        int n;
        vector<int> odd, even;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            int a;
            cin >> a;
            if (a%2)
            {
                odd.push_back(a);
            }
            else
            {
                even.push_back(a);
            }
        }
        for (auto &i: odd)
        {
            cout << i << " ";
        }
        for (auto &i: even)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
4
3
1 1 2
3
1 1 1
8
10 9 13 15 3 16 9 13
2
18 9
*/