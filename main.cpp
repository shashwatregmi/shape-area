
// include c++ libraries for program function
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdexcept>
///include the base and derived shape files
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

////functions used 
void input_data(ifstream& fin); // reads the file - line by line and calls functions to calculate/print
bool is_num (string& input); // checks if the substring contains a double as we want it to
void calculations(vector <shape*> shapelist); // calculates the area and perimeter
bool areacompare(const shape* a, const shape* b); // for area SORT -- returns true/false after comparing the area
bool pericompare(const shape* a, const shape* b); // for perimeter SORT -- returns true/false after comparing the perimeter


int main () { // MAIN FUNCTION
	try {
		string line; // string variable that stores the value of getline..
		ifstream main_fin("files.txt"); // Open file named 'files.txt' 
		if (main_fin.fail()) { // if the file fails to open
			throw runtime_error("The file cannot be found."); //throw error
		}

		while (getline(main_fin, line)) { // while there is a line to be read in the file
			ifstream fin(line); // open the file listed in the main_fin file ....
			if (fin.fail()) { // if the file fails to open
				cout << "\n|| Could not open " << line <<". || \n\n"; // give message and will try again with another file if line exists
			} else { // if file is found and opens
				cout << endl << line << endl; // cout the name of the file -- stored in line
				input_data(fin); // call input data function which takes this file and calls other functions to calculate
			}
		}	
	} catch (runtime_error& e){
		cout << e.what() << endl;
	}
	return 0; // return 0
}

void input_data(ifstream& fin){
	string shape_data, input; // string variables to store line read and input
	double num_1, num_2; // double varibles to store the radius/side/height/width of shape
	vector <shape*> shapelist; // vector of shape pointers 
	try {	
		while (getline(fin, shape_data)) {// while data can be read from this file (line by line)
			char s; // char variables to identify if we are dealing with a circle, triangle or rectangle
			int index; // integer index variable -- this is used to find out where to take substr till such that we get the doubles we want
			s = shape_data[0]; // lets take the first char in the line we just read and put into the char s variable
			
			if (s == 'c') { //if the char is c it means we have a circle
				if (shape_data.size() >= 3 && shape_data[1] == ' '){ // if the size is bigger than 3 and we have a space at index 2 for formatiing
					index = shape_data.find(' ', 2); // find the next space after index 2 in the get line string
					input = shape_data.substr(2, index); // take substr from index 2 till the index variable (space) --  this will give us our first set of data
					
					if (is_num(input)){ //call is_num function to check that our substr is a number -- otherwise we just ignore this line and get another line (beginning of loop)
						num_1 = stod(input); // put the substring into the double variable by using the string to double (stod) function
						shapelist.push_back(new circle(num_1)); //push back the new shape created in dynamic memory into the vector of shape pointers
					}
				}
			} else if (s == 't') { //if the char is t it means we have a triangle
				if (shape_data.size() >= 3 && shape_data[1] == ' '){ // if the size is bigger than 3 and we have a space at index 2 for formatiing
					index = shape_data.find(' ', 2); // find the next space after index 2 in the get line string
					input = shape_data.substr(2, index); // take substr from index 2 till the index variable (space) --  this will give us our first set of data
					
					if (is_num(input)){ //call is_num function to check that our substr is a number -- otherwise we just ignore this line and get another line (beginning of loop)
						num_1 = stod(input); // put the substring into the double variable by using the string to double (stod) function
						shapelist.push_back(new triangle(num_1)); //push back the new shape created in dynamic memory into the vector of shape pointers
					}
				}
			} else if (s == 'r'){ //if the char is r it means we have a rectangle
				if (shape_data.size() >= 3 && shape_data[1] == ' '){ // if the size is bigger than 3 and we have a space at index 2 for formatiing
					index = shape_data.find(' ', 2); // find the next space after index 2 in the get line string

					input = shape_data.substr(2, index); // take substr from index 2 till the index variable (space) --  this will give us our first set of chars
					if (is_num(input)){ //call is_num function to check that our substr is a number -- otherwise we just ignore this line and get another line (beginning of loop)
						
						num_1 = stod(input); // put the substring into the double variable by using the string to double (stod) function
						int index_2; // integer index variable -- this is used to find out where to take substr till such that we get the 2nd double for rectangle
						index_2 = shape_data.find(' ', index + 1); // find the next space after index + 1  (last space) in the get line string
						input = shape_data.substr(index + 1, index_2); // take substr from (index+1) till the index_2 variable (space) --  this will give us our seconds set of data
						
						if (is_num(input)){ //call is_num function to check that our substr is a number -- otherwise we just ignore this line and get another line (beginning of loop)
							num_2 = stod(input); // put the substring into the double variable by using the string to double (stod) function
							shapelist.push_back(new rectangle(num_1, num_2)); //push back the new shape created in dynamic memory into the vector of shape pointers
						}
					}
				}
			}
		}
		calculations(shapelist); //call calculations functions that calculates and prints the area for all data in the vector
	} catch (exception& e){
		cout << e.what() << endl;
	}
	for (int i = 0; i < shapelist.size(); i++){ // now lets delete all the pointers we put into the vector such that there are no memory leaks
		delete shapelist[i]; // delete the pointer at index i
		shapelist[i] = nullptr; // set the index i to be a nullptr
	}

} //// END OF FUNCTION

bool is_num(string& input){ //function that checks if the string taken using substr is a numerical value or not
	double num_1 = 0; // variable to check if its a numerical value
	if (num_1 == 0){ // when the check variable is set to 0
		try { // lets try to 
			num_1 = stod(input); //convert the string (taken using substr) into a double... 
		} // this will fail if the data in input is not a numerical value
		catch(exception& e) { // so if that is the case -- lets use catch to send a false flag  
			return false; // return a false so we know that it is not a number
		}
	}
	return true; // if we can sucessfully convert into a double then we return a true value.
}

void calculations(vector <shape*> shapelist){ // function that sorts and the calulates and prints the area AND perimeter

	sort(shapelist.begin(), shapelist.end(), areacompare); // sort all vector data using the areacompare functions as the 3rd parameter
	for (int i = 0; i < shapelist.size(); i++){ // loop that iterates through every content in the vector
		cout << "area = " << shapelist[i]->area() << " -- "; // print the area of the shape with some formatting
		shapelist[i]->print(); // print the dimensions and name of shape
		cout << endl; //print blank line 
	}

	cout << endl;//print blank line 

	sort(shapelist.begin(), shapelist.end(), pericompare); // sort all vector data using the perimetercompare functions as the 3rd parameter
	for (int i = 0; i < shapelist.size(); i++){ // loop that iterates through every content in the vector
		cout << "perimeter = " << shapelist[i]->perimeter() << " -- "; // print the perimeter of the shape with some formatting
		shapelist[i]->print(); // print the dimensions and name of shape
		cout << endl; //print blank line 
	}
}

bool areacompare(const shape* a, const shape* b){ // used in sort as the 3rd paramater..compare area of two shapes as pointers

	int flag = 0; // flag to see what result is
	flag = a->shape::areacompare(*b); // put the two parameters into the areacompare function (in base class)
	if (flag == -1){ // if -1 is returned
		return true; // return true meaning that object is < parameter
	}
	return false; // otherwise retrunn false 
}

bool pericompare(const shape* a, const shape* b){ // used in sort as the 3rd paramater..compare perimeter of two shapes as pointers

	int flag = 0; // flag to see what result is
	flag = a->shape::perimetercompare(*b); // put the two parameters into the areacompare function (in base class)
	if (flag == -1){ // if -1 is returned
		return true; // return true meaning that object is < parameter
	}
	return false; // otherwise retrunn false 
}