#include "mygraph.hpp"
#include "enp.hpp"
#include "mst.hpp"
#include "random_points.hpp"

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char **argv) {

    if (argc < 3) {
        return 0;
    }

    int n = atoi(argv[1]);
    int range = atoi(argv[2]);

    RandomPoints rp;
    rp.generate(n, range);

    NodeVec nv;
    AdjList al;
 
    for (int i = 0; i < rp.pv.size(); i++) {
        nv.push_back(Node(i, rp.pv[i].x, rp.pv[i].y));
        al.push_back(new IdSet);
    }

    std::ofstream f("graph.in");
    GraphMethods::print(f, nv, al);

    return 0;
}