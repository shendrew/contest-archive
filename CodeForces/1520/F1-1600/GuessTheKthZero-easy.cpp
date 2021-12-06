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

int n, t, k;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> t >> k;
    int low=1, high=n+1, mid;
    while (low<high)
    {
        mid=low+(high-low)/2;
        int sum;
        cout << "? " << 1 << " " << mid << endl;
        cin >> sum;
        if (sum==-1)
        {
            exit(0);
        }
        if (mid-sum>=k)
        {
            high=mid;
        }
        else
        {
            low=++mid;
        }
    }

    cout << "! " << mid << endl;
    cout.flush();

    return 0;
}

/*
6 1
2

// 101101
*/