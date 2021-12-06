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
#define ll long long
int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<pair<pair<int, int>, int>> vh(n), vw(n);
        vector<pair<int, int>> minw(n), minh(n), a(n);
        for (int i=0; i<n; i++)
        {
            scanf("%d%d", &a[i].f, &a[i].s);
            vh[i].f.f=a[i].f, vh[i].f.s=a[i].s;
            vw[i].f.f=a[i].s, vw[i].f.s=a[i].f;
            vh[i].s=i+1, vw[i].s=i+1;
        }
        sort(vh.begin(), vh.end()), sort(vw.begin(), vw.end());

        minw[0]={vh[0].f.s, vh[0].s}, minh[0]={vw[0].f.s, vw[0].s};
        for (int i=1; i<n; i++)
        {
            minw[i]=minw[i-1];
            minh[i]=minh[i-1];
            if (vh[i].f.s<minw[i-1].f)
            {
                minw[i]={vh[i].f.s, vh[i].s};
            }
            if (vw[i].f.s<minh[i-1].f)
            {
                minh[i]={vw[i].f.s, vw[i].s};
            }
        }

        for (int i=0; i<n; i++)
        {
            int low=0, high=n-1, mid=(low+high+1)/2, ans=-1;
            while (low!=high)
            {
                mid=(low+high+1)/2;
                if (vh[mid].f.f<a[i].f)
                {
                    low=mid;
                }
                else
                {
                    high=--mid;
                }
            }
            if (vh[mid].f.f<a[i].f && minw[mid].f<a[i].s)
            {
                ans=minw[mid].s;
            }

            low=0, high=n-1, mid=(low+high+1)/2;
            while (low!=high)
            {
                mid=(low+high+1)/2;
                if (vw[mid].f.f<a[i].f)
                {
                    low=mid;
                }
                else
                {
                    high=--mid;
                }
            }
            if (vw[mid].f.f<a[i].f && minh[mid].f<a[i].s)
            {
                ans=minh[mid].s;
            }
            printf("%d ", ans);
        }
        printf("\n");
    }

    return 0;
}

/*
4
3
3 4
5 4
3 3
3
1 3
2 2
3 1
4
2 2
3 1
6 3
5 4
4
2 2
2 3
1 1
4 4
*/