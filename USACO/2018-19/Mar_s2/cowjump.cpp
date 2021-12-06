#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

ifstream fin("cowjump.in");
ofstream fout("cowjump.out");

int n, p, q, ans, sni, fni;
vector<double> s;
vector<int> x, y, x2, y2;
vector<pair<pair<int, int>,int>> start, finish;
set<int> active;

bool intersect(float mid, int a, int b, int c, int d)
{
    return ((mid-a)*(mid-b) <= 0 && (mid-c)*(mid-d) <= 0);
}

int main()
{
    fin >> n;
    s.resize(n), x.resize(n), y.resize(n), x2.resize(n), y2.resize(n), start.resize(n), finish.resize(n);
    int i,j;
    for (i=0; i<n; i++)
    {
        fin >> x[i] >> y[i] >> x2[i] >> y2[i];
        if (make_pair(x[i],y[i])<=make_pair(x2[i],y2[i]))
        {
            start[i].first.first=x[i], start[i].first.second=y[i], finish[i].first.first=x2[i], finish[i].first.second=y2[i];
        }
        else
        {
            start[i].first.first=x2[i], start[i].first.second=y2[i], finish[i].first.first=x[i], finish[i].first.second=y[i];
        }
        start[i].second=i, finish[i].second=i;
    }
    for (i=0; i<n; i++)
    {
        if (x[i]!=x2[i])
        {
            s[i]=(y2[i]-y[i])/(1.0*(x2[i]-x[i]));
        }
    }
    sort(start.begin(),start.end()), sort(finish.begin(),finish.end());
    
    
    float poix, poiy;
    bool flag=false;
    active.insert(start[0].second);
    sni++;
    while (fni<n && !flag)
    {
        if (start[sni]<=finish[fni] && sni<n)
        {
            //cout << "add " << start[sni].first.first << ","<< start[sni].first.second << endl;
            j=start[sni].second;
            for (int h=0; h<active.size(); h++)
            {
                if (flag)
                    break;
                int i = *next(active.begin(), h);
                if (x[i]==x2[i] && x[j]==x2[j])
                {
                    continue;
                }
                if (x[i]==x2[i])
                {
                    poix=x[i];
                    poiy=s[j]*(poix-x[j])+y[j];
                }
                else if (x[j]==x2[j])
                {
                    poix=x[j];
                    poiy=s[i]*(poix-x[i])+y[i];
                }
                else
                {
                    poix=(y[i]-y[j]-s[i]*x[i]+s[j]*x[j])/(s[j]-s[i]);
                    poiy=s[i]*(poix-x[i])+y[i];
                }
                
                if (intersect(poix, x[i], x2[i], x[j], x2[j]) && intersect(poiy, y[i], y2[i], y[j], y2[j]))
                {
                    flag=true;
                    p=min(i, j), q=max(i, j);
                }
            }
            active.insert(start[sni].second);
            sni++;
        }
        else
        {
            //cout << "remove " << finish[fni].first.first << ","<< finish[fni].first.second << endl;
            active.erase(finish[fni].second);
            fni++;
        }
    }
    
    //cout << "p: " << p << " q: " << q << endl;
    
    i=q, ans=p;
    for (j=0; j<n; j++)
    {
        if (j!=i && j!=p)
        {
            if ((x[i]==x2[i]) && (x[j]==x2[j]))
            {
                continue;
            }
            if (x[i]==x2[i])
            {
                poix=x[i];
                poiy=s[j]*(poix-x[j])+y[j];
            }
            if (x[j]==x2[j])
            {
                poix=x[j];
                poiy=s[i]*(poix-x[i])+y[i];
            }
            else
            {
                poix=(y[i]-y[j]-s[i]*x[i]+s[j]*x[j])/(s[j]-s[i]);
                poiy=s[i]*(poix-x[i])+y[i];
            }
            
            if (intersect(poix, x[i], x2[i], x[j], x2[j]) && intersect(poiy, y[i], y2[i], y[j], y2[j]))
            {
                ans=q;
                break;
            }
        }
    }
    cout << ans+1;
    fout << ans+1;
    return 0;
}
