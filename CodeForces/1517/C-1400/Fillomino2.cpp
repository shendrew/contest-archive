#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string>
using namespace std;

#define f first
#define s second
int n;
int a[500][500];

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int p;
        cin >> p;
        a[i][i]=p;
    }

    for (int i=0; i<n; i++)
    {
        int fill=1;
        pair<int, int> cur={i, i};
        while (fill<a[i][i])
        {
            if (cur.s>0 && !a[cur.f][cur.s-1])
            {
                cur.s--;
            }
            else
            {
                cur.f++;
            }
            a[cur.f][cur.s]=a[i][i];
            fill++;
        }
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<=i; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
5
2 5 3 4 1
*/
