/**

   * author:    Diego Briaares
   * At:   25.07.2022 01:53:09
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

// Randal

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Multiset Treap(cnt = 1), 
	//Insert(v) if v not in Treap already
	// Upd(v) otherwise
struct node {
	node* L;
	node* R;
	int key, pry;
	int sz;
	int cnt;
};

const int MAXNODES = 100002;
node treap[MAXNODES];
int nodes;

int size(node* T) {
	if (T == NULL) {
		return 0;
	}
	return T->sz;
}

void Merge(node* &T, node* A, node* B) {
	if (A == NULL) {
		T = B;
		return;
	}
	if (B == NULL) {
		T = A;
		return;
	}

	if (A->pry >= B->pry) {
		Merge(A->R, A->R, B);
		T = A;
	}
	else {
		Merge(B->L, A, B->L);
		T = B;
	}
	T->sz = (size(T->L) + size(T->R) + T->cnt);
	return;
}

void Split(node* T, int k, node* &A, node* &B) {
	if (T == NULL) {
		A = B = NULL;
		return;
	}
	if (T->key > k) {
		Split(T->L, k, A, T->L);
		B = T;
		B->sz = (size(B->L) + size(B->R) + B->cnt);
	}
	else {
		Split(T->R, k, T->R, B);
		A = T;
		A->sz = (size(A->L) + size(A->R) + A->cnt);
	}
	return;
}

node* new_node(int v = 0) {
	if (nodes >= MAXNODES) {
		cout << "NEL PASTEL (muchos nodos)\n";
		return NULL;
	}
	node* NewT = &treap[nodes++];
	NewT->sz = 1;
	NewT->cnt = 1;
	NewT->L = NULL;
	NewT->R = NULL;
	NewT->key = v;
	NewT->pry = uniform_int_distribution<int>(0, MAXNODES * 10)(rng);
	return NewT; 
}

bool Find(node* T, int v) {
	if (T == NULL) {
		return false;
	}
	else if (T->key == v) {
		return true;
	}
	else if (T->key < v) {
		return Find(T->R, v);
	}
	else {
		return Find(T->L, v);
	}
}

/* - */
vector<int> inorder(node* T) {
	if (T == NULL) {
		return vector<int>();
	}
	vector<int> order;
	vector<int> L = inorder(T->L);
	order.insert(order.end(), L.begin(), L.end());
	order.push_back(T->key);
	vector<int> R = inorder(T->R);
	order.insert(order.end(), R.begin(), R.end());
	return order;
} /* -- */


// No debe haber un v
void Insert(node* &T, int v = 0) {
	node* T1;
	node* T2;
	Split(T, v, T1, T2);
	Merge(T1, T1, new_node(v));
	Merge(T, T1, T2);
	return;
}


// Debe haber un v 
void Erase(node* &T, int v) {
	node* T1;
	node* T2;
	node* T3;
	Split(T, v, T1, T2);
	Split(T1, v - 1, T1, T3);
	Merge(T, T1, T2);
	return;
}


// Debe haber un k-esimo elemento
int OrdK(node* &T, int k) {
	if (T == NULL) {
		return 420;
	}
	if (size(T->L) < k && size(T->L) + T->cnt >= k) {
		return T->key;
	}
	if (size(T->L) + T->cnt < k) {
		return OrdK(T->R, k - size(T->L) - T->cnt);
	}
	else {
		return OrdK(T->L, k);
	}
}

int Count(node* &T, int x) {
	if (T == NULL) {
		return 0;
	}
	node* T1;
	node* T2;
	Split(T, x, T1, T2);
	int amt = size(T1);
	Merge(T, T1, T2);
	return amt;
}

// Si ya v esta en el Treap puedes "meterlo" por aqui
void Upd(node* &T, int v) {
	if (T == NULL) {
		return;
	}
	if (T->key == v) {
		T->cnt++;
	}
	else if (T->key < v) {
		Upd(T->R, v);
	}
	else {
		Upd(T->L, v);
	}
	T->sz = size(T->L) + size(T->R) + T->cnt;
}

	int main () {
		optimize();
		
	}