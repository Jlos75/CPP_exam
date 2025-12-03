//
// Created by jeann on 03/12/2025.
//

#ifndef TP_EXAM_CPP_KNNSTRING_H
#define TP_EXAM_CPP_KNNSTRING_H
#include "KNN.h"
#include <string>
#include <vector>
using namespace std;

class KNNString: public KNN<vector<string>>  {
public:
    KNNString();
    KNNString(int k);

    double similarityMeasure(const vector<string> &a, const vector<string> &b) override;

    int levenshteinFullMatrix(const std::string &str1, const std::string &str2);
};


#endif //TP_EXAM_CPP_KNNSTRING_H