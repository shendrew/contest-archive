#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;

int main()
{
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int r, b, ans=0;
        int ar[1000]={0}, ab[1000]={0};
        cin >> r;
        for (int j=1; j<=r; j++)
        {
            int ri;
            cin >> ri;
            ar[j]=ar[j-1]+ri;
        }
        cin >> b;
        for (int j=1; j<=b; j++)
        {
            int bi;
            cin >> bi;
            ab[j]=ab[j-1]+bi;
        }

        for (int j=0; j<=r; j++)
        {
            for (int e=0; e<=b; e++)
            {
                ans=max(ans, ar[j]+ab[e]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}

/*
4
4
6 -5 7 -3
3
2 3 -4
2
1 1
4
10 -3 2 2
5
-1 -2 -3 -4 -5
5
-1 -2 -3 -4 -5
1
0
1
0
*/
