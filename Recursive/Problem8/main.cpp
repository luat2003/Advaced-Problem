#include <iostream>
#define N 27
#define M 99999999
using namespace std;
int kt[N] = {0}, a[N][N], n, k, minn = M, Min = M;
void quangDuongNhoNhat( int vt, int tong, int soKhach, int soDiem){
    if( soDiem >= 2*n && soKhach == 0){
        minn = min(minn, tong + a[vt][0]);
    }else{
        for( int i = 1; i <= 2*n; i++){
            if( kt[i] == 0 ){
                kt[i] = 1;
                if( i > n && kt[i-n] == 1 && (tong + a[vt][i] + Min*(2*n-soDiem) ) < minn ){
                    quangDuongNhoNhat(i, tong + a[vt][i], soKhach - 1, soDiem+1);
                }
                if( i <= n && soKhach < k && (tong + a[vt][i] + Min*(2*n-soDiem) ) < minn ){
                    quangDuongNhoNhat( i, tong + a[vt][i], soKhach + 1, soDiem+1);
                }
                kt[i] = 0;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for( int i = 0; i <= 2*n; i++){
        for( int j = 0; j <= 2*n; j++){
            cin >> a[i][j];
            if( a[i][j] != 0){
                Min = min( Min, a[i][j]);
            }
        }
    }
    quangDuongNhoNhat(0, 0, 0, 0);
    cout << minn;
    return 0;
}
