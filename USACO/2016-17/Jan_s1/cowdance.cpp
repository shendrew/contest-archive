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

ifstream fin("cowdance.in");
ofstream fout("cowdance.out");

#define f first
#define s second
#define ll long long

int n, maxt;
vector<int> v;

bool check(int k)
{
    int time=0;
    multiset<int> st;
    for (int i=0; i<k; i++)
    {
        st.insert(v[i]);
        time=max(time, v[i]);
    }
    for (int i=k; i<n; i++)
    {
        int cur=*st.begin();
        st.erase(st.begin());
        st.insert(cur+v[i]);
        time=max(time, cur+v[i]);
    }
    return time<=maxt;
}

int main()
{
    fin >> n >> maxt;
    v.resize(n);
    for (int i=0; i<n; i++)
    {
        fin >> v[i];
    }

    int low=1, high=n, mid;
    while (low<high)
    {
        mid=low+(high-low)/2;
        if (check(mid))
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }

    fout << mid << endl;

    return 0;
}