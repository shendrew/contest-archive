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
        string str;
        cin >> n >> str;
        vector<int> vt, vm;
        for (int i=0; i<n; i++)
        {
            if (str[i]=='T')
            {
                vt.push_back(i);
            }
            else
            {
                vm.push_back(i);
            }
        }

        bool possible=true;
        if (vm.size()*2==vt.size())
        {
            for (int i=0; i<vm.size(); i++)
            {
                if (!(vt[i]<vm[i] && vm[i]<vt[i+vm.size()]))
                {
                    possible=false;
                    break;
                }
            }
        }
        else
        {
            possible=false;
        }
        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

/*
5
3
TMT
3
MTT
6
TMTMTT
6
TMTTTT
6
TTMMTT
*/