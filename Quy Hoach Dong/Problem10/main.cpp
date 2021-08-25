#include <iostream>
#define N 105
using namespace std;
int m, n, a[N], b[N], dp[N][N], kt[N][N] = {0};
int dayConChungDaiNhat( int k, int l){
    if( k == 0 || l == 0){
        return 0;
    }
    if( kt[k][l] ){
        return dp[k][l];
    }
    int maxx = 0;
    for( int i = k; i >= 1; i--){
        for( int j = l; j >= 1; j--){
            if( a[i] == b[j]){
                maxx = max(maxx, dayConChungDaiNhat(i-1,j-1)+1);
            }else{
                maxx = max(maxx, max(dayConChungDaiNhat(i,j-1), dayConChungDaiNhat(i-1,j)) );
            }
        }
    }
    kt[k][l] = 1;
    dp[k][l] = maxx;
    return maxx;

}

int main()
{
    cin >> m >> n;
    for( int i = 1; i <= m; i++){
        cin >> a[i];
    }
    for( int i = 1; i <= n; i++){
        cin >> b[i];
    }
    cout << dayConChungDaiNhat(m,n);
    return 0;
}
