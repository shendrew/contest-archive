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
    for (int i=0; i<t; i++)
    {
        set<int> num;
        map<int, int> m, ind;
        int n;
        cin >> n;
        for (int j=0; j<n; j++)
        {
            int a;
            cin >> a;
            num.insert(a);
            m[a]++;
            ind[a]=j+1;
        }

        for (auto &j: num)
        {
            if (m[j]==1)
            {
                cout << ind[j] << endl;
                break;
            }
        }
    }

    return 0;
}

/*
4
4
11 13 11 11
5
1 4 4 4 4
10
3 3 3 3 10 3 3 3 3 3
3
20 20 10
*/