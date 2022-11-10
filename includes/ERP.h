#pragma once

#include <iostream>
#include <exception>
#include <map>

#include "processes.h"

using namespace std;

struct resource // resource struct
{
    std::string type;
    int quantity;
    double price;
    std::map<std::string, std::string> extra_info;

};


class ERP {
    public:

    /* Default Constructor for ERP creates vector */
    ERP();

    /* Copy constructor for ERP */
    ERP(string& filename);

    /* Copy assignment operator */
    // void operator=(ERP erp_);

    /* Destructor for ERP */
    // ~ERP();

    /**
     * Getters and Setters for Quantity
     * @param s resource to get or set quantity for
     */
    int getQuantity(string s);
    void setQuantity(string s, int q);

    /**
     * Getters and Setters for Price
     * @param s resource to get or set price for
     */
    double getPrice(string s);
    void setPrice(string s, double p);

    /**
     * Getters and Setters for Type
     * @param s resource to get or set Type for
     */
    string getType(string s);
    void setType(string s, string p);

    /**
     * Getters and Setters for Info
     * @param resource resource to get Info for
     * @param info category of info to retrieve
     */
    string getInfo(string resource, string info);
    void setInfo(string resource, string info, string value, string type);

    /**
     * Add resource
     * @param resource resource to add
     * @param info resource info to store
     */
    void addResource(string resource, string info);

    void printResource(string resource_name);

    /**
     * Performs the given process on the provided set of resources
     * @param filename the detials about the processes
     */
    void addProcesses(string filename);

    /**
     * Performs the given process on the provided set of resources
     * @param processName the given process to perform
     * @param resources the set of resources to perform the process on
     */
    void performProcess(string processName);


    private:
    std::map<std::string, resource> resources_;
    Processes* processes;
    
};
