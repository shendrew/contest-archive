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
int visit[1001];

int main()
{
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> edge[1001];
        for (int i=0; i<n-1; i++)
        {
            int n1, n2;
            cin >> n1 >> n2;
            edge[n1].push_back(n2);
            edge[n2].push_back(n1);
        }

        if (!(n%2) || edge[x].size()<=1)
        {
            cout << "Ayush" << endl;
        }
        else
        {
            cout << "Ashish" << endl;
        }
    }

    return 0;
}

/*
1
9 1
1 2
1 3
3 4
3 5
1 6
6 7
6 9
7 8
*/