
#include <iostream>
#define IZQ (nodo * 2)
#define DER (nodo * 2 + 1)
#define lld long long int
using namespace std;
const int MAXN = 1000002;

int n;
lld C[MAXN], f[MAXN];

struct bit {
    lld left[MAXN];
    lld right[MAXN];

    lld query(int i, int j) {
        lld menor = f[i];
        i++;
        if(i > j) return menor;
        int p;
        for(p = j; p && p - (p&-p) + 1 >= i; p -= p&-p)
            menor = min(menor, left[p]);
        menor = min(menor, f[p]);
        for(p = i; p + (p&-p) - 1 <= j; p += p&-p)
            menor = min(menor, right[p]);
        return menor;
    }

    void update(int p, lld v) {
        if(!p) return;
        int x = p - 1, y = p + 1;
        lld menor = v;
        for(int i = p; i <= n; i += i&-i) {
            while(y < i) {
                menor = min(menor, right[y]);
                y += y & -y;
            }
            if(y == i) menor = min(menor, f[y]);
            while(x > i - (i&-i) + 1) {
                menor = min(menor, left[x]);
                x -= x & -x;
            }
            if(x == i - (i&-i) + 1) menor = min(menor, f[x]);
            left[i] = menor;
        }
        x = p - 1; y = p + 1;
        menor = v;
        for(int i = p; i; i -= i&-i) {
            while(y < i + (i&-i) - 1) {
                menor = min(menor, right[y]);
                y += y & -y;
            }
            if(y == i + (i&-i) - 1) menor = min(menor, f[y]);
            while(x > i) {
                menor = min(menor, left[x]);
                x -= x & -x;
            }
            if(x == i) menor = min(menor, f[x]);
            right[i] = menor;
        }
    }

} BIT;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int k = 1;
    for(int i = 0; i < n; i++) {
        cin >> C[i];
        if(i == (1 << (k + 1))) k++;
        int l = i > 1 ? i - (1 << k) : 0;
        int r = i > 1 ? i - 1 - (1 << (k - 1)) : 0;
        f[i] = C[i] + BIT.query(l, r);
        BIT.update(i, f[i]);
    }
    cout << f[n - 1] << "\n";
    return 0;
}
