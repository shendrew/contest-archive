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

int t;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        string str1, str2;
        cin >> str1 >> str2;
        int n1=str1.size(), n2=str2.size(), count=0;
        for (int i=n2-1, j=n1-1; i>=0; i--)
        {
            while (j>=0 && str1[j]!=str2[i])
            {
                j-=2;
            }
            if (j>=0 && str2[i]==str1[j])
            {
                count++;
                j--;
            }
        }
        
        if (count==n2)
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
4
ababa
ba
ababa
bb
aaa
aaaa
aababa
ababa
*/