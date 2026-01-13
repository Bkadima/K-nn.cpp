#include <iostream>
#include "knn.h"

using namespace std;

double valeurAbs(double V){
    if(V < 0) return -1 * V;
    return V;
}

double racine(double S){
    if (S == 0) return 0;
    if (S < 0) return -1;

    double epsilon = 1e-7; 
    double x = S;
    if (S < 1) x = 1.0; 
    
    double suiv = 0.5 * (x + S / x);
    while(valeurAbs(x - suiv) > epsilon){
        x = suiv;
        suiv = 0.5 * (x + S / x);
    }
    return x;
}

double distanceEuclidienne(Point *p1, Point *p2, int dim){
    double dist = 0.0;
    for(int i = 0; i < dim; i++){
        double x = p2->p[i] - p1->p[i];
        dist += x * x;
    }
    return racine(dist);
}

double distanceManhattan(Point *p1, Point *p2, int dim){
    double dist = 0.0;
    for(int i = 0; i < dim; i++){
        dist += valeurAbs(p2->p[i] - p1->p[i]);
    }
    return dist;
}

double distanceCosinus(Point *p1, Point *p2, int dim){
    double normA = 0.0, normB = 0.0, ab = 0.0;
    for(int i = 0; i < dim; i++){
        normA += p1->p[i] * p1->p[i];
        normB += p2->p[i] * p2->p[i];
        ab += p1->p[i] * p2->p[i];
    }
    
    double denominateur = racine(normA) * racine(normB);
    if (denominateur == 0) return 1.0; 

    return 1.0 - (ab / denominateur);
}