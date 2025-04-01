#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream> 

using namespace std;

double vectorMagnitude(vector<double> & myVector){
    double value{0.0};
    for(auto v: myVector){
        value += v * v;
    }
    return sqrt(value);
}

double dotProduct(vector<double> & v1, vector<double> & v2){
    double value{0.0};
    for(int i = 0; i < v1.size(); i++){
        value += v1[i] * v2[i];
    }
    return value;
}

struct VectorCombo{
    double score;
    vector<double> v1;
    vector<double> v2;

    VectorCombo(double _score, const vector<double> & _v1, const vector<double> & _v2): score(_score), v1(_v1), v2(_v2){}
    bool operator==(const VectorCombo& other) const {
        return score == other.score && v1 == other.v1 && v2 == other.v2;
    }
};

ostream& operator<<(ostream& os, const vector<double>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        os << vec[i];
        if (i != vec.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

vector<VectorCombo> cosineDistanceSort(vector<vector<double>> & vecList){
    vector<VectorCombo> vList;
    for(int i = 0; i < vecList.size(); i++){
        for(int j = i + 1; j < vecList.size(); j++){
            double dot = dotProduct(vecList[i], vecList[j]);
            double magnitude = vectorMagnitude(vecList[i]) * vectorMagnitude(vecList[j]);
            double score = acos(dot / magnitude);
            vList.emplace_back(score, vecList[i], vecList[j]);
                

        }
    }
    sort(vList.begin(), vList.end(), [](const VectorCombo &a, const VectorCombo &b) {
        return a.score < b.score; // Sort by cosine similarity score (lower is more similar)
    });
    return vList;
};


string cosineDistancePrint(const std::vector<VectorCombo>& vlist) {
    ostringstream oss;  

    for (const auto& v : vlist) {
        oss << v.score << " ";
        
        // Print vector v1
        oss << "[";
        for (const auto& val : v.v1) {
            oss << val << " ";
        }
        oss << "] [";

        for (const auto& val : v.v2) {
            oss << val << " ";
        }
        oss << "]\n";  // New line after each VectorCombo
    }

    // Return the accumulated string
    return oss.str();
}