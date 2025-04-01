#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include <istream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include "readOneLine.h"
#include "readOneLine.cpp"
#include <algorithm>
#include "basicCalcs.cpp"
#include "include/doctest.h"


using namespace std;

TEST_CASE("Vector Magnitude Tests"){

    vector<double> vec1 = {1.0, 1.0, 1.0, 1.0, 1.0};
    vector<double> vec2 = {1.0, 1.0, 1.0, 1.0, 0.0};
    vector<double> vec3 = {1.0, 1.0, 1.0};
    vector<double> vec4 = {1.0, 1.0, 0.0};

    CHECK(sqrt(5) == vectorMagnitude(vec1));
    CHECK(2 == vectorMagnitude(vec2));
    CHECK(sqrt(3) == vectorMagnitude(vec3));
    CHECK(sqrt(2) == vectorMagnitude(vec4));
}

TEST_CASE("DotProduct Test"){
    vector<double> vec1 = {1.0, 1.0, 1.0, 1.0, 1.0};
    vector<double> vec2 = {1.0, 1.0, 1.0, 1.0, 0.0};
    vector<double> vec3 = {1.0, 1.0, 1.0};
    vector<double> vec4 = {1.0, 1.0, 0.0};
    vector<double> vec5 = {1.0, 1.0, 0.0, 1.0, 1.0};

    CHECK(dotProduct(vec1, vec2) == 4);
    CHECK(dotProduct(vec3, vec4) == 2);
    CHECK(dotProduct(vec1, vec5) == 4);
    CHECK(dotProduct(vec2, vec5) == 3);
}

TEST_CASE("Cosine-Distance Print Test"){
    SUBCASE("Edge Cases"){
        vector<double> vec1 = {1.0, 1.0, 1.0, 1.0, 1.0};
        vector<double> vec2 = {1.0, 1.0, 1.0, 0.0, 0.0};
        VectorCombo v(1, vec1, vec2);
        vector<VectorCombo> VList = {v};
        string solution = "1 [1 1 1 1 1 ] [1 1 1 0 0 ]\n";

        CHECK(cosineDistancePrint(VList) == solution);
        
    };
        vector<double> vec1 = {1.0, 1.0, 1.0, 1.0, 1.0};
        vector<double> vec2 = {1.0, 1.0, 1.0, 0.0, 0.0};
        vector<double> vec3 = {1.0, 1.0, 0.0, 1.0, 1.0};
        VectorCombo v1(1, vec1, vec2);   
        VectorCombo v2(2, vec2, vec3);
        VectorCombo v3(3, vec1, vec3);
        vector<VectorCombo> VList = {v1, v2, v3};
        
        string solution = "1 [1 1 1 1 1 ] [1 1 1 0 0 ]\n2 [1 1 1 0 0 ] [1 1 0 1 1 ]\n3 [1 1 1 1 1 ] [1 1 0 1 1 ]\n";
        CHECK(cosineDistancePrint(VList) == solution);

}

TEST_CASE("Cosine-Distance Sort Test"){

    SUBCASE("Two vector Test"){
    
    vector<double> vec1 = {1.0, 1.0, 1.0, 1.0, 1.0};
    vector<double> vec2 = {1.0, 1.0, 1.0, 1.0, 0.0};
    vector<vector<double>> vec3 = {vec1, vec2};

    vector<VectorCombo> VList = cosineDistanceSort(vec3);

    string solution = "0.463648 [1 1 1 1 1 ] [1 1 1 1 0 ]\n";
    CHECK(cosineDistancePrint(VList) == solution);

    vector<double> vec4 = {1.0, 1.0, 1.0};
    vector<double> vec5 = {1.0, 1.0, 0.0};
    vector<vector<double>> vec6 = {vec4, vec5};

    vector<VectorCombo> VList2 = cosineDistanceSort(vec6);
    string solution2 = "0.61548 [1 1 1 ] [1 1 0 ]\n";
    CHECK(cosineDistancePrint(VList2) == solution2);
}

    SUBCASE("Three vector Test"){
        vector<double> vec1 = {1.0, 1.0, 1.0, 1.0, 1.0};
        vector<double> vec2 = {1.0, 1.0, 1.0, 0.0, 0.0};
        vector<double> vec3 = {1.0, 1.0, 0.0, 1.0, 1.0};

        vector<vector<double>> vectorList = {vec1, vec2, vec3};
        vector<VectorCombo> VList = cosineDistanceSort(vectorList);
        string solution = "0.463648 [1 1 1 1 1 ] [1 1 0 1 1 ]\n0.684719 [1 1 1 1 1 ] [1 1 1 0 0 ]\n0.955317 [1 1 1 0 0 ] [1 1 0 1 1 ]\n";
        CHECK(cosineDistancePrint(VList) == solution);

    }

    SUBCASE("Four vector Test"){
        vector<double> vec1 = {1.0, 1.0, 1.0, 1.0, 1.0};
        vector<double> vec2 = {1.0, 1.0, 1.0, 0.0, 0.0};
        vector<double> vec3 = {1.0, 1.0, 0.0, 1.0, 1.0};
        vector<double> vec4 = {0.0, 0.0, 0.0, 0.0, 1.0};

        vector<vector<double>> vectorList = {vec1, vec2, vec3, vec4};
        vector<VectorCombo> VList = cosineDistanceSort(vectorList);
        string solution = "0.463648 [1 1 1 1 1 ] [1 1 0 1 1 ]\n0.684719 [1 1 1 1 1 ] [1 1 1 0 0 ]\n0.955317 [1 1 1 0 0 ] [1 1 0 1 1 ]\n1.0472 [1 1 0 1 1 ] [0 0 0 0 1 ]\n1.10715 [1 1 1 1 1 ] [0 0 0 0 1 ]\n1.5708 [1 1 1 0 0 ] [0 0 0 0 1 ]\n";
        CHECK(cosineDistancePrint(VList) == solution);
    }
}