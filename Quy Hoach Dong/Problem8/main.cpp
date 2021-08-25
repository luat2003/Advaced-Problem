#include <iostream>
#define N 105
using namespace std;
int m, n, dp[N][N], kt[N][N] = {0},  gt[N][N] = {0}, Max = -99999999;
int giaTriLonNhat( int k, int vt){
    if( k == m ){
        return gt[m][vt];
    }
    if( k < m && vt == n){
        return -99999999;
    }
    if( kt[k][vt] == 1){
        return dp[k][vt];
    }
    int maxx = -99999999;
    for( int j = vt+1; j <= n; j++){
        maxx = max( maxx, giaTriLonNhat(k+1, j) + gt[k][vt]);
    }
    kt[k][vt] = 1;
    dp[k][vt] = maxx;
    return dp[k][vt];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for( int i = 1; i <= m; i++){
        for( int j = 1; j <= n; j++){
            cin >> gt[i][j];
        }
    }
    for( int i = 1; i <= n-m+1; i++){
        Max = max(Max, giaTriLonNhat(1,i));
    }
    cout << Max;
    return 0;
}
