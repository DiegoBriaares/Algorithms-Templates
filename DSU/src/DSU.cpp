#include "DSU.hpp"

#include <deque>

namespace DSU 
{

 Set::Set(int id_) : id(id_), sz(1), rep(this) {}

 Set* Set::Find() {
   if (rep == this) {
     return this;
   }
   rep = rep->Find();
   return rep;
 }

void Set::Union (Set* S) {
  Set* A = this->Find();
  Set* B = S->Find();
  if (A == B) {
    return;
  }

  if (A->sz < B->sz) {
    A->rep = B;
    B->sz += A->sz;
  }
  else {
    B->rep = A;
    A->sz += B->sz;
  }
}

Query::Query(Set* A_, Set* B_) : A(A_), B(B_) {} 

void Query::Union() {
  A->Union(B);
}

bool Query::Same() {
  return A->Find() == B->Find();
}

std::vector<bool> Connectivity (int N, int Q, const std::vector<std::pair<int, int>>& edges) {
  std::deque<Set> Sets;
  for (int i = 0; i < N; i++) {
    Sets.emplace_back(i);

  }
  std::vector<bool> ans;
  ans.reserve(Q);
  for (int i = 0; i < Q; i++) {
    int QA = edges[i].first;
    int QB = edges[i].second;
    DSU::Query Qry(&Sets[QA], &Sets[QB]);
    ans.push_back(Qry.Same());
    Qry.Union();
  }
  return ans;
}

}
