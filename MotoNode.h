//****************************************************
//  MotoNode.h                              *
// Header file for the MotoNode class               *
// This class represents a single motorcycle node   *
// in the linked list with all motorcycle data      *
// Author: Wesley Charlton                               *
//                                   *
//****************************************************
#ifndef MOTONODE_H
#define MOTONODE_H

#include <string>
using namespace std;

class MotoNode {
private:
	string manufacture;
	string model;
	int stockNumber;
	string style;
	double price;
	int horsePower;
	MotoNode* next;

public:
	// Constructors
	MotoNode();
	MotoNode(string man, string mod, int stock, string stl, double prc, int hp);
	~MotoNode();

	// Getters
	string GetManufacture() const;
	string GetModel() const;
	int GetStockNumber() const;
	string GetStyle() const;
	double GetPrice() const;
	int GetHorsePower() const;
	MotoNode* GetNext() const;

	// Setters
	void SetManufacture(string man);
	void SetModel(string mod);
	void SetStockNumber(int stock);
	void SetStyle(string stl);
	void SetPrice(double prc);
	void SetHorsePower(int hp);
	void SetNext(MotoNode* nxt);
};

#endif
