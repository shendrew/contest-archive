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
        int n, k;
        char str[100000];
        cin >> n >> k >> str;
        sort(str, str+n);

        bool same=true;
        char start=str[0];
        for (int i=0; i<k; i++)
        {
            if (start!=str[i])
            {
                same=false;
            }
        }

        if (!same)
        {
            cout << str[k-1];
        }
        else
        {
            cout << str[0];

            set<char> unique;
            for (int i=k; i<n; i++)
            {
                unique.insert(str[i]);
            }

            if (unique.size()==1)
            {
                for (int i=0; i<ceil((n-k)/(double)k); i++)
                {
                    cout << str[k];
                }
            }
            else
            {
                for (int i=k; i<n; i++)
                {
                    cout << str[i];
                }
            }
        }
        cout << endl;
    }

    return 0;
}

/*
6
4 2
baba
5 2
baacb
5 3
baacb
5 3
aaaaa
6 4
aaxxzz
7 1
phoenix
*/