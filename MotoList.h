//****************************************************
//  MotoList.h                              *
// Header file for the MotoNode class               *
// This class represents a single motorcycle node   *
// in the linked list with all motorcycle data  *
// Author: Wesley Charlton                                *
//                                    *
//****************************************************

#ifndef MOTOLIST_H
#define MOTOLIST_H

#include "MotoNode.h"

class MotoList {
private:
	MotoNode* head;
	MotoNode* tail;

public:
	// Constructor
	MotoList();

	// Big Three
	MotoList(MotoList& rhs);
	MotoList& operator=(MotoList& rhs);
	~MotoList();

	// Member functions
	void PushBack(MotoNode* nuNode);
	void AddOneBike(MotoNode* NuNode);
	void SellOneBike(int stockNum);
	void PrintList();
	void PrintPrice(double price);
	void PrintStyle(string style);
};

#endif