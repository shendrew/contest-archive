#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cereal.in");
ofstream fout("cereal.out");

int n,m,cows;
int f[100001], s[100001], cereal[100001], ans[100001];

int main()
{
    fin >> n >> m;
    for (int i=n; i>0; i--)
    {
        fin >> f[i] >> s[i];
    }
    
    for (int i=1; i<n+1; i++)
    {
        int cur=i;
        int pick=f[cur];
        while (1)
            {
            if (cereal[pick]==0) // if reaches start (i=0) or empty spot, cow++
            {
                cereal[pick]=cur;
                cows++;
                break;
            }
            else if (cereal[pick]>cur) // if can't take pick (second choice)
                break;
            else // previous cow now has two choices (take second / nothing)
            {
                int pre=cereal[pick]; // previous cow that took pick
                cereal[pick]=cur; // set cow to current
                if (pick == s[pre]) // if pick is the previous cow's second
                    break;
                cur=pre; // current to previous
                pick=s[pre]; // set the pick to
                    
            }
        }
        ans[i]=cows;
    }
    for (int i=n; i>0; i--)
    {
        fout << ans[i] << endl;
        cout << ans[i] << endl;
    }
    return 0;
}
