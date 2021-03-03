bool cmp(point a, point b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

void convex_hull(vector <point>& a) {
    if (a.size() == 1) return;
    sort(a.begin(), a.end(), &cmp);
    point p1 = a.front(), p2 = a.back();
    vector <point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    int sz = a.size();
    for (int i = 1; i < sz; ++i) {
        int szu = up.size(), szd = down.size();
        if (i == sz - 1 || clockwise(p1, a[i], p2)) {
            while (up.size() >= 2 && !clockwise(up[szu - 2], up[szu - 1], a[i])) up.pop_back();
            up.push_back(a[i]);
        }
        if (i == sz - 1 || counter_clockwise(p1, a[i], p2)) {
            while (down.size() >= 2 && !counter_clockwise(down[szd - 2], down[szd - 1], a[i])) down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); ++i) a.push_back(up[i]);
    for (int i = (int)down.size() - 2; i; --i) a.push_back(up[i]);
}
