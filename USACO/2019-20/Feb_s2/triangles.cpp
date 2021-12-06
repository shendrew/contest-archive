#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

ifstream fin("triangles.in");
ofstream fout("triangles.out");

#define f first
#define s second
int n;
vector<pair<pair<int,int>,int>> ax, ay; //same x, same y
long long lenX[100000], lenY[100000];
long long ans;

int main()
{
    fin >> n;
    for (int i=0; i<n; i++)
    {
        int x, y;
        fin >> x >> y;
        ax.push_back({{x,y},i});
        ay.push_back({{y,x},i});
    }
    sort(ax.begin(),ax.end()), sort(ay.begin(),ay.end());

    vector<int> indx={ax[0].s}, indy={ay[0].s}, dx, dy;
    int startY=ax[0].f.s, startX=ay[0].f.s;
    long long preX=0, preY=0;

    for (int i=0; i<ax.size(); i++)
    {
        if (ax[i].f.f!=ax[i+1].f.f || i==ax.size()-1)
        {
            lenX[indx[0]]=preX;
            for (int j=0; j<dx.size(); j++)
            {
                preX=preX+(j-(dx.size()-1-j))*dx[j];
                lenX[indx[j+1]]=preX;
            }
            dx.clear();
            indx.clear();
            startX=ax[i+1].f.s;
            preX=0;
        }
        else
        {
            dx.push_back(ax[i+1].f.s-ax[i].f.s);
            preX+=ax[i+1].f.s-startX;
        }
        indx.push_back(ax[i+1].s);
    }

    for (int i=0; i<ay.size(); i++)
    {
        if (ay[i].f.f!=ay[i+1].f.f || i==ay.size()-1)
        {
            lenY[indy[0]]=preY;
            for (int j=0; j<dy.size(); j++)
            {
                preY=preY+(j-(dy.size()-1-j))*dy[j];
                lenY[indy[j+1]]=preY;
            }
            dy.clear();
            indy.clear();
            startY=ay[i+1].f.s;
            preY=0;
        }
        else
        {
            dy.push_back(ay[i+1].f.s-ay[i].f.s);
            preY+=ay[i+1].f.s-startY;
        }
        indy.push_back(ay[i+1].s);
    }

    for (int i=0; i<n; i++)
    {
        ans+=lenX[i]*lenY[i];
    }

    int mod=pow(10,9)+7;

    fout << ans%mod << endl;

    return 0;
}

/*
4
0 0
0 1
1 0
1 2
*/