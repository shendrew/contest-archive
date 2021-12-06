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
int n;
int a[500][500];
long long ans;

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            int g;
            cin >> g;
            if (g==100) 
            {
                a[i][j]=2;
            }
            else if (g>100)
            {
                a[i][j]=1;
            }
        }
    }

    for (int x1=0; x1<n; x1++)
    {
        for (int y1=0; y1<n; y1++)
        {
            for (int x2=x1; x2<n; x2++)
            {
                for (int y2=y1; y2<n; y2++)
                {
                    long long test=1;
                    bool loop=true;
                    for (int i=x1; i<=x2; i++)
                    {
                        for (int j=y1; j<=y2; j++)
                        {
                            test*=a[i][j];
                            if (!a[i][j])
                            {
                                loop=false;
                                break;
                            }
                        }
                        if (!loop)
                        {
                            break;
                        }
                    }
                    if (test>1 && loop)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/*
3
57 120 87
200 100 150
2 141 135
*/