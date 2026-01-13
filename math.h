#ifndef math_h
#define math_h
struct Point;

double racine(double S);
double valeurAbs(double V);
double distanceEuclidienne(Point *p1, Point *p2, int dim);
double distanceManhattan(Point *p1, Point *p2, int dim);
double distanceCosinus(Point *p1, Point *p2, int dim);

#endif