#include <iostream>
#include "knn.h"
#include "math.h"

using namespace std;

Point* ajtP(Point* tete, double x, double y, int label) {
    Point* nouveau = new Point;
    nouveau->p = new double[2];
    nouveau->p[0] = x;
    nouveau->p[1] = y;
    nouveau->label = label;
    nouveau->suiv = tete;
    return nouveau;
}

void suppP(Point* p) {
    while (p != nullptr) {
        Point* temp = p;
        p = p->suiv;
        delete[] temp->p;
        delete temp;
    }
}

int main() {
    int dim = 2;
    int k = 3;
    Point* P = nullptr;
    P = ajtP(P, 1, 5, 1);
    P = ajtP(P, 0, 4, 1);
    P = ajtP(P, 1, 4, 1);
    P = ajtP(P, 1, 1, 2);
    P = ajtP(P, 0, 0, 2);
    P = ajtP(P, -1, -1, 2);
    P = ajtP(P, -4, 0, 3);
    P = ajtP(P, -5, 1, 3);
    P = ajtP(P, -4, 2, 3);
    Point test;
    test.p = new double[dim];
    test.p[0] = 0;
    test.p[1] = -2;
    test.label = -1;
    test.suiv = nullptr;
    cout << "### Classification du point (-1, 5) avec k=" << k << " ###" << endl;
    cout << "-----------------------------------------------" << endl;
    int resEuclid = knnEuclidien(P, nullptr, &test, dim, k);
    cout << "Label (Euclidien) : " << resEuclid << endl;
    int resManhat = knnManhattan(P, nullptr, &test, dim, k);
    cout << "Label (Manhattan) : " << resManhat << endl;
    int resCos = knnCosinus(P, nullptr, &test, dim, k);
    cout << "Label (Cosinus)   : " << resCos << endl;
    delete[] test.p;
    suppP(P);

    return 0;
}