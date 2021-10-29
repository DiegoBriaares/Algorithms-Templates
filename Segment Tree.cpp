/**

   * Made by:    Diego Briaares
   * At:   29.10.2021 15:20:06
**/

#include <bits/stdc++.h>
using namespace std;


void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

const int INF = (int) 1e9;

const int MAX = (int) 1e5;

int A[MAX];

int ST[4 * MAX];

void build(int l, int r, int node) {
	if (l == r) {
		ST[node] = A[l];
		return;
	}
	if (l > r) return;
	int mid = (l + r) / 2;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	build(l, mid, left);
	build(mid + 1, r, right);
	ST[node] = min(ST[left], ST[right]);
}

void update(int l, int r, int node, int i, int v) {
	if (l > r || l > i || r < i) return;
	if (i <= l && r <= i) {
		ST[node] = v;
		return;
	}
	int mid = (l + r) / 2;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	update(l, mid, left, i, v);
	update(mid + 1, r, right, i, v);
	ST[node] = min(ST[left], ST[right]);
}

int query(int l, int r, int node, int ql, int qr) {
	if (l > r || l > qr || r < ql) return INF;
	if (ql <= l && r <= qr) return ST[node];
	int mid = (l + r) / 2;
	int left = node * 2 + 1;
	int right = node * 2 + 2;
	return min(query(l, mid, left, ql, qr), query(mid + 1, r, right, ql, qr));
}

	int main () {
		optimize();
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n; i++) cin >> A[i];
		build(0, n - 1, 0);
		while (q--) {
			int op, a, b;
			cin >> op >> a >> b;
			a--;
			if (op == 1){
				update(0, n - 1, 0, a, b);
			}
			else {
				b--;
				cout << query(0, n - 1, 0, a, b) << "\n";
			}
		}
	}