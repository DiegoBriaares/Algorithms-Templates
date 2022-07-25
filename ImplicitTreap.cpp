/**

   * author:    Diego Briaares
   * At:   25.07.2022 01:56:53
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

 // Randal..

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
	node* L;
	node* R;
	int key, pry;
	int sz;
	int swp;
	int id;
};

const int MAXNODES = 1000002;
node treap[MAXNODES];
int nodes;

int size(node* T) {
	if (T == NULL) {
		return 0;
	}
	return T->sz;
}

void Push(node* &T) {
	swap(T->L, T->R);
	if (T->L) {
		T->L->swp ^= 1;
	}
	if (T->R) {
		T->R->swp ^= 1;
	}
	T->swp = 0;
}

void Merge(node* &T, node* A, node* B) {
	if (T && T->swp) {
		Push(T);
	}	
	if (A == NULL) {
		T = B;
		return;
	}
	if (B == NULL) {
		T = A;
		return;
	}
	if (A->swp) {
		Push(A);
	}
	if (B->swp) {
		Push(B);
	}

	if (A->pry >= B->pry) {
		Merge(A->R, A->R, B);
		T = A;
	}
	else {
		Merge(B->L, A, B->L);
		T = B;
	}
	T->sz = (size(T->L) + size(T->R) + 1);
	return;
}

void Split(node* T, int k, node* &A, node* &B) {
	if (T == NULL) {
		A = B = NULL;
		return;
	}
	if (T->swp) {
		Push(T);
	}
	T->key = size(T->L) + 1;
	if (T->key > k) {
		Split(T->L, k, A, T->L);
		B = T;
		B->sz = (size(B->L) + size(B->R) + 1);
	}
	else {
		Split(T->R, k - T->key, T->R, B);
		A = T;
		A->sz = (size(A->L) + size(A->R) + 1);
	}
}

node* new_node(int v = 0) {
	if (nodes >= MAXNODES) {
		cout << "NEL PASTEL (muchos nodos)\n";
		return NULL;
	}
	node* NewT = &treap[nodes++];
	NewT->sz = 1;
	NewT->swp = 0;
	NewT->id = v;
	NewT->L = NULL;
	NewT->R = NULL;
	NewT->pry = uniform_int_distribution<int>(0, MAXNODES * 10)(rng);
	return NewT; 
}

vector<int> inorder(node* T) {
	if (T == NULL) {
		return vector<int>();
	}
	if (T->swp) {
		Push(T);
	}
	vector<int> order;
	vector<int> L = inorder(T->L);
	order.insert(order.end(), L.begin(), L.end());
	order.push_back(T->id);
	vector<int> R = inorder(T->R);
	order.insert(order.end(), R.begin(), R.end());
	return order;
}


	int main () {
		optimize();
		
	}