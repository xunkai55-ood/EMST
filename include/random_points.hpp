#ifndef OOP1_RANDOM_POINTS_HPP
#define OOP1_RANDOM_POINTS_HPP

#include <cstdlib>
#include "mygraph.hpp"

class RandomPoints {
public:
    RandomPoints() {
        srand(time(0));
        pv.clear();
        xr[0] = rand();
        xr[1] = rand();
        xr[2] = rand();
    }
    ~RandomPoints() {
        pv.clear();
    }
    void generate(int n, int radius = 10000) {
        while (n) {
            double x = (2 * rand_real() - 1) * radius;
            double y = (2 * rand_real() - 1) * radius;
            int flag = 0;
            for (int i = 0; i < pv.size(); i++)
                if (eq(pv[i].x, x) && eq(pv[i].y, y)) {
                    flag = 1;
                    break;
                }
            if (flag) continue;
            n--;
            pv.push_back(Point2D(x, y));
        }
    }

    Point2DVec pv;

private:
    unsigned short xr[3];
    double rand_real() {
        return erand48(xr);
    }
};

#endif