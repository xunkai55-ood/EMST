#ifndef OOP1_MST_MST_HPP
#define OOP1_MST_MST_HPP

#include "../mygraph.hpp"
#include <cstdio>

class MSTSolver {
    // Default: Prim algo
public:
    MSTSolver() {}
    ~MSTSolver() {
        res.clear();
    }

    virtual AdjList& solve(NodeVec &nv, AdjList &al);
    IdSet *id_set_list;
    AdjList res;
    double ans;

};

#endif