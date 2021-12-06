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

int n;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<string> v1(n), v2(n);
    for (int i=0; i<n; i++)
    {
        cin >> v1[i];
    }
    for (int i=0; i<n; i++)
    {
        cin >> v2[i];
    }

    map<string, string> m;
    for (int i=0; i<n; i++)
    {
        m[v1[i]]=v2[i];
    }

    bool possible=true;
    for (int i=0; i<n; i++)
    {
        if (v1[i]!=m[v2[i]] || v1[i]==v2[i])
        {
            possible=false;
            break;
        }
    }

    if (possible)
    {
        cout << "good" << endl;
    }
    else
    {
        cout << "bad" << endl;
    }

    return 0;
}

/*
4
Ada Alan Grace John
John Grace Alan Ada
*/