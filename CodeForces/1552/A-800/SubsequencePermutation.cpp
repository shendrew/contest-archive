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
        string str;
        cin >> n >> str;
        vector<char> v, sv;
        for (int i=0; i<n; i++)
        {
            v.push_back(str[i]);
            sv.push_back(str[i]);
        }
        sort(sv.begin(), sv.end());

        int ans=0;
        for (int i=0; i<n; i++)
        {
            if (v[i]!=sv[i])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}

/*
4
3
lol
10
codeforces
5
aaaaa
4
dcba
*/