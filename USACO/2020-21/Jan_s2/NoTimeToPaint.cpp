#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n, q;
string str;
int a[100001], prefix[100002], suffix[100002], preVis[100002], sufVis[100002];

int main()
{
    cin >> n >> q >> str;

    for (int i=1; i<=n; i++)
    {
        a[i]=int(str[i-1])-64;
    }

    int pre=0;
    for (int i=1; i<=n; i++)
    {
        prefix[i]=prefix[i-1];
        if (!preVis[a[i]] || a[i]>pre)
        {
            prefix[i]++;
        }
        else
        {
            for (int j=a[i]-1; j>=1; j--)
            {
                if (preVis[j]>preVis[a[i]])
                {
                    prefix[i]++;
                    break;
                }
            }
        }
        preVis[a[i]]=i;
        pre=a[i];
    }

    int suf=0;
    for (int i=n; i>=1; i--)
    {
        suffix[i]=suffix[i+1];
        if (!sufVis[a[i]] || a[i]>suf)
        {
            suffix[i]++;
        }
        else
        {
            for (int j=a[i]-1; j>=1; j--)
            {
                if (sufVis[j]>0 && sufVis[j]<sufVis[a[i]])
                {
                    suffix[i]++;
                    break;
                }
            }
        }
        sufVis[a[i]]=i;
        suf=a[i];
    }

    for (int i = 0; i<q; i++)
    {
        int p1, p2;
        cin >> p1 >> p2;
        cout << prefix[p1-1]+suffix[p2+1] << endl;
    }

    return 0;
}

/*
8 2
ABBAABCB
3 6
1 4
*/
