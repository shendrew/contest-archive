#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define f first
#define s second
int n, ans;
pair<int,int> a[100001];
vector<pair<int,int>> order;

int main()
{
    ifstream fin ("convention2.in");
    ofstream fout ("convention2.out");
    fin >> n;;
    for (int i=n-1; i>=0; i--)
    {
        int x, y;
        fin >> x >> y;
        a[i]={x,y};
        order.push_back({x,i});
    }
    sort(order.begin(), order.end());
    int nextCow=1, time=a[order[0].s].f;
    priority_queue<int> wait;
    wait.push(order[0].s);
    while (wait.size())
    {
        int cur=wait.top();
        wait.pop();

        ans=max(ans, time-a[cur].f);
        time+=a[cur].s;
        bool gap=true;
        while (time>a[order[nextCow].s].f && nextCow<n)
        {
            wait.push(order[nextCow].s);
            nextCow++;
            gap=false;
        }
        if (gap && wait.size()==0 && nextCow<n)
        {
            time=a[order[nextCow].s].f;
            wait.push(order[nextCow].s);
            nextCow++;
        }
    }
    fout << ans << endl;
}
