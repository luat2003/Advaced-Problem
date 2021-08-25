#include <iostream>
#define N 1005
using namespace std;
int n, P, L, w[N], v[N], s[N] = {0};
double dp[N], kt[N] = {0};
double thoiGianNhoNhat(int k){
    if( k == n ){
        return L*1.0/v[n];
    }
    if( k > n ){
        return 0;
    }
    if( kt[k] == 1 ){
        return dp[k];
    }
    double minn = 99999999;
    for( int i = k+1; i <= n; i++){
        if( s[i] - s[k-1] > P){
            int MinV = v[k];
            for( int j = k; j <= i-1; j++){
                MinV = min(MinV, v[j]);
                minn = min( minn, thoiGianNhoNhat(j+1) + L*1.0/MinV);
            }
            break;
        }
        if( i == n ){
            int MinV = v[k];
            for( int j = k; j <= n; j++){
                MinV = min( MinV, v[j]);
                minn = min( minn, thoiGianNhoNhat(j+1) + L*1.0/MinV );
            }
        }
    }
    kt[k] = 1;
    dp[k] = minn;
    return minn;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    (cout << fixed).precision(6);
    cin >> n >> P >> L;
    for( int i = 1; i <= n; i++){
        cin >> w[i] >> v[i];
        s[i] = s[i-1]+w[i];
    }
    cout << thoiGianNhoNhat(1);
    return 0;
}
