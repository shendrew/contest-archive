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

int k, m;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> k >> m;
    set<int> num;
    for (int i=1; i<=k; i++)
    {
        num.insert(i);
    }
    for (int i=0; i<m; i++)
    {
        int r;
        cin >> r;
        vector<int> rmv;
        int ind=1;
        for (auto &j: num)
        {
            if (ind%r==0)
            {
                rmv.push_back(j);
            }
            ind++;
        }
        for (auto &j: rmv)
        {
            num.erase(j);
        }
    }

    for (auto &i: num)
    {
        cout << i << endl;
    }

    return 0;
}

/*
10
2
2
3
*/