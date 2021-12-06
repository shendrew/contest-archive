#include <iostream>
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
int n;

bool cmp(string const &str1, string const &str2)
{
    string s1=str1+str2, s2=str2+str1;
    return (s1.compare(s2) < 0);
}

int main()
{
    cin >> n;
    vector<string> v(n);
    for (int i=0; i<n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), cmp);

    for (auto &i: v)
    {
        cout << i;
    }
    cout << endl;

    return 0;
}

/*
3
c
cb
cba
*/