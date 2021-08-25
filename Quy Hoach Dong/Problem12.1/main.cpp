#include <iostream>
#define N 1005
#define X 40005
using namespace std;
int n, x, y, M, x1[N], x2[N], h[N], dp[X][N], kt[X][N] = {0};

int quangDuongNganNhat( int u, int k){
    if( kt[u+20000][k] ){
        return dp[u+20000][k];
    }
    int minn = 99999999, c = 0;
    for( int i = k+1; i <= n+1; i++){
        if( i == n+1 && M >= h[k] && x1[i] <= u && u <= x2[i]){
            minn = 0;
            kt[u+20000][k] = 1;
            dp[u+20000][k] = minn;
            return minn;
        }
        if( h[i] < h[k] && h[i] + M >= h[k] && x1[i] <= u && u <= x2[i]){
            c = 1;
            int j = i+1;
            minn = min( minn, quangDuongNganNhat(x1[i], i) + u - x1[i] );
            minn = min( minn, quangDuongNganNhat(x2[i], i) + x2[i] - u);
            break;
        }

    }
    if( c == 0 ){
        minn = 99999999;
    }
    kt[u+20000][k] = 1;
    dp[u+20000][k] = minn;
    return minn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y >> M;
    h[0] = y;
    h[n+1] = 0, x1[n+1] = -20000, x2[n+1] = 20000;
    for( int i = 1; i <= n; i++){
        cin >> x1[i] >> x2[i] >> h[i];
    }
    for( int i = 1; i < n; i++){
        for( int j = 1; j < n; j++){
            if( h[j] < h[j+1] ){
                swap( h[j], h[j+1]);
                swap(x1[j], x1[j+1]);
                swap(x2[j], x2[j+1]);
            }
        }
    }
    cout << y+quangDuongNganNhat(x, 0);
    return 0;
}
