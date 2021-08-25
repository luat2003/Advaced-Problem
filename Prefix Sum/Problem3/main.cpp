#include <iostream>

using namespace std;
long long h[1002][1002] ;
long long x1[100001] = {0};
long long y1[100001] = {0};
long long x2[100001] = {0};
long long y2[100001] = {0};
long long v[100001] = {0};
int main()
{
    long long n, m;
    cin >> n >> m;
    long long i, j;
    for( i = 0; i <= n+1; i++){
        for( j = 0; j <= n+1; j++){
            h[i][j] = 0;
        }
    }
    for( i = 1; i <= m; i++){
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i] >> v[i];
        h[x1[i]][y1[i]] += v[i];
        h[x1[i]][y2[i]+1] -= v[i];
        h[x2[i]+1][y1[i]] -= v[i];
        h[x2[i]+1][y2[i]+1] += v[i];
    }
    for( i = 1; i <= n; i++){
        for( j = 1; j <= n; j++){
            h[i][j] = h[i][j-1] + h[i-1][j]-h[i-1][j-1]+h[i][j];
            cout << h[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
