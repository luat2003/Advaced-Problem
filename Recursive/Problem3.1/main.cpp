#include <iostream>

using namespace std;

int a[11], kt[11] = {0}, n;
void hoanVi(){
    for( int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}

void recursive( int a[11], int j, int n){
    if( j == n+1 ){
        hoanVi();
        return;
    }
    for( int k = 1; k <= n; k++){
        if( kt[k] == 0 ){ // Kiểm tra xem số k đã được lấy chưa
            kt[k] = 1;
            a[j] = k; // gán a[j] = k
            recursive(a, j+1, n); // đệ quy lên j+1, khi đó tiếp tục gán a[j+1] đến khi j = n -> n+1 -> in ra
            kt[k] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    recursive(a, 1, n);
    return 0;
}
