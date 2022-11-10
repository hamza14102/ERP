#include "ERP.h"
#include <iostream>

using namespace std;
int main()
{
    //creates an ERP system
    string file = "input/resources.txt";
    ERP* erp = new ERP(file);

    //adds labor resources to ERP
    // erp->addResource("labor-a", "price,10,quantity,2,type,labor,days:string,MWF,shift timings:string,9AM-5PM");
    erp->printResource("labor-a");
    cout << "\n" << endl;

    //add mago wood resources to ERP
    // erp->addResource("mango wood", "price,0.50,quantity,1000,type,wood,region:string,Austrailia,weight:int,5kg/sqm");
    erp->printResource("mango wood");
    cout << "\n" << endl;

    //setting a new quantity for mango wood
    erp->setQuantity("mango wood", 900);
    cout << "New Mango Woods quantity: " << erp->getQuantity("mango wood") << "\n" << endl;

    //setting a new price for labor
    erp->setPrice("labor-a", 12);
    cout << "New price for labor-a: " << erp->getPrice("labor-a") << "\n" << endl;

    //getting a type of resources
    cout << "Type of resources: " << erp->getType("mango wood") << endl;
    cout << "Type of resources: " << erp->getType("labor-a") << "\n" << endl;

    //getting information about the resources
    cout << "INFO: mango wood->Weight: " << erp->getInfo("mango wood", "weight") << endl;
    cout << "INFO: labor-a->Available_Days: " << erp->getInfo("labor-a", "days") << "\n" << endl;

    //labor-a changed working days
    erp->setInfo("labor-a", "days", "MTWF", "string");
    cout << "INFO: labor-a->New_Available_Days: " << erp->getInfo("labor-a", "days") << endl;


    erp->addProcesses("input/processes.txt");
    erp->printResource("aluminium");
    erp->printResource("chair");
    erp->performProcess("buildChair");
    erp->printResource("aluminium");
    erp->printResource("chair");
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////        Testing processes class        ///////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Process* process = new Process("./Processes-in-files/process_a.txt", *erp);
    


    return 0;
}