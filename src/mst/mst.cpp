#include "mst/mst.hpp"

AdjList& MSTSolver::solve(NodeVec &nv, AdjList &al) {
    ans = 0;
    res.clear();

    int u = 0, n = nv.size();
    double *d = new double[nv.size()];
    bool *f = new bool[nv.size()];
    int *back = new int[nv.size()];
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        f[i] = false;
        back[i] = -1;
        res.push_back(new IdSet);
    }
    d[u] = 0, f[u] = true, back[u] = -1;

    for (int i = 0; i < n - 1; i++) {
        for (IdSet::iterator j = al[u]->begin(); j != al[u]->end(); j++) {
            int v = *j;
            if (f[v]) continue;
            double duv = dist(nv[u], nv[v]);
            if (d[v] > duv) {
                d[v] = duv;
                back[v] = u;
            }
        }
        double mind = INF;
        // fprintf(stderr, "%lf\n", mind);
        for (int v = 0; v < n - 1; v++) {
            // fprintf(stderr, "%d\n", v);
            if (f[v]) continue;
            if (d[v] < mind) {
                mind = d[v];
                u = v;
            }
        }
        // fprintf(stderr, "%d\n", u);
        f[u] = true;
    }

    for (int i = 0; i < n; i++) {
        if (back[i] >= 0) {
            GraphMethods::add_edge(res, nv[i], nv[back[i]]);
            GraphMethods::add_edge(res, nv[back[i]], nv[i]);
            ans += dist(nv[i], nv[back[i]]);
        }
    }

    delete d;
    delete f;
    delete back;

    return res;
}