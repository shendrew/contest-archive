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
int n, q;
int prefix[200001];

int main()
{
    cin >> n >> q;
    for (int i=1; i<=n; i++)
    {
        int a;
        cin >> a;
        prefix[i]=prefix[i-1]^a;
    }
    for (int i=0; i<q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << (prefix[b]^prefix[a-1]) << endl;
    }

    return 0;
}

/*
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
*/