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

int x, n;
long long ans;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> x >> n;
    multiset<long long> st;
    for (int i=0; i<n; i++)
    {
        long long d;
        cin >> d;
        st.insert(d);
    }
    
    while (st.size()>1)
    {
        long long cur=0;
        cur+=*st.begin();
        st.erase(st.begin());
        cur+=*st.begin();
        st.erase(st.begin());
        st.insert(cur);
        ans+=cur;
    }

    cout << ans << endl;

    return 0;
}

/*
8 3
2 3 3
*/