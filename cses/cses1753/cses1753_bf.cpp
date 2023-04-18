#include <iostream>
#include <string>
using namespace std;

int n, m;
string s1, s2;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();

    int ans = 0;
    for(int i = 0; i <= n-m; i++){
        bool good = true;
        for(int j = 0; j < m; j++){
            if(s1[i+j] != s2[j]){
                good = false;
                break;
            }
        }
        ans += good;
    }
    cout << ans << '\n';
}
