#include <iostream>

using namespace std;
int a[35], c[35], n, b, i = 0, maxx = 0;

void giaTri( int weight, int gia, int k){
    if( weight >= b || k > n){
        maxx = max(maxx, gia);
    }else{
        for( int i = 0; i <= 1; i++){
            if( i*a[k] + weight > b){
                        continue;
            }
            giaTri(weight + i*a[k], gia + i*c[k], k+1);
        }
    }
}


int main()
{
    cin >> n >> b;
    for( int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }
    giaTri(0, 0,1);
    cout << maxx;
    return 0;
}
