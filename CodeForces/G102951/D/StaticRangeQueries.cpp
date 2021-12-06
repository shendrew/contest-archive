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

int n, q;
long long prefix[1000006];

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;

    set<int> points;
    map<int, int> change;
    for (int i=0; i<n; i++)
    {
        int l, r, v;
        cin >> l >> r >> v;
        l++, r++;
        points.insert(l);
        points.insert(r);
        change[l]+=v;
        change[r]-=v;
    }

    vector<pair<int, int>> query;
    for (int i=0; i<q; i++)
    {
        int l, r;
        cin >> l >> r;
        l++, r++;
        points.insert(l);
        points.insert(r-1);
        points.insert(l-1);
        query.push_back({l, r-1});
    }
    points.insert(0);

    map<int, int> valInd, indVal;
    int ind=0;
    for (auto &i: points)
    {
        valInd[i]=ind;
        indVal[ind]=i;
        ind++;
    }

    long long cur=0;
    for (int i=0; i<points.size(); i++)
    {
        prefix[i]+=prefix[i-1];
        prefix[i]+=cur*(indVal[i]-indVal[i-1]-1);
        cur+=change[indVal[i]];
        prefix[i]+=cur;
    }

    for (auto &i: query)
    {
        cout << prefix[valInd[i.s]]-prefix[valInd[i.f]-1] << endl;
    }

    return 0;
}

/*
5 5
3 7 2
1 10 4
1 6 10
0 4 10
6 7 1
5 7
0 2
5 9
1 6
4 9
*/