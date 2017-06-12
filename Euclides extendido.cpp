#include <bits/stdc++.h>
#define lld long long int
using namespace std;

lld gcd(lld a, lld b, lld &x, lld &y) {
    if(!b) {
        x = 1; y = 0;
        return a;
    } else {
        lld d = gcd(b, a % b, x, y);
        lld newX = y, newY = x - y * (a / b);
        x = newX;
        y = newY;
        return d;
    }
}

lld t(lld a, lld b, lld M, lld &brincos) {
    lld x, y;
    lld d = __gcd(a, M);
    if(b % d) return -1;
    a /= d; b /= d; M /= d;
    d = gcd(a, M, x, y);
    x *= b; y *= b;
    if(x < 0) {
        lld k = -x;
        x += k * M / d;
        y -= k * a / d;
    }
    brincos = M / d;
    return x % M;
}

lld x, y, n, m, Q;

bool solution(lld px, lld py) {
    lld k1, k2;
    lld t1 = t(x, px, 2 * n, k1);
    lld t2 = t(y, py, 2 * m, k2);
    if(t1 == -1 || t2 == -1) return false;
    if(abs(t1 - t2) % __gcd(k1, k2)) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> x >> y >> Q;
    int c = 0;
    for(int i = 1; i <= Q; i++) {
        lld px, py;
        cin >> px >> py;
        if(solution(px, py) || solution(2*n - px - 1, py) || solution(px, 2*m - py - 1) || solution(2*n - px - 1, 2*m - py - 1)) c++;
    }
    cout << c << "\n";
    return 0;
}
