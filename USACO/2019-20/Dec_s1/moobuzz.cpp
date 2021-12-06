#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

ifstream fin("moobuzz.in");
ofstream fout("moobuzz.out");


int n;
int a[8] = {14,1,2,4,7,8,11,13};

int main()
{
    fin >> n;

    fout << fixed << setprecision(0) << 15*floor((n-1)/8)+a[n%8] << endl;
    return 0;
}
