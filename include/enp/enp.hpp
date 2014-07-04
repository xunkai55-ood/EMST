#ifndef OOP1_ENP_ENP_HPP
#define OOP1_ENP_ENP_HPP

#include "../mygraph.hpp"

class EnpSolver {

public:
    EnpSolver() {}
    virtual ~EnpSolver() {}
    virtual void solve(NodeVec &v, AdjList &al) {}
};

#endif