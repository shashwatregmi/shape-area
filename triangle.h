#pragma once
#include <string>
#include "shape.h" // needed to inherit 
using namespace std;

class triangle : public shape {

public:

	triangle(); // default construcor
	triangle(double trig_side); // constructor
	~ triangle() {}; //destructor
	double getside(); //get side
	double area() const; //calculate area
	double perimeter() const; //calculate perimeter
	void print() const; //print with proper format

private:
	double side = 0; // side varibale
	void check(); //helper function to make sure it is not negative or 0
};

void triangle::check(){ //helper check function

	if (side <= 0){ // if radius is less than or equal 0

		throw runtime_error("The sides must be a non zero positive number."); //throw error

	} 
}

triangle::triangle() { //default constructor

	side = 1.0; // set side to 1

}

triangle::triangle(double trig_side) { //constructor

	side = trig_side; //set side to value
	check(); //check if the value meets requirments
}

double triangle::getside(){ //return side

	return side;
}

double triangle::area() const { //calculate area

	double area = 0; //variable to store area
	
	area = (side * side) / 2; //calculation
	return area;   //return
}

double triangle::perimeter() const { //calculate perimeter

	double perimeter;//variable to store perimeter
	
	perimeter = 3 * side; //calclation
	return perimeter; //return

}

void triangle::print() const { //print

	cout << "triangle: side = " << side; //with proper formatting
}