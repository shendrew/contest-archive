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
int t;

int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        int win=n/2;
        if (!(n%2))
        {
            win=(n-2)/2;
        }
        for (int j=0; j<n-1; j++)
        {
            int counter=0;
            for (int k=j+1; k<n; k++)
            {
                if (counter<win)
                {
                    cout << 1 << " ";
                }
                else if (counter==win && !(n%2))
                {
                    cout << 0 << " ";
                }
                else
                {
                    cout << -1 << " ";
                }
                counter++;
            }
        }
        cout << endl;
    }

    return 0;
}

/*
2
2
3
*/