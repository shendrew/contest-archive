#include <iostream>
#include <vector>
using namespace std;

int n;
long long a[100001], dp[100001];

int main()
{
    cin >> n;
    int i, high=0;
    for (i=0; i<n; i++)
    {
        int ind;
        cin >> ind;
        a[ind]++;
        high=max(ind,high);
    }
    dp[1]=a[1];
    long long ans=dp[1];
    for (i=2; i<=high; i++)
    {
        dp[i]=max(dp[i-1],(a[i]*i)+dp[i-2]);
        ans=dp[i];
    }
    cout << ans;

    return 0;
}
