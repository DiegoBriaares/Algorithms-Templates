#include <iostream>

#include <vector>



using namespace std;



class node {

public:

node* P, *C[2];

  int flip;

  node* pp;

long long data, stv;//data of node, subtree value

int id;



  node(){

cout << "Llama" << endl;

data = flip = stv = 0;

P = pp = C[0] = C[1] = NULL;

  }



inline long long query(long long v1, long long v2){ return v1 + v2; }



  inline void fix() {

stv = data;

    if(C[0]) {stv = query(stv, C[0]->stv); C[0]->P = this;}

    if(C[1]) {stv = query(stv, C[1]->stv); C[1]->P = this;}

  }



  inline void push_flip() {

    if(!flip) return;

    flip = 0;

    swap(C[0], C[1]);

    if(C[0]) C[0]->flip ^= 1;

    if(C[1]) C[1]->flip ^= 1;

  }



  inline int up() {

    return !P ? -1 : (P->C[0] == this ? 0 : 1);

  }



  inline void zig(int c) {

    node* X = C[c];

    if(X->P = P) P->C[up()] = X;

    C[c] = X->C[1 - c];

    X->C[1 - c] = this;

    fix();

X->fix();

    if(P) P->fix();

    swap(pp, X->pp);

  }



  inline void zigzig(int c) {

    node* X = C[c];

    node* Y = X->C[c];

    if(Y->P = P) P->C[up()] = Y;

    C[c] = X->C[1 - c];

    X->C[c] = Y->C[1 - c];

    Y->C[1 - c] = X;

    X->C[1 - c] = this;

    fix();

X->fix();

Y->fix();

    if(P) P->fix();

    swap(pp, Y->pp);

  }



  inline void zigzag(int c) {

    node* X = C[c];

    node* Y = X->C[1 - c];

    if(Y->P = P) P->C[up()] = Y;

    C[c] = Y->C[1 - c];

    X->C[1 - c] = Y->C[c];

    Y->C[1 - c] = this;

    Y->C[c] = X;

    fix();

X->fix();

Y->fix();

    if(P) P->fix();

    swap(pp, Y->pp);

  }



  inline node* splay() {

    for(push_flip(); P; ) {

      if(P->P) P->P->push_flip();

      P->push_flip();

      push_flip();



      int c1 = up();

      int c2 = P->up();

      if(c2 == -1) {

        P->zig(c1);

      } else if(c1 == c2) {

        P->P->zigzig(c1);

      } else {

        P->P->zigzag(c2);

      }

    }

    return this;

  }

};



struct LinkCutTree {

vector<node> nodes;

LinkCutTree(int N, long long *values = NULL) {

node n1;

nodes.insert(nodes.begin(), N, n1);

nodes = new node[N];

if (values != NULL){

for (int i = 0; i < N; i++){

nodes[i].data = values[i];

nodes[i].fix();

}

}

for (int i = 0; i < N; i++){

nodes[i].id = i;

}

}



inline void link(int u, int v) {//v se hace hijo de u

makeRoot(v);

 nodes[v].pp = &nodes[u];

}



inline void cut(int u, int v = -1) {

if (v != -1)

 makeRoot(v);

access(u);

   	nodes[u].C[0]->P = NULL;

   	nodes[u].C[0] = NULL;

   	nodes[u].fix();

}



inline int getRoot(int id){

access(id);

node *t = &nodes[id];

while(t->C[0]) t = t->C[0];

t->splay();

return t->id;

}



/* Move u to root of represented tree. */

inline void makeRoot(int u) {

access(u);

nodes[u].splay();//Creo que este splay no hace falta

if(nodes[u].C[0]) {

cout << "Lo pasa al hijo!" << endl;

nodes[u].C[0]->P = NULL;

nodes[u].C[0]->flip ^= 1;

nodes[u].C[0]->pp = &nodes[u];

nodes[u].C[0] = NULL;

nodes[u].fix();

}

}



/* Move u to root aux tree.  Return the root of the root aux tree. */

inline node* access(int u) {

cout << "Accede al " << u << endl;

  node *x,*pp,*last;

last = &nodes[u];

x = nodes[u].splay();

if(x->C[1]){

x->C[1]->pp = x;

x->C[1]->P = NULL;

x->C[1] = NULL;

x->fix();

}



  for(; x->pp;) {

cout << "Entra" << endl;

last = x->pp;

    pp = x->pp->splay();

    x->pp = NULL;

    if(pp->C[1]) {

     	pp->C[1]->P = NULL;

      pp->C[1]->pp = pp;

    }

    pp->C[1] = x;

    pp->fix();

nodes[u].splay();

  }

cout << "x es: " << x->id << endl;

if (x->C[0]){

cout << "El hijo de " << x->id << " es " << x->C[0]->id << endl;

}

  return last;

}





inline long long pathAggregate(int u){

access(u);

return nodes[u].stv;

}



inline long long pathAggregate(int u, int v){

makeRoot(u);

return pathAggregate(v);

}



inline int lca(int u, int v){

access(u);

return access(v)->id;

}



};
