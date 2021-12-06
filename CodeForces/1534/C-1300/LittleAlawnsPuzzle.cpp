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
int visit[400001];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        vector<int> v1, v2;
        map<int, int> m1;   //value, index
        for (int i=0; i<n; i++)
        {
            int a;
            scanf("%d", &a);
            v1.push_back(a);
            m1[v1[i]]=i;
        }
        for (int i=0; i<n; i++)
        {
            int a;
            scanf("%d", &a);
            v2.push_back(a);
        }
        
        for (int i=0; i<=400000; i++)
        {
            visit[i]=0;
        }

        int count=0;
        for (int i=0; i<n; i++)
        {
            if (!visit[v1[i]])
            {
                count++;
                int cur=v2[i], next;
                visit[v1[i]]=1;
                while(!visit[cur])
                {
                    visit[cur]=1;
                    next=v2[m1[cur]];
                    cur=next;
                }
            }
        }

        int ans=1;
        for (int i=1; i<=count; i++)
        {
            ans=(ans*2)%1000000007;
        }
        printf("%d\n", ans);
    }

    return 0;
}

/*
2
4
1 4 2 3
3 2 1 4
8
2 6 5 1 4 3 7 8
3 8 7 5 1 2 4 6
*/