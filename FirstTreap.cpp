/**
 
   * author:    Diego Briaares
   * At:   19.07.2022 21:13:39
**/
 
#include <bits/stdc++.h>
using namespace std;
 
   //Randal

	void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef struct treap {
	treap* left;
	treap* right;
	int v, key, size;
}treap;
 
 
const int TREAP_MAX_NODES = 5 * 1e5;
treap nodes[4 * TREAP_MAX_NODES];
int treap_nodes;
 
int size(treap* T) {
	if (T == NULL) return 0;
	else return T->size;
}
 
void UpdateSize(treap* T) {
	if (T == NULL) return;
	else T->size = size(T->left) + size(T->right) + 1;
}
 
treap* Merge(treap* A, treap* B) {	
	if (A == NULL) return B;
	if (B == NULL) return A;
	treap* result = NULL;

	if (A->key > B->key) {
		result = A;
		result->right = Merge(A->right, B);
	}
	else {
		result = B;
		result->left = Merge(A, B->left);
	}
	UpdateSize(result);
	return result;
}  
 
pair<treap*, treap*> Split(treap* T, int K) {
	if (T == NULL) {
		UpdateSize(T);
		return make_pair(T, T);
	}
	treap* TT = T;
	pair<treap*, treap*> S, result;
	if (T->v <= K) {
		S = Split(T->right, K);
		TT->right = NULL;	
		result.first = Merge(TT, S.first);
		result.second = S.second;
	}
	else {
		S = Split(T->left, K);
		TT->left = NULL;
		result.first = S.first;
		result.second = Merge(S.second, TT);
	}
	UpdateSize(result.first);
	UpdateSize(result.second);
	return result;
}
 
treap* insert(treap* T, int v) {
	treap* node = &nodes[treap_nodes++];
	node->size = 1;
	node->left = NULL;
	node->right = NULL;
	node->v = v;
	node->key = uniform_int_distribution<int>(0, 1000000)(rng);
	pair<treap*, treap*> S = Split(T, v);
	S.first = Merge(S.first, node);
	S.second = Merge(S.first, S.second);
	return S.second;
}

treap* erase(treap* T, int v) {
	pair<treap*, treap*> S = Split(T, v);
	pair<treap*, treap*> NS = Split(S.first, v - 1);
	S.second = Merge(NS.first, S.second);
	return S.second;
}
 
 
bool Find(treap* T, int v) {
	if (T == NULL) return false;
	if (T->v == v) return true;
  else if (T->v > v) {
  	return Find(T->left, v);
  }
  else {
  	return Find(T->right, v);
  }
}
 
treap* Kth(treap* T, int K) {
	if (T == NULL) return T;
	if (K == size(T->left) + 1) return T;
	else if (K > size(T->left) + 1) return Kth(T->right, K - size(T->left) - 1);
	else return Kth(T->left, K);
}
 
 
	int main () {
	
	}