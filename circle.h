#pragma once
#include <string>
#include "shape.h" // needed to inherit 
using namespace std;

class circle : public shape {

public:

	circle(); // default construcor
	circle(double cir_radius); // constructor
	~ circle() {}; //destructor
	double getradius(); //get radius
	double area() const; //calculate area
	double perimeter() const; //calculate perimeter
	void print() const; //print with proper format

private:
	double radius = 0; // radius varibale
	const double PI = 3.14159265; //cosnt PI
	void check(); //helper function to make sure it is not negative or 0
};

void circle::check(){ //helper check function

	if (radius <= 0){ // if radius is less than or equal 0

		throw runtime_error("The radius must be a non zero positive number."); //throw error

	} 
}

circle::circle() { //default constructor

	radius = 1.0; //set radius to 1

}

circle::circle(double cir_radius) { //constructor

	radius = cir_radius; //set radius to value
	check(); //check if the value meets requirments
}

double circle::getradius(){ //return radius

	return radius;
}

double circle::area() const { //calculate area
 
	double area = 0; //variable to store area
	
	area = PI * (radius * radius); //calculation
	return area;  //return
}

double circle::perimeter() const { //calculate perimeter

	double perimeter = 0; //variable to store perimeter
	
	perimeter = 2 * PI * radius; //calclation
	return perimeter; // return

}

void circle::print() const{ //print

	cout << "circle: radius = " << radius; //with proper formatting
}