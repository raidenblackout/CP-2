#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define ll long long
#define forn(i, n) for (int i = 0; i < n; i++)
#define fort(i, n) for (int i = 1; i <= n; i++)
#define all(x) x.begin(), x.end()
#define read(x) freopen(x, "r", stdin);
#define write(x) freopen(x, "w", stdout);
#define FastRead                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(nullptr);
#define dd 256
const int MOD = 1e9 + 7;

//#define xihaad
int main()
{
    FastRead
#ifdef xihaad
        read("input.txt");
// write("output.txt");
#endif
    int testcase = 1;
    cin >> testcase;
    while (testcase--)
    {
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd;
        if (rb <= rd && cb <= cd)
            cout << min(abs(rd - rb), abs(cd - cb)) << endl;
        else if (rb < rd && cb > cd)
            cout << min(rd - rb, n - cb + n - cd) << endl;
        else if (cb < cd && rb > rd)
            cout << min(cd - cb, n - rb + n - rd) << endl;
        else
            cout << min(2*n-rd-rb,2*n-cd-cb) << endl;
    }
    //cerr << "time = " << clock() << " ms" << '\n';
    return 0;
}