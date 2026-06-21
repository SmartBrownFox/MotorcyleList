//****************************************************
//  MotoNode.cpp                              *
// Header file for the MotoNode class               *
// This class represents a single motorcycle node   *
// in the linked list with all motorcycle data      *
// Author: Wesley Charlton                                *
//                                    *
//****************************************************
#include "MotoNode.h"

// Default Constructor
MotoNode::MotoNode() {
	manufacture = "";
	model = "";
	stockNumber = 0;
	style = "";
	price = 0.0;
	horsePower = 0;
	next = nullptr;
}

// Parameterized Constructor
MotoNode::MotoNode(string man, string mod, int stock, string stl, double prc, int hp) {
	manufacture = man;
	model = mod;
	stockNumber = stock;
	style = stl;
	price = prc;
	horsePower = hp;
	next = nullptr;
}

// Destructor
MotoNode::~MotoNode() {
	if (next != nullptr) {
		delete next;
		next = nullptr;
	}
}

// Getters
string MotoNode::GetManufacture() const {
	return manufacture;
}
string MotoNode::GetModel() const {
	return model;
}
int MotoNode::GetStockNumber() const {
	return stockNumber;
}
string MotoNode::GetStyle() const {
	return style;
}
double MotoNode::GetPrice() const {
	return price;
}
int MotoNode::GetHorsePower() const {
	return horsePower;
}
MotoNode* MotoNode::GetNext() const {
	return next;
}

// Setters
void MotoNode::SetManufacture(string man) {
	manufacture = man;
}
void MotoNode::SetModel(string mod) {
	model = mod;
}
void MotoNode::SetStockNumber(int stock) {
	stockNumber = stock;
}
void MotoNode::SetStyle(string stl) {
	style = stl;
}
void MotoNode::SetPrice(double prc) {
	price = prc;
}
void MotoNode::SetHorsePower(int hp) {
	horsePower = hp;
}
void MotoNode::SetNext(MotoNode* nxt) {
	next = nxt;
}
