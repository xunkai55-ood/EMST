#ifndef OOP1_ENP_BRUTE_FORCE_ENP_HPP
#define OOP1_ENP_BRUTE_FORCE_ENP_HPP

#include "enp.hpp"

class BruteForceEnpSolver : public EnpSolver {

public:
    BruteForceEnpSolver() : EnpSolver() {}
    void solve(NodeVec &v, AdjList &al);

private:
    int neighbor_label(Point2D &p, Point2D &q);
};

#endif