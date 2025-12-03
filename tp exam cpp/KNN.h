//
// Created by jeann on 03/12/2025.
//

#ifndef TP_EXAM_CPP_KNN_H
#define TP_EXAM_CPP_KNN_H

#include <algorithm>
#include <vector>
using namespace std;


template<typename T>
class KNN {
private:
    int k;
public:
    KNN() : k(3) {}
    KNN(int k) : k(k) {}

    int getK() const {
        return k;
    }

    vector<int> findNearestNeighbors(const vector<T>& trainData, const T& target) {
        vector<pair<double, int>> distances;
        for (size_t i = 0; i < trainData.size(); ++i) {
            double dist = similarityMeasure(trainData[i], target);
            distances.push_back({dist, static_cast<int>(i)});
        }

        sort(distances.begin(), distances.end());
        // Retourner  k premier index
        vector<int> neighbors;
        for (int i = 0; i < k && i < static_cast<int>(distances.size()); ++i) {
            neighbors.push_back(distances[i].second);
        }

        return neighbors;
    }

    virtual double similarityMeasure(const T& a, const T& b) = 0;

};




#endif //TP_EXAM_CPP_KNN_H
