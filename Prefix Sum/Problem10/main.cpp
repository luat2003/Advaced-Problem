#include <iostream>
#define N 1502
long long a[N][N], h[N][N] = {0}, hcn[N] = {0}, hcn1[N] = {0}, hcn2[N] = {0};
long long max_tren_trai[N][N] = {0}, max_duoi_phai[N][N] = {0}, max_duoi_trai[N][N] = {0};
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long m, n, k, Max = 0, Max1, Max2, Max3, Max4, Max5, Max6, Max7, Max8, x, Max9, Max10;
    cin >> m >> n >> k;
    for( int i = 1; i <= m; i++){
        for( int j = 1; j <= n; j++){
            cin >> a[i][j];
            h[i][j] = h[i][j-1] + a[i][j];
        }
    }
    for( int j = k; j <= n; j++){
        for( int i = k, v = 1; i <= m; i++){
            max_tren_trai[i][j] = max(max_tren_trai[i-1][j], max_tren_trai[i][j-1]);
            max_duoi_phai[m-i+1][n-j+1] = max(max_duoi_phai[m-i+2][n-j+1], max_duoi_phai[m-i+1][n-j+2]);
            max_duoi_trai[m-i+1][j] = max(max_duoi_trai[m-i+2][j], max_duoi_trai[m-i+1][j-1]);
            while( v <= i ){

                hcn[v] = hcn[v-1]+h[v][j]-h[v][j-k];
                hcn1[v] = hcn1[v-1] + h[m-v+1][n-j+k] - h[m-v+1][n-j];
                hcn2[v] = hcn2[v-1] + h[m-v+1][j] - h[m-v+1][j-k];
                if( v >= k ){
                    max_tren_trai[i][j] = max(max_tren_trai[i][j], hcn[v]-hcn[v-k]);
                    max_duoi_phai[m-i+1][n-j+1] = max(max_duoi_phai[m-i+1][n-j+1], hcn1[v]-hcn1[v-k]);
                    max_duoi_trai[m-i+1][j] = max(max_duoi_trai[m-i+1][j], hcn2[v]-hcn2[v-k]);
                }
                v++;
            }
        }
    }
    for( int i = k; i <= n; i++){
        for( int v = 1; v <= m; v++){
            hcn[v] = hcn[v-1]+h[v][i]-h[v][i-k];
            if( v < k ){
                continue;
            }
            x = hcn[v] - hcn[v-k];
            Max1 = max_tren_trai[v-k][n];
            Max2 = max_duoi_phai[v+1][1];
            Max3 = max_tren_trai[m][i-k];
            Max4 = max_duoi_phai[1][i+1];
            Max5 = max(max_duoi_phai[v+1][i-k+1],Max4);
            Max6 = max(max_duoi_phai[v-k+1][i+1],Max2);
            Max7 = max_tren_trai[v][i-k];
            Max8 = max_tren_trai[v-k][i];
            Max9 = x+Max1+max_duoi_trai[v-k+1][i-k];
            Max10 = max(Max9,x+Max4+max_duoi_trai[v+1][i]);
            Max1 = max(x+Max1+Max6,x+Max3+Max5);
            Max1 = max(Max1, max(x+Max7+Max2, x+Max8+Max4) );
            Max = max( Max, max(Max1,Max10 ) );
        }
    }
    cout << Max;
    return 0;
}
