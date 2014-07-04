#include "enp/brute_force_enp.hpp"

int BruteForceEnpSolver::neighbor_label(Point2D &p, Point2D &q) {
    // 1 2 3 4 5 6 7 8
    double dx = q.x - p.x, dy = q.y - p.y;
    if (eq(dx, 0)) {
        if (le(dy, 0)) {
            return 7;
        } else {
            return 3;
        }
    } else if (gt(dx, 0)) {
        if (ge(dy, dx)) {
            return 2;
        } else if (ge(dy, 0)) {
            return 1;
        } else if (ge(dy, -dx)) {
            return 8;
        } else {
            return 7;
        }
    } else {
        if (gt(dy, -dx)) {
            return 3;
        } else if (gt(dy, 0)) {
            return 4;
        } else if (gt(dy, dx)) {
            return 5;
        } else {
            return 6;
        }
    }
}

void BruteForceEnpSolver::solve(NodeVec &nv, AdjList &al) {
    for (NodeItr v = nv.begin(); v != nv.end(); v++) {
        double dis[8] = {INF, INF, INF, INF, INF, INF, INF, INF};
        Node* closest[8];
        for (NodeItr u = nv.begin(); u != nv.end(); u++) {
            if (u == v) continue;
            double uvd = dist(*v, *u);
            int k = neighbor_label(v->p, u->p);
            if (uvd < dis[k]) {
                dis[k] = uvd;
                closest[k] = &(*u);
            }
        }
        for (int i = 0; i < 8; i++)
            if (lt(dis[i], INF)) { // add edge
                GraphMethods::add_edge(al, *v, *(closest[i]));
                GraphMethods::add_edge(al, *(closest[i]), *v);
            }
    }
}