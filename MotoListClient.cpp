//****************************************************
// Program: MotoListClient.cpp						 *
// Client program to use the MotoNode and MotoList   *
// classes											 *
// Name: Wesley Charlton                             *
//                                     *
//****************************************************
#include "MotoNode.h"
#include "MotoList.h"
#include <iostream>
#include<fstream>
#include<string>

MotoNode*CreateNuNode(); // prototype: creates a node to be added to the list
ifstream infile;		 // global file pointer to read data from the input file

int main() {

  infile.std::open("MotoData.txt"); // open data file, must be in the same
                                    // folder with your code
  // in other words, in your project folder.

  MotoList MyListOfMoto; // List of Motorcycle
  double price;          // Use to  bikes under a given price
  int choice, DelStock;  // The choices of metdisplayhods, see below
  string Style;          // Use to display bikes under a given price
  MotoNode *NuNode;      // Use to point to the new node

  infile >> choice; // get a menu choice before entering the loop

  while (choice != 6) {
    if (choice == 1) { // Add a newly created node to the front of the list
      NuNode = CreateNuNode();
      MyListOfMoto.AddOneBike(NuNode);
    } else if (choice ==
               2) { // Finds and deletes a node based on the integer entered
      infile >> DelStock;
      MyListOfMoto.SellOneBike(DelStock);
    } else if (choice == 3) { // Display the list
      MyListOfMoto.PrintList();
    } else if (choice == 4) { // Display all bikes for a given price
      infile >> price;
      MyListOfMoto.PrintPrice(price);
    } else if (choice == 5) { // Display all bikes for a given style
      std::getline(infile, Style);
      MyListOfMoto.PrintStyle(Style);
    }
    infile >> choice;
  }

	return 0;
}

//-----------------------------------------------------
// Function: CreateNuNode
// Inputs data for a new bike
// Create a new node and returns a pointer to that node
//-----------------------------------------------------
MotoNode* CreateNuNode()
{
	//Declare the appropriate variables to popluate your node.
	MotoNode* nuNode;
	string manufacture;
	string model;
	int stockNumber;
	string style;
	double price;
	int horsePower;

	//Input those variables to popluate your node.
        std::getline(infile, manufacture);
        std::getline(infile, model);
        infile >> stockNumber;
        infile.std::ignore();
        std::getline(infile, style);
        infile >> price;
	infile >> horsePower;

	//add those variables as arguments to populate your node.
	nuNode = new MotoNode(manufacture, model, stockNumber, style, price, horsePower);

	return nuNode;
}
//-----------------------------------------------------
//Make sure if any changes to document additional functions!!!!!
//-----------------------------------------------------