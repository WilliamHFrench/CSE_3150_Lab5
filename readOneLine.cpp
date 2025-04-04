#ifndef _READ_ONE_LINE_
#define _READ_ONE_LINE_


#include <istream>
#include <sstream>
#include <vector>

#include "readOneLine.h"

using namespace std;


vector<double> doubles_read_one_line(istream & in_stream) {
    vector<double> res;
    string line;
    
    getline(in_stream, line);
    istringstream is(line);
    string next;
    while (is >> next) {
        res.push_back(stod(next));
    }

    return res;
}




#endif