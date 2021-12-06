#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <numeric>
#include <math.h>
#include <string>
#include <string.h>
#include <iomanip>
#include <functional>
using namespace std;

ifstream fin("family.in");
ofstream fout("family.out");

#define f first
#define s second
#define ll long long

int n, distA, distB;
string a, b;
map<string, string> parent;
vector<string> ancestorA, ancestorB;

void findParent(string cow, vector<string> &v)
{
    v.push_back(cow);
    if (parent[cow]!="")
    {
        findParent(parent[cow], v);
    }
}

void common()
{
    for (int i=0; i<ancestorA.size(); i++)
    {
        for (int j=0; j<ancestorB.size(); j++)
        {
            if (ancestorA[i]==ancestorB[j])
            {
                distA=i;
                distB=j;
                return;
            }
        }
    }
}

int main()
{
    fin >> n >> a >> b;
    for (int i=0; i<n; i++)
    {
        string x, y;
        fin >> x >> y;
        parent[y]=x;
    }

    findParent(a, ancestorA);
    findParent(b, ancestorB);

    common();

    if (distA==0 && distB==0)
    {
        fout << "NOT RELATED";
    }
    else if (distA==1 && distB==1)
    {
        fout << "SIBLINGS";
    }
    else if (distA==0 && distB==1)
    {
        fout << a << " is the mother of " << b;
    }
    else if (distB==0 && distA==1)
    {
        fout << b << " is the mother of " << a;
    }
    else if (distB && distA==0)
    {
        fout << a << " is the ";
        for (int i=0; i<distB-2; i++)
        {
            fout << "great-";
        }
        fout << "grand-mother of " << b;
    }
    else if (distA && distB==0)
    {
        fout << b << " is the ";
        for (int i=0; i<distA-2; i++)
        {
            fout << "great-";
        }
        fout << "grand-mother of " << a;
    }
    else if (distB && distA==1)
    {
        fout << a << " is the ";
        for (int i=0; i<distB-2; i++)
        {
            fout << "great-";
        }
        fout << "aunt of " << b;
    }
    else if (distA && distB==1)
    {
        fout << b << " is the ";
        for (int i=0; i<distA-2; i++)
        {
            fout << "great-";
        }
        fout << "aunt of " << a;
    }
    else
    {
        fout << "COUSINS";
    }
    fout << endl;

    return 0;
}