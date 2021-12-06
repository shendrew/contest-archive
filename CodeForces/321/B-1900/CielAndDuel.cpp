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

int n, m, sum, ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    vector<int> atk, def, ciel(m);
    multiset<int> st;
    for (int i=0; i<n; i++)
    {
        int strength;
        string str;
        cin >> str >> strength;
        if (str=="ATK")
        {
            atk.push_back(strength);
        }
        else
        {
            def.push_back(strength);
        }
    }
    for (int i=0; i<m; i++)
    {
        cin >> ciel[i];
        st.insert(ciel[i]);
    }
    sort(atk.begin(), atk.end());
    sort(def.begin(), def.end());
    sort(ciel.begin(), ciel.end());

    if (m>=n)
    {
        bool all=true;
        for (int i=0; i<def.size(); i++)
        {
            if (st.upper_bound(def[i])==st.end())
            {
                all=false;
                break;
            }
            st.erase(st.upper_bound(def[i]));
        }
        for (int i=0; i<atk.size(); i++)
        {
            if (st.lower_bound(atk[i])==st.end())
            {
                all=false;
                break;
            }
            ans+=*st.lower_bound(atk[i])-atk[i];
            st.erase(st.lower_bound(atk[i]));
        }
        if (all)
        {
            for (auto &i: st)
            {
                ans+=i;
            }
        }
    }
    for (int i=1; i<=atk.size() && i<=m; i++)
    {
        int cur=0;
        for (int j=0; j<min(i, m); j++)
        {
            if (ciel[m-i+j]<atk[j])
            {
                break;
            }
            cur+=ciel[m-i+j]-atk[j];
        }
        ans=max(ans, cur);
    }

    cout << ans << endl;


    return 0;
}

/*
3 4
ATK 10
ATK 100
ATK 1000
1
11
101
1001
*/