#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

int t;

int main()
{
    cin >> t;
    for (int i=0; i<t; i++)
    {
        int m,n;
        cin >> m;
        n=m;
        vector<int> sqr;
        set<int> sq;
        while (n>2)
        {
            sqr.push_back(n);
            sq.insert(n);
            n=ceil(pow(n,0.5));
        }
        sqr.push_back(2);
        sq.insert(2), sq.insert(1);
        cout << m-sq.size()+2*(sqr.size()-1) << endl;
        for (int j=1; j<=m; j++)
        {
            if (sq.count(j)==0)
            {
                cout << j << " " << sqr[0] << endl;
            }
        }
        for (int j=0; j<sqr.size()-1; j++)
        {
            cout << sqr[j] << " " << sqr[j+1] << endl;
            cout << sqr[j] << " " << sqr[j+1] << endl;
        }
    }
    return 0;
}

/*
3
3
4
200000
*/
