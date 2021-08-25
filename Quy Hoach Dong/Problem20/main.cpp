#include <bits/stdc++.h>
#include <string.h>
#define N 305
using namespace std;
int m;
long long dp[N][N][N] , a[N], L, R, n, dpL[N], dpR[N], min_L[N][N] , min_R[N][N]  , Min = 1e9;

bool ktTrongDoanL( int i, int k){
    if( a[i] <= a[k] && a[k] < dpL[i] ){
        return true;
    }
    return false;
}
bool ktTrongDoanR( int i, int k){
    if( a[i] <= a[k] && a[k] < dpR[i] ){
        return true;
    }
    return false;
}

void soBuocChuyenItNhat(){
    for(int k = 1; k <= m; k++){
        for( int l = 0; l <= m; l++){
            for( int r = 0; r <= m; r++){
                if( ktTrongDoanL(l, k) || ktTrongDoanR(r,k) ){
                    dp[k][l][r] = dp[k - 1][l][r];
                    dp[k][l][r] = min(dp[k][l][r] , min_R[k - 1][l] + 1);
                    dp[k][l][r] = min(dp[k][l][r] , min_L[k - 1][r] + 1);
                    min_R[k][l] = min(min_R[k][l] , dp[k][l][r]);
                    min_L[k][r] = min(min_L[k][r] , dp[k][l][r]);
                    if( k == m ){
                        Min = min( Min, dp[k][l][r]);
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> L >> R;
    memset(dp , 126 , sizeof(dp));
    memset(min_L , 126 , sizeof(min_L));
    memset(min_R , 126 , sizeof(min_R));
    dp[0][0][0] = 0;
    min_L[0][0] = 0;
    min_R[0][0] = 0;
    for( int i = 1; i <= m; i++){
        cin >> a[i];
        dpL[i] = a[i] + L;
        dpR[i] = a[i] + R;
    }
    a[0] = -n;
    soBuocChuyenItNhat();
    cout << Min;
    return 0;
}
