    #include <iostream>
    #include <vector>
    using namespace std;
     
    int n;
    int a[1000000], cnt[1000001];
    long long total, ans;
     
    int main()
    {
        cin >> n;
        int i, j;
        for (i=0; i<n; i++)
        {
            cin >> a[i];
            total+=a[i];
        }
        if (total%3!=0 || n<3)
        {
            cout << 0;
        }
        else
        {
            long long third=total/3, sum=0;
            for (i=n-1; i>=1; i--)
            {
                sum+=a[i];
                cnt[i]=cnt[i+1]+(sum==third);
            }
            sum=0;
            for (i=0; i<n-2; i++)
            {
                sum+=a[i];
                if (sum==third)
                {
                    ans+=cnt[i+2];
                }
            }
            cout << ans;
        }
    }