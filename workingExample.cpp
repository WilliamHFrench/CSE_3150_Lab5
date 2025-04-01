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


int main() {

    using namespace std;

    vector<double> my_vector;
    vector<vector<double>> VList;

    ifstream txtFile;
    txtFile.open("vector.txt");

    while (! txtFile.eof() ) {

        my_vector = doubles_read_one_line(txtFile);
        VList.push_back(my_vector);
        
        }
        txtFile.close();
    
        vector<VectorCombo> sortedList = cosineDistanceSort(VList);
        cout << cosineDistancePrint(sortedList);

    return 0;
}

