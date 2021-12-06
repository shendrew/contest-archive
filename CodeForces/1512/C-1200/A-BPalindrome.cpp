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

    while(t--)
    {
        int a, b, n;
        string str;
        cin >> a >> b >> str;
        n=a+b;
        vector<int> v;
        for (int i=0; i<n; i++)
        {
            if (str[i]=='0')
            {
                v.push_back(0);
            }
            else if (str[i]=='1')
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(-1);
            }
        }

        int zero=0, one=0;
        bool possible=true;
        for (int i=0; i<n/2; i++)
        {
            int num1=v[i], num2=v[n-i-1];
            if (num1==0)
            {
                zero++;
                if (num2==-1)
                {
                    zero++;
                    v[n-i-1]=0;
                }
                else if (num2==0)
                {
                    zero++;
                }
                else
                {
                    possible=false;
                    break;
                }
            }
            else if (num1==1)
            {
                one++;
                if (num2==-1)
                {
                    one++;
                    v[n-i-1]=1;
                }
                else if (num2==1)
                {
                    one++;
                }
                else
                {
                    possible=false;
                    break;
                }
            }
            else if (num1==-1)
            {
                if (num2==0)
                {
                    zero+=2;
                    v[i]=0;
                }
                else if (num2==1)
                {
                    one+=2;
                    v[i]=1;
                }
            }
        }

        if (n%2)
        {
            if (v[(n+1)/2-1]==0)
            {
                zero++;
            }
            else if (v[(n+1)/2-1]==1)
            {
                one++;
            }
        }

        for (int i=0; i<(n+1)/2; i++)
        {
            if (v[i]==-1)
            {
                if (n%2 && i==(n+1)/2-1)
                {
                    if (zero<a)
                    {
                        zero++;
                        v[i]=0;
                    }
                    else if (one<b)
                    {
                        one++;
                        v[i]=1;
                    }
                }
                else
                {
                    if (zero+2<=a)
                    {
                        zero+=2;
                        v[i]=0, v[n-i-1]=0;
                    }
                    else if (one+2<=b)
                    {
                        one+=2;
                        v[i]=1, v[n-i-1]=1;
                    }
                }
            }
        }

        if (zero==a && one==b && possible)
        {
            for (auto &i: v)
            {
                cout << i;
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}

/*
9
4 4
01?????0
3 3
??????
1 0
?
2 2
0101
2 2
01?0
0 1
0
0 3
1?1
2 2
?00?
4 3
??010?0
*/