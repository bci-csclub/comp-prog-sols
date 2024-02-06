#include <bits/stdc++.h>
using namespace std;

struct Event {
    int type; // -1 - rect start, 0 - point, 1 - rect end
    int x, y1, y2; // y2 is unused when type is 0

    const bool operator<(const Event& e) const {
        // Order by x first and break ties based on type
        // Ties must be broken this way for this problem since being on the edge of a rectangle still counts
        if(x != e.x) return x < e.x;
        return type < e.type;
    }
};

const int MN = 2e5 + 5;
int n, m;
vector<int> yCompr; // sorted list of y values of all points
vector<Event> events;

int ds[MN];

// Increase each value in [l, r) by v
void upd(int l, int r, int v){
    for(int i = l; i < r; i++) ds[i] += v;
}

// Query value at position p
int query(int p){
    return ds[p];
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.push_back({-1, x1, y1, y2});
        events.push_back({1, x2, y1, y2});
    }
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        events.push_back({0, x, y});
        yCompr.push_back(y);
    }

    sort(yCompr.begin(), yCompr.end());
    sort(events.begin(), events.end());

    int ans = 0;
    for(Event e : events){
        auto [type, x, y1, y2] = e;

        if(type == 0){
            y1 = lower_bound(yCompr.begin(), yCompr.end(), y1) - yCompr.begin();
            ans += query(y1) > 0;
        }
        else {
            y1 = lower_bound(yCompr.begin(), yCompr.end(), y1) - yCompr.begin();
            y2 = upper_bound(yCompr.begin(), yCompr.end(), y2) - yCompr.begin();
            if(type == -1) upd(y1, y2, 1);
            else upd(y1, y2, -1);
        }
    }

    cout << ans << '\n';
}
