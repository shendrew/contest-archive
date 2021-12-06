#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define f first
#define s second
int n;
vector<pair<int,int>> east, north;
map<pair<int,int>, int> ind;
int stopCow[1001], ans[1001];
bool stop[1001];

bool compareSecond(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second<b.second;
}

int main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        string d;
        int x, y;
        cin >> d >> x >> y;
        ind[{x,y}]=i;
        if (d=="E")
        {
            east.push_back({x,y});
        }
        else if (d=="N")
        {
            north.push_back({x,y});
        }
    }
    sort(east.begin(), east.end(), compareSecond);
    sort(north.begin(), north.end());
    for (int i=0; i<east.size(); i++)
    {
        for (int j=0; j<north.size(); j++)
        {
            if (!stop[ind[east[i]]] && !stop[ind[north[j]]] && east[i].f<north[j].f && east[i].s>north[j].s)
            {
                if (east[i].f-north[j].f == east[i].s-north[j].s)
                {

                }
                else if (north[j].f-east[i].f > east[i].s-north[j].s)
                {
                    stop[ind[east[i]]]=true;
                    stopCow[ind[east[i]]]=ind[north[j]];
                }
                else if (north[j].f-east[i].f < east[i].s-north[j].s)
                {
                    stop[ind[north[j]]]=true;
                    stopCow[ind[north[j]]]=ind[east[i]];
                }
            }
        }
    }


    for (int i=1; i<=n; i++)
    {
        int j=i;
        while (stopCow[j]!=0)
        {
            ans[stopCow[j]]++;
            j=stopCow[j];
        }
    }
    for (int i=1; i<=n; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}

/*
6
E 3 5
N 5 3
E 4 6
E 10 4
N 11 1
E 9 2
*/
