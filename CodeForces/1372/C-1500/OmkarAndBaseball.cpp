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
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i=0; i<n; i++)
        {
            cin >> v[i];
        }

        int start=0, finish=n-1;

        while (v[start]==start+1 && start<n)
        {
            start++;
        }
        while (v[finish]==finish+1 && finish>=0)
        {
            finish--;
        }

        int correct=0;
        for (int i=start; i<=finish; i++)
        {
            if (v[i]==i+1)
            {
                correct++;
            }
        }
        if (start==n)
        {
            cout << 0 << endl;
        }
        else if (correct==0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }   
    }

    return 0;
}

/*
2
5
1 2 3 4 5
7
3 2 4 5 1 6 7
*/