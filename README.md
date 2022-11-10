# ERP: Enterprise Resource Planning Software

A simple platform for customers to better manage their resources. This includes features such as maintaining a record of all the resources, not only as a database but also keeping track of the processes that the resources go through by allocating resources to user defined spaces.

## Functionality

1. Maintain a database for resources
2. Track the processes as a list to better manage the resources and the finances
3. Evaluates the inventory, sales, revenue, and expenses

This is a simple ERP system where users can add their customized resources and set/get resources. This system has separate setters and getters for quantity, price, and type which are the main properties of each resource. Resources other than those can be added by providing an information category and its respective data which is stored in a map. The user can also use the print function to see the status of resources.

## Reproducible Installation Instructions

This program uses the terminal. Therefore, there are not any specific instructions needed to use this program other than downloading this file, but it is important to make sure the input file is in the correct format. Each information of resources should be a string with a double quotation mark and should be separated by a comma.

Example input for adding resources.

> "labor-a", "price,10,quantity,2,type,labor,days:string,MWF,shift timings:string,9AM-5PM"

To use 'Processes' features, the user should input the correct text file, a file containing information about processes separated by a semicolon. Three arguments should be passed through the terminal to use this feature.

## Technical Architecture

![image](https://user-images.githubusercontent.com/80299116/166295586-9becdcb2-377f-416c-b0f7-cc4fe6006823.png)

This program is written in C++. As shown in the diagram, the user can freely add resources which will make customized resource storage called ERP. With the resources being stored, the user can choose what to do with the resources. For example, if the user inputs the text file that has information about making a certain product, this program will compute how many resources are needed or how many products can user make. If the user decides to make a certain product with some resources, the storage status will be changed accordingly.
