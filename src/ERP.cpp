#include "ERP.h"
#include <fstream>

using namespace std;

ERP::ERP() {
    // Implement this
}

ERP::ERP(string& filename) {
    ifstream input;

    input.open(filename);
    if (!input.is_open()) {
        cout << "failed to open the file" << endl;
    }

    // std::map<string,int> info;
    for (string line; getline(input, line); line = "")
    {
        vector<string> resource = split(line, ';');
        if (resource.size() != 2) {
            resources_.clear();
            throw invalid_argument("Invalid Format for Resource");
        }
        addResource(resource[0], resource[1]);
    }
}

// void ERP::operator=(ERP erp_) {
//     // Implement this
// }

// ERP::~ERP() {
//     // Implement this
// }

int ERP::getQuantity(string resource) {
    if (resources_.find(resource) == resources_.end()) {
        throw runtime_error("resource {" + resource + "} not found");
    } else {
        return resources_[resource].quantity;
    }
}

void ERP::setQuantity(string resource, int quantity) {
    if (resources_.find(resource) == resources_.end()) {
        throw runtime_error("resource {" + resource + "} not found");
    } else {
        resources_[resource].quantity = quantity;
    }
}

double ERP::getPrice(string resource) {
    if (resources_.find(resource) == resources_.end()) {
        throw runtime_error("resource {" + resource + "} not found");
    } else {
        return resources_[resource].price;
    }
}

void ERP::setPrice(string resource, double price) {
    if (resources_.find(resource) == resources_.end()) {
        throw runtime_error("resource {" + resource + "} not found");
    } else {
        resources_[resource].price = price;
    }
}

string ERP::getType(string resource) {
    if (resources_.find(resource) == resources_.end()) {
        throw runtime_error("resource {" + resource + "} not found");
    } else {
        return resources_[resource].type;
    }
}

void ERP::setType(string resource, string type) {
    if (resources_.find(resource) == resources_.end()) {
        throw runtime_error("resource {" + resource + "} not found");
    } else {
        resources_[resource].type = type;
    }
}

string ERP::getInfo(string resource, string info) {
    if (resources_.find(resource) == resources_.end()) {
        throw runtime_error("resource {" + resource + "} not found");
    } else {
        if (resources_[resource].extra_info.find(info) == resources_[resource].extra_info.end()) {
            throw runtime_error("information {" + info + "} not found in resource {" + resource + "}");
        } else {
            string to_ret = resources_[resource].extra_info[info];
            return to_ret.substr(0, to_ret.find(":"));
        }
    }
}

void ERP::setInfo(string resource, string info, string value, string type) {
    if (resources_.find(resource) == resources_.end()) {
        throw runtime_error("resource {" + resource + "} not found");
    } else {
        if (resources_[resource].extra_info.find(info) == resources_[resource].extra_info.end()) {
            throw runtime_error("information {" + info + "} not found in resource {" + resource + "}");
        } else {
            resources_[resource].extra_info[info] = value + ":" + type;
        }
    }
}

void ERP::addResource(string resource_name, string info) {
    resource to_add;

    for (size_t i = 0; i < info.length() && info.substr(i).find(",") != string::npos; i += info.substr(i).find(",") + 1) {
        // std::cout << i << std::endl;
        size_t next_pos = info.substr(i).find(",") + 1;
        string key = info.substr(i, next_pos);

        i += next_pos;
        next_pos = info.substr(i).find(",");
        string value = info.substr(i, next_pos);

        if (key == "price,") {
            double price = stod(value);
            to_add.price = price;
        } else if (key == "quantity,") {
            int quantity = stod(value);
            to_add.quantity = quantity;
        } else if (key == "type,") {
            string type = value;
            to_add.type = type;
        } else {
            string val_type = key.substr(key.find(":"));
            key = key.substr(0, key.find(":"));
            to_add.extra_info[key] = value + val_type.substr(0, val_type.length() - 1);
        }
    }
    resources_[resource_name] = to_add;
}

void ERP::printResource(string resource_name) {
    if (resources_.find(resource_name) == resources_.end()) {
        throw runtime_error("resource {" + resource_name + "} not found");
    } else {
        resource res = resources_[resource_name];
        std::cout << "Resource Name -> " << resource_name << std::endl;
        std::cout << "Resource Type -> " << res.type << std::endl;
        std::cout << "Resource Price -> " << res.price << std::endl;
        std::cout << "Resource Quantity -> " << res.quantity << std::endl;
        
        for (auto& key : res.extra_info) {
            std::cout << "Resource " << key.first << " -> " << key.second.substr(0, key.second.find(":")) << std::endl;
        }
    }
}


void ERP::performProcess(string processName) {
    auto processIO = processes->GetInputOutput(processName);
    vector<string> processInputs = processIO.first;
    vector<string> processOutputs = processIO.second;

    for (string input : processInputs) {
        vector<string> inputResource= split(input, ':');
        int currQuantity = getQuantity(inputResource[0]);
        setQuantity(inputResource[0], currQuantity - stoi(inputResource[1]));
    }
    for (string input : processOutputs) {
        vector<string> inputResource= split(input, ':');
        int currQuantity = getQuantity(inputResource[0]);
        setQuantity(inputResource[0], currQuantity + stoi(inputResource[1]));
    }
}

void ERP::addProcesses(string filename) {
    processes = new Processes(filename);
}