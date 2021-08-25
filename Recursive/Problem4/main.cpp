#include <iostream>

using namespace std;
int n, k, countt = 0, x[7], y[7],kt[7] = {0}, a[7];
void hoanVi(){
    for( int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << "\n";
    countt++;
}

void recursive( int k, int j, int n){
    if( j == n+1){
        hoanVi();
        return;
    }
    for( int i = 1; i <= n; i++){
        if( kt[i] == 0 ){
            int c = 0;
            for( int v = 0; v < k; v++){
                if( i == y[v] ){
                    if( kt[x[v]] == 0){
                        c = 1;
                        break;
                    }
                }
            }
            if( c == 1){
                continue;
            }
            kt[i] = 1;
            a[j] = i;
            recursive(k, j+1, n);
            kt[i] = 0;
        }
    }
}

int main(){
	cin >> n >> k;
	for( int i = 0; i < k; i++){
        cin >> x[i] >> y[i];
	}
	recursive(k, 1, n);
	cout << countt;
	return 0;
}
