#pragma once

#include <cmath>

using namespace std;

 

class shape
{
public:

       // All base classes should have a virtual destructor so that derived
       // classes can implement their own destructor if needed
       virtual ~shape() {}

       // Returns the area of the shape
       virtual double area() const = 0;
       // Returns the perimeter of the shape
       virtual double perimeter() const = 0;
       
       // Prints the shape: <shape>: <attributes>
       // e.g. circle: radius = 12.3
       //      rectangle: width = 3, height = 5.2
       virtual void print() const = 0;

       int areacompare(const shape& sh) const;
       int perimetercompare(const shape& sh) const;

};

 

// Compares the area of two shapes of any type.
// Returns: -1 if calling object is < parameter
//           0 if calling object = parameter
//          +1 if calling object > parameter
// Shape areas are considered to be equal if they differ by less
// than 0.001
int shape::areacompare(const shape& sh) const
{
       if (fabs(area() - sh.area()) < 0.001) {
              return 0;
       }
       else if (area() < sh.area()) {
              return -1;
       }
       else {
              return 1;
       }

}

// Compares the perimeter of two shapes of any type.
// Returns: -1 if calling object is < parameter
//           0 if calling object = parameter
//          +1 if calling object > parameter
// Shape perimeters are considered to be equal if they differ by less
// than 0.001
int shape::perimetercompare(const shape& sh) const
{
       if (fabs(perimeter() - sh.perimeter()) < 0.001) {
              return 0;
       }
       else if (perimeter() < sh.perimeter()) {
              return -1;
       }
       else {
             return 1;
       }
}