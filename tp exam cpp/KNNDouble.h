//
// Created by jeann on 03/12/2025.
//

#ifndef TP_EXAM_CPP_KNNDOUBLE_H
#define TP_EXAM_CPP_KNNDOUBLE_H
#include "KNN.h"
#include <utility>
using namespace std ;

class KNNDouble : public KNN<pair<double, double>> {
public:
    KNNDouble();
    KNNDouble(int k);

    double similarityMeasure(const pair<double, double>& a, const pair<double, double>& b) override;
};


#endif //TP_EXAM_CPP_KNNDOUBLE_H