
#include "KNNDouble.h"
#include <cmath>
using namespace std;

KNNDouble::KNNDouble() : KNN(1) {}
KNNDouble::KNNDouble(int k) : KNN(k) {}

double KNNDouble::similarityMeasure(const pair<double, double>& x, const pair<double, double>& y) {
    double dx = x.first - y.first;
    double dy = x.second - y.second;
    return  sqrt(dx * dx + dy * dy);
}