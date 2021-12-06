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
        int si;
        cin >> si;
        int sum=0, ind=0;
        while (sum+ind<si-1)
        {
            ind++;
            sum+=ind*2;
        }
        cout << ind+1 << endl;

    }

    return 0;
}

/*
4
1
8
7
42
*/