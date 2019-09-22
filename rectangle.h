#pragma once
#include <string>
#include "shape.h" // needed to inherit 
using namespace std;

class rectangle : public shape {

public:

	rectangle(); // default construcor
	rectangle(double rect_height, double rect_width); // constructor
	~ rectangle() {}; //destructor
	double getheight(); //get height
	double getwidth(); //get width
	double area() const; ////calculate area
	double perimeter() const; //calculate perimeter
	void print() const; //print with proper format

private:
	double height = 0; // height varibale
	double width = 0; // width varibale
	void check(); //helper function to make sure it is not negative or 0
};

void rectangle::check(){ //helper check function

	if (height <= 0 || width <= 0){ // if height/width is less than or equal 0

		throw runtime_error("The height/width must be a non zero positive number."); //throw error

	} 
}

rectangle::rectangle() { //default constructor

	height = 1.0; //set height to 1
	width = 1.0; // set width to 1

}

rectangle::rectangle(double rect_height, double rect_width) { //constructor

	height = rect_height; //set height to value
	width = rect_width; //set width to value
	check(); //check if the values meet the specifications
}

double rectangle::getwidth(){ //return width

	return width;
}

double rectangle::getheight(){ //retrn the height

	return height;
}

double rectangle::area() const { //calculate area

	double area = 0; //variable to store area
	
	area = height * width; //calculations
	return area; // return area
}

double rectangle::perimeter() const { //calculate perimeter

	double perimeter; //variable to store perimeter
	
	perimeter = (2 * width) + (2 * height); //calclation
	return perimeter; //return

}

void rectangle::print() const { //print

	cout << "rectangle: width = " << width << ", height = " << height; //with proper formatting
}