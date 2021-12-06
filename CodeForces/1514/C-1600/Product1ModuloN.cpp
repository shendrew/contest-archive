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

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<int> ans;
    for (int i=1; i<n; i++)
    {
        if (gcd(i, n)==1)
        {
            ans.push_back(i);
        }
    }

    long long product=1;
    for (auto &i: ans)
    {
        product=product*i%n;
    }
    
    if (product!=1)
    {
        ans.pop_back();
    }

    cout << ans.size() << endl;
    for (auto &i: ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
5
*/