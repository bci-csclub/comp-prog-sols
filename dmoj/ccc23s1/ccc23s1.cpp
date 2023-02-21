#include <iostream>
using namespace std;

const int MN = 2e5 + 5;
int n;
bool arr[MN], brr[MN];
int ans;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i], ans += 3*arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i], ans += 3*brr[i];
    for(int i = 0; i < n-1; i++){
        ans -= 2*(arr[i] && arr[i+1]);
        ans -= 2*(brr[i] && brr[i+1]);
    }
    for(int i = 0; i < n; i += 2) ans -= 2*(arr[i] && brr[i]);
    cout << ans << '\n';
}
