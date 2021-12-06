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

struct node
{
    int value=-1;
    int level=-1;
};

int n, m;
int a[300005];
node tree[300005];

void build(int low, int high, int ind)
{
    if (low==high)
    {
        tree[ind].value=a[low];
        tree[ind].level=0;
        return;
    }
    int mid=(low+high)/2;
    build(low, mid, ind*2+1);
    build(mid+1, high, ind*2+2);

    tree[ind].level=tree[ind*2+1].level^1;
    if (tree[ind].level==1)
    {
        tree[ind].value=tree[ind*2+1].value|tree[ind*2+2].value;
    }
    else
    {
        tree[ind].value=tree[ind*2+1].value^tree[ind*2+2].value;
    }
}

void update(int low, int high, int ind, int val, int tar)
{
    if (low==high)
    {
        tree[ind].value=val;
        return;
    }
    int mid=(low+high)/2;
    if (tar<=mid)
    {
        update(low, mid, ind*2+1, val, tar);
    }
    else
    {
        update(mid+1, high, ind*2+2, val, tar);
    }

    if (tree[ind].level==1)
    {
        tree[ind].value=tree[ind*2+1].value|tree[ind*2+2].value;
    }
    else
    {
        tree[ind].value=tree[ind*2+1].value^tree[ind*2+2].value;
    }
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int p=pow(2, n);
    for (int i=0; i<p; i++)
    {
        cin >> a[i];
    }

    build(0, p-1, 0);

    for (int i=0; i<m; i++)
    {
        int ind, val;
        cin >> ind >> val;
        update(0, p-1, 0, val, ind-1);
        cout << tree[0].value << endl;
    }

    return 0;
}

/*
2 4
1 6 3 5
1 4
3 4
1 2
1 2
*/