#ifndef knn_h
#define knn_h

struct Point{
    double *p;
    int label;
    Point *suiv;
};

struct Voisin{
    Point *vois;
    double dist;
    Voisin *suiv;
};
struct lCount{
    int label;
    int nb;
    lCount *suiv;
};
void normalMinMax(Point *p1, Point *p2, Point *max, Point *min, int dim);
void normalVec(Point *p, int dim);
Voisin *addVois(Point *p, Voisin *v, double dist);
void minMax(Point *P, Point *min, Point *max, int dim);
int nblabel(Voisin *v, int k);
void detruireVoisins(Voisin *v);
int knnEuclidien(Point *p, Voisin *vois, Point *test, int dim, int k );
int knnManhattan(Point *p, Voisin *vois, Point *test, int dim, int k );
int knnCosinus(Point *p, Voisin *vois, Point *test, int dim, int k );


#endif