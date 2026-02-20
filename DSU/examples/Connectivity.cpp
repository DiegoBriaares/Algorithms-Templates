#include <iostream>
#include <vector>
#include <utility>
#include <DSU.hpp>

int main () {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  int N, Q;
  std::cin >> N;
  std::cin >> Q;

  std::vector<std::pair<int, int>> edges;
  edges.reserve(Q);
  for (int i = 0; i < Q; i++) {
    int QA, QB;
    std::cin >> QA >> QB;
    QA--, QB--;
    edges.emplace_back(QA, QB);
  }

  std::vector<bool> ConnectivityT = DSU::Connectivity(N, Q, edges);
  for (int i = 0; i < Q; i++) {
    std::cout << ConnectivityT[i] << "\n";
  }
}
