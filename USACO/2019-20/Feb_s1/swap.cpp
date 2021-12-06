#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("swap.in");
ofstream fout("swap.out");

int n, m, k;
int a[100001];
bool visited[100001];

int main() {
    fin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < m; i++) // swap 1 round
    {
        int l,r;
        fin >> l >> r;
        for (int j = 0; j < (r-l+1)/2; j++)
        {
            int temp = a[l+j];
            a[l+j] = a[r-j];
            a[r-j] = temp;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true; // if not searched
            int start = a[i];
            vector<int> cycle;
            cycle.push_back(i);
            while (start != i) // if not in postion or repeat until the value returns to position
            {
                visited[start] = true;
                cycle.push_back(start);
                start = a[start]; // go to the position of the current value
            }
            int mod = k % cycle.size(); // the first value of the cycle after all rounds
            for (int j = 0; j < cycle.size(); j++)
            {
                a[cycle[j]] = cycle[(j+mod) % cycle.size()]; // insert new values
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        fout << a[i] << endl;
        cout << a[i] << endl;
    }
    return 0;
}
