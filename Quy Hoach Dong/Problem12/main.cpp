#include <iostream>
#define N 1005
#define M 40005
using namespace std;
int x1[N], x2[N], h[N], n, x, y, m, dp[N][N], kt[N][N] = {0};

int quangDuongNganNhat( int u, int v, int k){
    if( kt[v][k]){
        return dp[v][k];
    }
    if( v == 0 ){
        return 0;
    }
    if( k == n ){
        return h[n];
    }
    int minn = 99999999;
    for( int i = k+1; i <= n; i++){
        if( h[i] <= v && x1[i] < u && u < x2[i] ){
            minn = min( minn, quangDuongNganNhat(x1[i],h[i], i) + v-h[i]+u-x1[i]);
            minn = min( minn, quangDuongNganNhat(x2[i], h[i], i) + v-h[i]+x2[i]-u );
            break;
        }
        if( h[i] <= v && i < n && h[i+1] + m >= v && x1[i] <= u && u <= x2[i] ){
            minn = min( minn, quangDuongNganNhat(x1[i],h[i], i) + v-h[i]+u-x1[i]);
            minn = min( minn, quangDuongNganNhat(x2[i], h[i], i) + v-h[i]+x2[i]-u );
            break;
        }
        if( h[i] <= v && h[i]+m >= v && i < n && (h[i+1]+m < v || v > m) ){
            if( u == x1[i]){
                minn = min( minn, quangDuongNganNhat(x2[i],h[i], i) + v-h[i]+x2[i]-x1[i]);
                break;
            }
            if( u == x2[i]){
                minn = min( minn, quangDuongNganNhat(x1[i],h[i], i) + v-h[i]+x2[i]-x1[i]);
                break;
            }
            if( x1[i] < u && u < x2[i] ){
                minn = min( minn, quangDuongNganNhat(x1[i],h[i], i) + v-h[i]+u-x1[i]);
                minn = min( minn, quangDuongNganNhat(x2[i],h[i], i) + v-h[i]+x2[i]-u);
                break;
            }
        }
        if( i == n && h[i] <= v && h[i]+m >= v && x1[i] <= u && u <= x2[i]){
            minn = min( minn, quangDuongNganNhat(x1[i], h[n], n) + v-h[i]+u-x1[i]);
            minn = min( minn, quangDuongNganNhat(x1[i], h[n], n) + v-h[i]+u-x1[i]);
            break;
        }
        if( v <= m ){
            minn = min( minn, v);
        }
    }
    kt[v][k] = 1;
    dp[v][k] = minn;
    return minn;
}

int main()
{
    cin >> n >> x >> y >> m;
    for( int i = 1; i <= n; i++){
        cin >> x1[i] >> x2[i] >> h[i];
    }
    for( int i = 1; i < n; i++){
        for( int j = 1; j < n; j++){
            if( h[j] < h[j+1] ){
                swap(h[j], h[j+1]);
                swap(x1[j], x1[j+1]);
                swap(x2[j], x2[j+1]);
            }
        }
    }
    cout << quangDuongNganNhat(x,y, 0);
    return 0;
}
