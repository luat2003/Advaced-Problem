#include <iostream>
#define N 60005
using namespace std;
int n, t[N], r[N], time[N] = {0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for( int i = 1; i <= n; i++){
        cin >> t[i];
    }
    time[1] = t[1];
    for( int i = 2; i <= n; i++){
        cin >> r[i];
        time[i] = min(time[i-1] + t[i], time[i-2]+r[i]);
    }
    cout << time[n];
    return 0;
}
