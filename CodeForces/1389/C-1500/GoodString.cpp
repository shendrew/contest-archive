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
        int ans=0;
        string str;
        cin >> str;
        for (int i=0; i<=9; i++)
        {
            for (int j=0; j<=9; j++)
            {
                vector<int> need={i, j};
                int cnt=0, ind=0;
                for (int k=0; k<str.size(); k++)
                {
                    if (str[k]-'0'==need[ind])
                    {
                        cnt++;
                        ind^=1;
                    }
                }
                if (i!=j && cnt%2)
                {
                    cnt--;
                }
                ans=max(ans, cnt);
            }
        }
        cout << str.size()-ans << endl;
    }

    return 0;
}

/*
3
95831
100120013
252525252525
*/