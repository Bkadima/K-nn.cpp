#include <iostream>
#include <map>
#include "math.h" 
#include "knn.h"

using namespace std;

void normalMinMax(Point *p, Point *max, Point *min, int dim) {
    for (int i = 0; i < dim; i++) {
        double range = max->p[i] - min->p[i];
        if (range != 0) {
            p->p[i] = (p->p[i] - min->p[i]) / range;
        } else {
            p->p[i] = 0;
        }
    }
}

void normalVec(Point *p, int dim) {
    double norm = 0.0;
    for (int i = 0; i < dim; i++) {
        norm += p->p[i] * p->p[i];
    }
    double r = racine(norm);
    if (r > 0) {
        for (int i = 0; i < dim; i++) {
            p->p[i] /= r;
        }
    }
}

Voisin *addVois(Point *p, Voisin *v, double dist) {
    Voisin *nouv = new Voisin;
    nouv->vois = p;
    nouv->dist = dist;
    nouv->suiv = nullptr;

    if (v == nullptr || dist < v->dist) {
        nouv->suiv = v;
        return nouv;
    }

    Voisin *courant = v;
    while (courant->suiv != nullptr && courant->suiv->dist < dist) {
        courant = courant->suiv;
    }
    nouv->suiv = courant->suiv;
    courant->suiv = nouv;
    return v;
}

void minMax(Point *P, Point *min, Point *max, int dim) {
    Point *courant = P;
    while (courant != nullptr) {
        for (int i = 0; i < dim; i++) {
            if (courant->p[i] < min->p[i]) min->p[i] = courant->p[i];
            if (courant->p[i] > max->p[i]) max->p[i] = courant->p[i];
        }
        courant = courant->suiv;
    }
}

int nblabel(Voisin *v, int k) {
    map<int, int> compteur;
    Voisin *courant = v;
    for (int i = 0; i < k && courant != nullptr; i++) {
        compteur[courant->vois->label]++;
        courant = courant->suiv;
    }

    int mLabel = -1;
    int maxFreq = -1;
    for (map<int, int>::iterator it = compteur.begin(); it != compteur.end(); ++it) {
        if (it->second > maxFreq) {
            maxFreq = it->second;
            mLabel = it->first;
        }
    }
    return mLabel;
}

void detruireVoisins(Voisin *v) {
    while (v != nullptr) {
        Voisin *temp = v;
        v = v->suiv;
        delete[] temp->vois->p;
        delete temp->vois;
        delete temp;
    }
}

int knnEuclidien(Point *p, Voisin *vois, Point *test, int dim, int k) {
    Point *min = new Point; Point *max = new Point;
    min->p = new double[dim]; max->p = new double[dim];
    for (int i = 0; i < dim; i++) { min->p[i] = 1e18; max->p[i] = -1e18; }

    minMax(p, min, max, dim);

    Point *testNorm = new Point;
    testNorm->p = new double[dim];
    for (int i = 0; i < dim; i++) testNorm->p[i] = test->p[i];
    normalMinMax(testNorm, max, min, dim);

    Voisin *listeVois = nullptr;
    Point *courant = p;
    while (courant != nullptr) {
        Point *copie = new Point;
        copie->p = new double[dim];
        copie->label = courant->label;
        for (int i = 0; i < dim; i++) copie->p[i] = courant->p[i];
        normalMinMax(copie, max, min, dim);

        double dist = distanceEuclidienne(copie, testNorm, dim);
        listeVois = addVois(copie, listeVois, dist);
        courant = courant->suiv;
    }

    int res = nblabel(listeVois, k);
    detruireVoisins(listeVois);
    delete[] min->p; delete min; delete[] max->p; delete max;
    delete[] testNorm->p; delete testNorm;
    return res;
}

int knnManhattan(Point *p, Voisin *vois, Point *test, int dim, int k) {
    Point *min = new Point; Point *max = new Point;
    min->p = new double[dim]; max->p = new double[dim];
    for (int i = 0; i < dim; i++) { min->p[i] = 1e18; max->p[i] = -1e18; }

    minMax(p, min, max, dim);

    Point *testNorm = new Point;
    testNorm->p = new double[dim];
    for (int i = 0; i < dim; i++) testNorm->p[i] = test->p[i];
    normalMinMax(testNorm, max, min, dim);

    Voisin *listeVois = nullptr;
    Point *courant = p;
    while (courant != nullptr) {
        Point *copie = new Point;
        copie->p = new double[dim];
        copie->label = courant->label;
        for (int i = 0; i < dim; i++) copie->p[i] = courant->p[i];
        normalMinMax(copie, max, min, dim);

        double dist = distanceManhattan(copie, testNorm, dim);
        listeVois = addVois(copie, listeVois, dist);
        courant = courant->suiv;
    }

    int res = nblabel(listeVois, k);
    detruireVoisins(listeVois);
    delete[] min->p; delete min; delete[] max->p; delete max;
    delete[] testNorm->p; delete testNorm;
    return res;
}

int knnCosinus(Point *p, Voisin *vois, Point *test, int dim, int k) {
    Point *testNorm = new Point;
    testNorm->p = new double[dim];
    for (int i = 0; i < dim; i++) testNorm->p[i] = test->p[i];
    normalVec(testNorm, dim);

    Voisin *listeVois = nullptr;
    Point *courant = p;
    while (courant != nullptr) {
        Point *copie = new Point;
        copie->p = new double[dim];
        copie->label = courant->label;
        for (int i = 0; i < dim; i++) copie->p[i] = courant->p[i];
        normalVec(copie, dim);

        double dist = distanceEuclidienne(copie, testNorm, dim);
        listeVois = addVois(copie, listeVois, dist);
        courant = courant->suiv;
    }

    int res = nblabel(listeVois, k);
    detruireVoisins(listeVois);
    delete[] testNorm->p; delete testNorm;
    return res;
}