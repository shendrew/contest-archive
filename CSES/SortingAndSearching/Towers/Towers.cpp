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

int n;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    multiset<int> tower;
    for (int i=0; i<n; i++)
    {
        int ki;
        cin >> ki;
        if (tower.upper_bound(ki)!=tower.end())
        {
            tower.erase(tower.upper_bound(ki));
        }
        tower.insert(ki);
    }

    cout << tower.size() << endl;

    return 0;
}

/*
5
3 8 2 1 5
*/