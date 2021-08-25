#include <iostream>
int x[11];
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, i;
    cin >> n;
    for( i = 1; i <= n; i++){
        x[i] = i;
    }
    while( i > 0 ){
        for( i = 1; i <= n; i++){
            cout << x[i] << " ";
        }
        cout << "\n";
        i = n-1;
        while( i>0 && x[i] > x[i+1]){
            i--;
        }
        int k = n;
        while( x[k] < x[i] ){
            k--;
        }
        x[i] += x[k];
        x[k] = x[i]-x[k];
        x[i] = x[i]-x[k];
        int a = i+1, b = n;
        while ( a < b){
            x[a] += x[b];
            x[b] = x[a]-x[b];
            x[a] = x[a]-x[b];
            a++;
            b--;
        }
    }
    return 0;
}
