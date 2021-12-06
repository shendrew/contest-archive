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
int n, m;

int main()
{
    cin >> n >> m;
    multiset<int> ticket;
    for (int i=0; i<n; i++)
    {
        int h;
        cin >> h;
        ticket.insert(h);
    }
    for (int i=0; i<m; i++)
    {
        int t;
        cin >> t;
        if (ticket.upper_bound(t)==ticket.begin())
        {
            cout << -1 << endl;
            continue;
        }
        auto it=ticket.upper_bound(t);
        it--;
        cout << *it << endl;
        ticket.erase(it);
    }

    return 0;
}

/*
5 3
5 3 7 8 5
4 8 3
*/