#include <iostream>
#include <cstdio>

#include "mygraph.hpp"

#include <cv.h>  
#include <cxcore.h>  
#include <highgui.h> 
#include <cstring> 
#include <cstdio>


const double image_a = 800;
const double image_margin = 100;
const double image_fa = image_a + 2 * image_margin;

double dot_r = 3;
double line_w = 2;

void scale_all(NodeVec &nv) {
    double min_a = INF, max_a = -INF;
    for (int i = 0; i < nv.size(); i++) {
        if (nv[i].p.x > max_a) max_a = nv[i].p.x;
        if (nv[i].p.y > max_a) max_a = nv[i].p.y;
        if (nv[i].p.x < min_a) min_a = nv[i].p.x;
        if (nv[i].p.y < min_a) min_a = nv[i].p.y;
    }
    fprintf(stderr, "%lf %lf\n", min_a, max_a);
    for (int i = 0; i < nv.size(); i++) {
        fprintf(stderr, "before: %lf %lf\n", nv[i].p.x, nv[i].p.y);
        nv[i].p.x = (nv[i].p.x - min_a) * image_a / (max_a - min_a) + image_margin;
        nv[i].p.y = (nv[i].p.y - min_a) * image_a / (max_a - min_a) + image_margin;
        fprintf(stderr, "after: %lf %lf\n", nv[i].p.x, nv[i].p.y);
    }
}

void draw_point(IplImage *img, double x, double y) {
    fprintf(stderr, "drawing: %lf %lf\n", x, y);
    cvCircle(img, cvPoint(x, y), dot_r, CV_RGB(0,255,255), dot_r, 8, 0);
}

void draw_line(IplImage *img, double x1, double y1, double x2, double y2) {
    cvLine(img, cvPoint(x1, y1), cvPoint(x2, y2), CV_RGB(255,255,0), line_w, CV_AA, 0);
}

void paint(char *fn) {
    NodeVec nv;
    AdjList al;
    std::ifstream fin(fn);
    GraphMethods::load(fin, nv, al);
    scale_all(nv);

    if (nv.size() > 50) {
        dot_r = 1;
        line_w = 1;
    }

    IplImage* img = cvCreateImage(cvSize(image_fa, image_fa), IPL_DEPTH_8U, 3);
    for (int i = 0; i < nv.size(); i++) {
        for (IdSet::iterator j = al[i]->begin(); j != al[i]->end(); j++) {
            if (*j < i) {
                draw_line(img, nv[i].p.x, nv[i].p.y, nv[*j].p.x, nv[*j].p.y);
            }
        }
    }

    for (int i = 0; i < nv.size(); i++) {
        draw_point(img, nv[i].p.x, nv[i].p.y);
    }
    char newfn[100];
    strcpy(newfn, fn);
    strcat(newfn, ".jpg");
    cvSaveImage(newfn, img);
    cvShowImage("image", img);
    cvWaitKey(0);
}

int main(int argc, char **argv)
{
    std::cout << "IT'S A VIEWER" << std::endl;
    if (argc == 1) {
        fprintf(stderr, "no such file\n");
    } else {
        paint(argv[1]);
    }
    return 0;
}