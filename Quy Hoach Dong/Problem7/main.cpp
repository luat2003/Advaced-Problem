#include <iostream>
#define N 105
using namespace std;
int n, M, w[N], v[N], dp[N][10005], kt[N][10005] = {0}, Max = 0;

int giaTriLonNhat( int k, int kl){
    if( kt[k][kl] == 1 ){
        return dp[k][kl];
    }
    for( int i = 1; i <= k; i++){
        for( int j = 1; j <= kl; j++){
            if( j < w[i] ){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    kt[k][kl] = 1;
    return dp[k][kl];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> M;
    for( int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for( int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cout << giaTriLonNhat(n, M);
    return 0;
}
