#include "mygraph.hpp"
#include "enp.hpp"
#include "mst.hpp"
#include "random_points.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>

#define BASELINE_OPEN

int main(int argc, char **argv) {

    if (argc < 2) {
        return 0;
    }

    NodeVec nv;
    AdjList al;
    EnpSolver *es = new BruteForceEnpSolver();
    AdjList &res = al;

    std::ifstream fin(argv[1]);
    GraphMethods::load(fin, nv, al);
    al.clear();

#ifdef BASELINE_OPEN

    for (int i = 0; i < nv.size(); i++) {
        al.push_back(new IdSet);
    }

    for (int i = 0; i < nv.size(); i++)
        for (int j = 0; j < nv.size(); j++) 
            if (i != j) 
                GraphMethods::add_edge(al, nv[i], nv[j]);

    MSTSolver *ms2 = new MSTSolver();
    ms2->solve(nv, al);

    res = ms2->res;
    std::cout << "EMST baseline:" << std::endl;
    std::cout << ms2->ans << std::endl;
    // std::ofstream f2("emst.baseline.out");
    // std::ofstream f22("graph.baseline.txt");
    // GraphMethods::print(f2, nv, res);
    // GraphMethods::print(f22, nv, al);

    al.clear();

#endif

    for (int i = 0; i < nv.size(); i++) {
        al.push_back(new IdSet);
    }

    es->solve(nv, al);
    std::ofstream f11("graph.output.out");
    GraphMethods::print(f11, nv, al);

    MSTSolver *ms = new MSTSolver();
    ms->solve(nv, al);

    res = ms->res;
    std::cout << "EMST answer:" << std::endl;
    std::cout << ms->ans << std::endl;
    std::ofstream f1("emst.output.out");
    GraphMethods::print(f1, nv, res);

    nv.clear();
    al.clear();


    return 0;
}