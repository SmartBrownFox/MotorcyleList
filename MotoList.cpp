//****************************************************
//  MotoList.cpp                              *
// Header file for the MotoNode class               *
// This class represents a single motorcycle node   *
// in the linked list with all motorcycle data      *
// Author: Wesley Charlton                                *
//                                    *

//****************************************************

// Class: MotoList.cpp (Implementation File)         *
// This class maintains a list of node objects.      *
//****************************************************
#include "MotoNode.h"
#include "MotoList.h"

#include <iostream>
using namespace std;

//****************************************************
// Function: MotoList (Constructor)                  *
// Initializes head and tail pointers to nullptr     *
//****************************************************
MotoList::MotoList() {
	head = nullptr;
	tail = nullptr;
}

//****************************************************
// Function: ~MotoList  (Destructor)                  *
// This function destroys the entire list.           *
//****************************************************
MotoList::~MotoList()
{
	if (head) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
}
//****************************************************
// Function: operator=                               *
// This is an overloaded assignment function. It is  *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
MotoList& MotoList::operator=(MotoList& rhs) {
	MotoNode* currObj = rhs.head;                // Copy List
	if (head != rhs.head)
	{
		if (head) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		while (currObj != nullptr) {

			PushBack(new MotoNode(currObj->GetManufacture(), currObj->GetModel(),
			                      currObj->GetStockNumber(), currObj->GetStyle(),
			                      currObj->GetPrice(), currObj->GetHorsePower()));
			currObj = currObj->GetNext();					//Traversal Statement
		}													//Important to point to the next node
	}
	return *this;
}
//****************************************************
// Function: MotoList(MotoList& rhs)                 *
// This is an copy constructor function. It is       *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
MotoList::MotoList(MotoList& rhs) {
	head = nullptr;
	tail = nullptr;
	MotoNode* currObj = rhs.head;                // Copy List

	while (currObj != nullptr) {
		PushBack(new MotoNode(currObj->GetManufacture(), currObj->GetModel(),
		                      currObj->GetStockNumber(), currObj->GetStyle(),
		                      currObj->GetPrice(), currObj->GetHorsePower()));
		currObj = currObj->GetNext();					//Traversal Statement
	}													//Important to point to the next node
}
//****************************************************
// Function: PushBack                                *
// Takes the node passed in and adds it to the end   *
// of the linked list. Accounts for an empty list.	 *
// NEEDED FOR TWO OF THE BIG THREE!!!!               *
//****************************************************
void MotoList::PushBack(MotoNode* nuNode) {
	if (!head) {
		head = tail = nuNode;
	}
	else {
		tail->SetNext(nuNode);
		tail = nuNode;
	}
}
//****************************************************
// Function: AddOneBike                              *
// Adds a new motorcycle node to the front of the    *
// linked list                                       *
//****************************************************
void MotoList::AddOneBike(MotoNode* NuNode) {
	if (!head) {
		head = tail = NuNode;
	}
	else {
		NuNode->SetNext(head);
		head = NuNode;
	}
	cout << NuNode->GetStockNumber() << "bike added." << endl;
}
//****************************************************
// Function: SellOneBike                             *
// Removes a motorcycle from the list based on stock *
// number and displays appropriate message           *
//****************************************************
void MotoList::SellOneBike(int stockNum) {
	MotoNode* curr = head;
	MotoNode* prev = nullptr;

	while (curr != nullptr && curr->GetStockNumber() != stockNum) {
		prev = curr;
		curr = curr->GetNext();
	}

	if (curr == nullptr) {
		cout << stockNum << " was not in stock." << endl;
		return;
	}

	if (prev == nullptr) {
		head = curr->GetNext();
	}
	else {
		prev->SetNext(curr->GetNext());
	}

	if (curr == tail) {
		tail = prev;
	}

	cout << stockNum << "bike removed." << endl;
	cout << stockNum << " has been sold." << endl;

	curr->SetNext(nullptr);
	delete curr;
}
//****************************************************
// Function: PrintList                               *
// Displays all motorcycle data     *
//****************************************************
void MotoList::PrintList() {
	cout << "===============================================================================" << endl;
	cout << "Manufacture    Model          Stock          Style          Price          Hp" << endl;
	cout << "-----------    -----          -----          -----          -----          ---" << endl;

	MotoNode* curr = head;
	while (curr != nullptr) {
		cout << curr->GetManufacture() << "         " << curr->GetModel() << "   "
		     << curr->GetStockNumber() << "           " << curr->GetStyle() << "         "
		     << curr->GetPrice() << "        " << curr->GetHorsePower() << endl;
		curr = curr->GetNext();
	}
	cout << "===============================================================================" << endl;
}
//****************************************************
// Function: PrintPrice                              *
// Displays all motorcycles equal to or under given  *
// price                                             *
//****************************************************
void MotoList::PrintPrice(double price) {
	cout << "===============================================================================" << endl;
	cout << "             All Bikes Under:" << price << endl;
	cout << "===============================================================================" << endl;
	cout << "Manufacture    Model          Stock          Style          Price          Hp" << endl;
	cout << "-----------    -----          -----          -----          -----          ---" << endl;

	MotoNode* curr = head;
	while (curr != nullptr) {
		if (curr->GetPrice() <= price) {
			cout << curr->GetManufacture() << "         " << curr->GetModel() << "   "
			     << curr->GetStockNumber() << "           " << curr->GetStyle() << "         "
			     << curr->GetPrice() << "        " << curr->GetHorsePower() << endl;
		}
		curr = curr->GetNext();
	}
	cout << "===============================================================================" << endl;
}
//****************************************************
// Function: PrintStyle                              *
// Displays all motorcycles matching style from the word doc that prof. Ron gave us!     *
//****************************************************
void MotoList::PrintStyle(string style) {
	cout << "===============================================================================" << endl;
	cout << "             All " << style << " bikes" << endl;
	cout << "===============================================================================" << endl;
	cout << "Manufacture    Model          Stock          Style          Price          Hp" << endl;
	cout << "-----------    -----          -----          -----          -----          ---" << endl;

	MotoNode* curr = head;
	while (curr != nullptr) {
		if (curr->GetStyle() == style) {
			cout << curr->GetManufacture() << "         " << curr->GetModel() << "   "
			     << curr->GetStockNumber() << "           " << curr->GetStyle() << "         "
			     << curr->GetPrice() << "        " << curr->GetHorsePower() << endl;
		}
		curr = curr->GetNext();
	}
	cout << "===============================================================================" << endl;
}
