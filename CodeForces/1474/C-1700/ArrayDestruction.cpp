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

int t;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        multiset<int, greater<int>> a;
        for (int i=0; i<2*n; i++)
        {
            int ai;
            cin >> ai;
            a.insert(ai);
        }

        bool possible=false;
        auto ind=a.begin();
        for (int i=1; i<2*n; i++)
        {
            int cur=*a.begin();
            bool good=true;
            ind++;
            multiset<int, greater<int>> num=a;
            vector<int> ans={cur+*ind};
            num.erase(num.find(cur));
            num.erase(num.find(*ind));
            ans.push_back(cur);
            ans.push_back(*ind);
            int x=cur;
            while (num.size())
            {
                cur=*num.begin();
                num.erase(num.find(cur));
                if (!num.count(x-cur))
                {
                    good=false;
                    break;
                }
                num.erase(num.find(x-cur));
                ans.push_back(cur);
                ans.push_back(x-cur);
                x=cur;
            }
            if (good)
            {
                cout << "YES" << endl << ans[0] << endl;
                for (int j=0; j<n; j++)
                {
                    cout << ans[j*2+1] << " " << ans[j*2+2] << endl;
                }
                possible=true;
                break;
            }
        }
        if (!possible)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

/*
4
2
3 5 1 2
3
1 1 8 8 64 64
2
1 1 2 4
5
1 2 3 4 5 6 7 14 3 11
*/