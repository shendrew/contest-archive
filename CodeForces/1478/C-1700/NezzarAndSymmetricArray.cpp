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
int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        bool possible=true;
        scanf("%d", &n);
        vector<long long> v, diff;
        set<long long> uni;
        map<long long, long long> occ;
        for (int i=0; i<2*n; i++)
        {
            long long ai;
            scanf("%lld", &ai);
            if (ai%2)
            {
                possible=false;
            }
            v.push_back(ai);
            uni.insert(ai);
            occ[ai]++;
        }

        for (auto &i: uni)
        {
            if (occ[i]%2)
            {
                possible=false;
            }
        }

        if (possible)
        {
            sort(v.begin(), v.end());

            for (int i=0; i<n-1; i++)
            {
                diff.push_back(v[2*(i+1)]-v[2*i]);
            }

            set<long long> ans;
            long long num;
            if (v[2*n-1]%(2*n)==0)
            {
                num=v[2*n-1]/(2*n);
                ans.insert(num);
                for (int i=n-1; i>=1; i--)
                {
                    num-=diff[i-1]/(2*i);
                    if (ans.find(num)!=ans.end() || diff[i-1]%(2*i) || num<=0)
                    {
                        possible=false;
                        break;
                    }
                    ans.insert(num);
                }
            }
            else
            {
                possible=false;
            }
            if (possible && num!=0)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}

/*
6
2
8 12 8 12
2
7 7 9 11
2
7 11 7 11
1
1 1
4
40 56 48 40 80 56 80 48
6
240 154 210 162 174 154 186 240 174 186 162 210
*/