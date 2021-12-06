#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int n, m;

int main()
{
    ifstream fin ("inOut.in");
    ofstream fout ("inOut.out");
    fin >> n;

    /* code */

    fout << n << endl;
    cout << system("pwd") << endl;
    return 0;
}
