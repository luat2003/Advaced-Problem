#include <iostream>
#include <algorithm>
#define N 5005
using namespace std;
int n, dp[N][N], kt[N][N] = {0}, cat[N][N] = {0}, check[N][N] = {0}, minn = 1e9, maxx = 0;
struct Circle {
    int c, r, sc1 = 0, sc2 = 0;
} vong[N];
bool cmp(Circle a, Circle b) {
    return a.c < b.c;
}

int soDuongTronNhieuNhat( int k , int l){
    int dem = 0;
    for( int j = 1; j <= n; j++){
        if( (k <= vong[j].c - vong[j].r) && (vong[j].c + vong[j].r <= l) ){
            dem++;
        }
    }
    return dem;
}

int xoaItNhat( int k, int l ){

    if(  kt[k+99][l+99]  ){
        return dp[k+99][l+99];
    }
    if( soDuongTronNhieuNhat( k, l ) == 0  ){
        dp[k+99][l+99] = 0;
        kt[k+99][l+99] = 1;
        return 0;
    }
    if( soDuongTronNhieuNhat( k, l ) == 1 ){
        dp[k+99][l+99] = 1;
        kt[k+99][l+99] = 1;
        return 1;
    }

    int Max = 0, Maxx = 0;
    for( int i = k+1; i <= l-1; i++){
        Max = max(Max, xoaItNhat(k,i) + xoaItNhat(i,l) + check[k+99][l+99] ); // Tìm cách chia đoạn đã cho thành các đoạn nhỏ
        // Mỗi đoạn nhỏ chứa nhiều đường tròn nhất, và cứ chia như vậy đến khi mỗi khoảng chứa có <= 1 đường tròn thì dừng
    }
    dp[k+99][l+99] = Max;
    kt[k+99][l+99] = 1;
    return Max;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for( int i = 1; i <= n; i++){
        cin >> vong[i].c >> vong[i].r;
        minn = min(minn, vong[i].c - vong[i].r);
        maxx = max( maxx, vong[i].c + vong[i].r);
        check[vong[i].c - vong[i].r+99][vong[i].c+vong[i].r+99] = 1;
    }
    sort(vong+1, vong+n+1, cmp);
    cout << n - xoaItNhat(minn, maxx) ;
    return 0;
}
