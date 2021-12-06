#include <iostream>
#include <vector>
using namespace std;

int t, n;

int main()
{
    cin >> t;
    int i, j;
    for (i=0; i<t; i++)
    {
        cin >> n;
        int ans=0, mx;
        cin >> mx;
        for (j=1; j<n; j++)
        {
            int a;
            cin >> a;
            if (a<mx)
            {
                int cnt=0, sec=1;
                while (a<mx)
                {
                    a+=sec;
                    sec*=2;
                    cnt++;
                }
                ans=max(ans, cnt);
            }
            else
            {
                mx=a;
            }
        }
        cout << ans << endl;
    }
}
