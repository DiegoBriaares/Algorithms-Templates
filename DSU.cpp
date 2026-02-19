#include <iostream>
#include <vector>

namespace DSU 
{

/* All sets must live at stable memory adresses. */
class Set {
public:
  int id;
  int sz;
  Set* rep;

  Set(int id_) : id(id_) {
    sz = 1;
    rep = this;
  }

  Set* Find() {
    if (rep == this) {
      return this;
    }
    rep = rep->Find();
    return rep;
  }

  void Union (Set* S) {
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
};

class Query {
public:
  Set* A;
  Set* B;

  Query(Set* A_, Set* B_) : A(A_), B(B_) {} 


  void Union() {
    A->Union(B);
  }

  bool Same() {
    return A->Find() == B->Find();
  }
};

}


int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  std::vector<DSU::Set> Sets;
  Sets.reserve(n);
  for (int i = 0; i < n; i++) {
    Sets.emplace_back(DSU::Set(i));

  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int QA, QB;
    cin >> QA >> QB;
    DSU::Query Qry(&Sets[QA], &Sets[QB]);
    cout << Qry.Same() << "\n";
    Qry.Union();
  }
}
