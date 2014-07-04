#ifndef OOP1_MYGRAPH_HPP
#define OOP1_MYGRAPH_HPP

#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>

#include "mymath.hpp"

struct Point2D {
    Point2D(double _x, double _y) : x(_x), y(_y) {}
    double x, y;

    inline void transform(double a11, double a12, double a21, double a22) {
        double nx = x * a11 + y * a12;
        double ny = x * a21 + y * a22;
        x = nx;
        y = ny;
    }
    inline Point2D copy_transfrom(double a11, double a12, double a21, double a22) {
        return Point2D(x * a11 + y * a12, x * a21 + y * a22);
    }
};

struct Node {
    const int id;
    Point2D p;
    Node(int _id, double _x, double _y): id(_id), p(_x, _y) {}
};

typedef std::vector< Node > NodeVec;
typedef NodeVec::iterator NodeItr;
typedef std::vector< Point2D > Point2DVec;
typedef Point2DVec::iterator Point2DItr;

typedef std::set< int > IdSet;
typedef std::vector< IdSet* > AdjList;

// Geometry utils

inline double dist2(const Point2D &a, const Point2D &b) {
    return sqr(a.x - b.x) + sqr(a.y - b.y);
}

inline double dist2(const Node &a, const Node &b) {
    return sqr(a.p.x - b.p.x) + sqr(a.p.y - b.p.y);
}

inline double dist(const Point2D &a, const Point2D &b) {
    double k = dist2(a, b);
    if (eq(k, 0)) return 0;
    return sqrt(k);
}

inline double dist(const Node &a, const Node &b) {
    double k = dist2(a, b);
    if (eq(k, 0)) return 0;
    return sqrt(k);
}

// Graph utils

namespace GraphMethods {

inline void add_edge(const AdjList &al, const Node &a, const Node &b) {
    al[a.id]->insert(b.id);
}

inline void print(std::ostream& fout, NodeVec &nv, AdjList &res) {

    fout << nv.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        fout << i << ' ' << nv[i].p.x << ' ' << nv[i].p.y << '\n';
    }
    for (int i = 0; i < res.size(); i++) {
        fout << res[i]->size() << ' ';
        for (IdSet::iterator j = res[i]->begin(); j != res[i]->end(); j++) {
                fout << *j << ' ';
            }
        fout << '\n';
    }

}

inline void load(std::istream& fin, NodeVec &nv, AdjList &al) {

    nv.clear();
    al.clear();

    int n;
    fin >> n;

    for (int i = 0; i < n; i++) {
        int id;
        double x, y;
        fin >> id >> x >> y;
        nv.push_back(Node(id, x, y));
        al.push_back(new IdSet);
    }
    char tmp[100];
    for (int i = 0; i < n; i++) {
        int j, k;
        fin >> k;
        while(k--) {
            fin >> j;
            add_edge(al, nv[i], nv[j]);
        }
    }
}

}

#endif