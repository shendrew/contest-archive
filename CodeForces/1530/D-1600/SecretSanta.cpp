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
        cin >> n;
        vector<int> v(n+1);
        for (int i=1; i<=n; i++)
        {
            cin >> v[i];
        }
        set<int> taken, loc, remain;
        vector<int> extra, ans(n+1), dif;
        for (int i=1; i<=n; i++)
        {
            if (taken.count(v[i]))
            {
                dif.push_back(i);
                loc.insert(i);
                remain.insert(i);
            }
            else
            {
                taken.insert(v[i]);
                ans[i]=v[i];
            }
        }
        for (int i=1; i<=n; i++)
        {
            if (taken.find(i)==taken.end())
            {
                extra.push_back(i);
            }
        }
        for (int i=0; i<dif.size(); i++)
        {
            ans[dif[i]]=extra[i];
        }

        if (extra.size()==1)
        {
            for (int i=1; i<=n; i++)
            {
                if (i!=dif[0] && v[i]==v[dif[0]] && ans[dif[0]]==dif[0])
                {
                    int temp=ans[i];
                    ans[i]=ans[dif[0]];
                    ans[dif[0]]=temp;
                    break;
                }
            }
        }
        else
        {
            vector<int> repeat, ok;
            for (int i=0; i<extra.size(); i++)
            {
                if (loc.count(extra[i]))
                {
                    repeat.push_back(extra[i]);
                    remain.erase(extra[i]);
                }
                else
                {
                    ok.push_back(extra[i]);
                }
            }
            
            if (repeat.size()==1)
            {
                for (auto &i: remain)
                {
                    if (repeat[0]!=i)
                    {
                        ans[i]=repeat[0];
                        remain.erase(i);
                        remain.insert(repeat[0]);
                        break;
                    }
                }
            }
            else if (repeat.size())
            {
                ans[repeat[0]]=repeat[repeat.size()-1];
                for (int i=1; i<repeat.size(); i++)
                {
                    ans[repeat[i]]=repeat[i-1];
                }
            }
            auto cur=remain.begin();
            for (int i=0; i<ok.size(); i++)
            {
                ans[*cur]=ok[i];
                cur++;
            }
        }

        cout << taken.size() << endl;
        for (int i=1; i<=n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }


    return 0;
}

/*
2
3
2 1 2
7
6 4 6 2 4 5 6

1
6
5 3 4 3 4 2
*/