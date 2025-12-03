//
// Created by jeann on 03/12/2025.
//

#include "KNNString.h"

KNNString::KNNString() : KNN<vector<string>>() {}
KNNString::KNNString(int k) : KNN<vector<string>>(k) {}

double KNNString::similarityMeasure(const vector<string>& a, const vector<string>& b){
    double totalDistance = 0.0;
    size_t len = min(a.size(), b.size());
    for (size_t i = 0; i < len; ++i) {
        totalDistance += levenshteinFullMatrix(a[i], b[i]);
    }
    return totalDistance;
}

int KNNString::levenshteinFullMatrix(const string& str1,const string& str2) {
    int m = str1.length();
    int n = str2.length();

    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1
                        + min(

                            // Insert
                            dp[i][j - 1],
                            min(

                                // Remove
                                dp[i - 1][j],

                                // Replace
                                dp[i - 1][j - 1]));
            }
        }
    }

    return dp[m][n];
}