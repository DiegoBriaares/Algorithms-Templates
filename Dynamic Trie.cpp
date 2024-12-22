/**

   * author:    Diego Briaares
   * At:   21.12.2024 22:59:02
**/

#include <bits/stdc++.h>
using namespace std;

void optimize() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

class Trie {
public:
	int trie_size;
	int node_cnt;
	struct trie_node {
	  // instead of fixing 26 sons, we can do some mapping idea to mantain memory for just the existing nodes.
		trie_node *son[26];
		bool end_word;
		int cnt;
	};

	trie_node *root;

	trie_node* New_node() {
		trie_node *node = new trie_node();
		node->end_word = false;
		node->cnt = 0;
		return node;		
	}

	Trie() {
		node_cnt = trie_size = 0;
		root = New_node();
	}

	void delete_trie(trie_node *node) {
		for (int i = 0; i < 26; i++) {
			if (node->son[i]) {
				delete_trie(node->son[i]);
			}
		}
		delete node;
	}

	~Trie() {
		delete_trie(root);
	}

	trie_node* add_node(trie_node *node, int buck) {
		node->son[buck] = New_node();
		return node->son[buck];
	}

	void insert_word(string w) {
		trie_node *node = root;
		int n = (int) w.size();
		for (int i = 0; i < n; i++) {
			int l = w[i] - 'a';
			if (!node->son[l]) {
				node = add_node(node, l);
			}
			else {
				node = node->son[l];
			}
			node->cnt++;
		}
		node->end_word = true;
	}

	int search_word(string w) {
		trie_node *node = root;
		int n = (int) w.size();
		for (int i = 0; i < n; i++) {
			int l = w[i] - 'a';
			if (!node->son[l]) {
				return false;
			}
			else {
				node = node->son[l];
			}
		}
		return node->cnt;
	}
};

Trie trie;

	int main () {
		optimize();
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
		  string w;
		  cin >> w;
		  trie.insert_word(w);
		}

		int m;
		cin >> m;
		for (int i = 0; i < m; i++) {
		  string w;
		  cin >> w;
		  cout << trie.search_word(w) << "\n";
		}

		


	}