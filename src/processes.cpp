#include "processes.h"
#include "ERP.h"
#include <fstream>
#include <map>

Processes::Processes(string filename) {

    ifstream input;

    input.open(filename);
    if (!input.is_open()) {
        cout << "failed to open the file" << endl;
    }

    // std::map<string,int> info;
    for (string line; getline(input, line); line = "")
    {
        vector<string> process = split(line, ';');
        if (process.size() != 3) {
            processInfo_.clear();
            throw invalid_argument("Invalid Format for Process");
        }
        vector<string> input = split(process[1]);
        vector<string> output = split(process[2]);
        processInfo_[process[0]] = pair<vector<string>, vector<string>>(input, output);
    }
}


pair<vector<string>, vector<string>> Processes::GetInputOutput(string processName) {
    if (processInfo_.find(processName) == processInfo_.end()) {
        throw invalid_argument("Invalid Process");
    }
    return processInfo_[processName];
}

// int Processes::makePrductCapacity(string product) {
//     /**
//      * @todo implement this!
//      */
//     return -1;
// }

// bool Processes::canMakePrductCapacity(string product, int quantity) {
//     /**
//      * @todo implement this!
//      */
//     return false;
// }

// void Processes::makePrduct(string product, int quantity) {
//     /**
//      * @todo implement this!
//      */

// }

// void Processes::setPrductInfo(string product) {
//     /**
//      * @todo implement this!
//      */

// }

// string Processes::getPrductInfo(string product) {
//     /**
//      * @todo implement this!
//      */
//     return "";
// }

// int Processes::howManyProduct(string product) {
//     /**
//      * @todo implement this!
//      */
//     return -1;
// }

// string Processes::howMuchResources(int n) {
//     /**
//      * @todo implement this!
//      */
//     return "";
// }

// double Processes::perUnitCost(string product) {
//     /**
//      * @todo implement this!
//      */
//     return 0.0;
// }