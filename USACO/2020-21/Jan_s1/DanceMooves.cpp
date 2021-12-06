#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define f first
#define s second
int n, k;
int a[100001], finish[100001], output[100001];
set<int> uni[100001];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
        uni[i].insert(i);
        finish[i]=i;
    }
    for (int i=0; i<k; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;

        uni[a[p1]].insert(p2);
        uni[a[p2]].insert(p1);
        finish[a[p1]]=p2;
        finish[a[p2]]=p1;

        int temp=a[p1];
        a[p1]=a[p2];
        a[p2]=temp;

    }

    for (int i=1; i<=n; i++)
    {
        int cur=i;
        set<int> visit, ans;
        while (!visit.count(cur) && !output[cur])
        {
            visit.insert(cur);
            ans.insert(uni[cur].begin(), uni[cur].end());
            cur=finish[cur];
        }
        for (auto &j:visit)
        {
            output[j]=ans.size();
        }
    }

    for (int i=1; i<=n; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}

/*
5 4
1 3
1 2
2 3
2 4
*/
