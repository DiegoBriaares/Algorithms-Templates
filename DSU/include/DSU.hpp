#ifndef DSU_HPP
#define DSU_HPP

#include <vector>
#include <utility>

namespace DSU 
{

/* All sets must live at stable memory adresses. */
class Set {
public:
  int id;
  int sz;

  explicit Set(int id_);
  Set* Find();
  void Union (Set* S);

private:
  Set* rep;
};

class Query {
public:

  explicit Query(Set* A_, Set* B_);
  void Union();
  bool Same();

private:
  Set* A;
  Set* B;
};

std::vector<bool> Connectivity (int n, int Q, const std::vector<std::pair<int, int>>& edges);
}

#endif


