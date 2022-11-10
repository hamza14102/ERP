#pragma once
#include <iostream>
#include <map>

#include "utilities.h"

using namespace std;

class Processes {
    public:

    Processes(string filename);

    /**
     * Returns the input and output fields for a given process
     * @param processName the name of the process for which to return the input and output
     * @return cost to make one product
     */
    pair<vector<string>, vector<string>> GetInputOutput(string processName);

   private:
   std::map<string,std::pair<vector<string>, vector<string>>> processInfo_;
   
};