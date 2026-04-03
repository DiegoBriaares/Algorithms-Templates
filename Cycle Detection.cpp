#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define MAXN 1000001

int N;
vector<pair<int, int>> edg[MAXN];
vector<vector<int>> cycles;

vector<int> cycle;
bool vis[MAXN];
bool cycled[MAXN];
int stack[MAXN];
int p;

void Find(int node, int last) {
  if (vis[node]) {
    if (cycled[node]) {
      return;
    }
    int pp = p;
    while (true) {
      cycle.push_back(stack[pp]);
      cycled[stack[pp]] = true;
      if (stack[pp] == node) {
        break;
      }
      pp--;
    }
    return;
  }
  vis[node] = true;
  stack[++p] = node;
  for (auto nxt : edg[node]) {
    if (nxt.first == last) continue;
    Find(nxt.first, node);
  }
  p--;
}

  int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // In this example, each node has exactly one non-directed edge.
    cin >> N;
    for (int u = 0; u < N; u++) {
      int v, cost;
      cin >> v >> cost;
      v--;
      edg[u].push_back(make_pair(v, cost));
      edg[v].push_back(make_pair(u, cost));
    }

    for (int i = 0; i < N; i++) {
      if (vis[i]) continue;
      cycle.clear();
      p = 0;
      Find(i, -1);
      cycles.push_back(cycle);
    }

    cout << "Last recorded cycle\n";
    for (int i = 0; i < (int) cycle.size(); i++) {
      cout << cycle[i] + 1 << "\n";
    }
  }


  /* 
  12
  3 1
  3 1
  4 1
  5 1
  7 1
  4 1
  6 1
  7 1
  8 1
  8 1
  10 1
  10 1
  */
