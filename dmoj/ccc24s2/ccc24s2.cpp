#include <bits/stdc++.h>
using namespace std;

const int MZ = 128;
int t, n;
string str;
int freq[MZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> t >> n;
    while(t--){
        cin >> str;
        memset(freq, 0, sizeof(freq));
        for(char ch : str) freq[ch]++;
        vector<bool> vec(n);
        for(int i = 0; i < n; i++) vec[i] = freq[str[i]] > 1;
        bool good = true;
        for(int i = 0; i < n-1; i++) good &= vec[i] != vec[i+1];
        cout << (good ? "T\n" : "F\n");
    }
}
