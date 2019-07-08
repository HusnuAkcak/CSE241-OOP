#include <iostream>
#include <fstream>
#include <string>
#include "shape.h"


using namespace std;

namespace geometrical {
    //GLOBAL FUNCTIONS (TWO OF THEM) STARTS
    void 
    printAll(const vector<Shape*>& shapes)noexcept {
        string fileName;
        ofstream filePtr;

        fileName="results/printAll_Shapes.svg";
        filePtr.open(fileName); //open file pointer

        //init the svg file 
        filePtr << "<svg version=\"1.1\" baseProfile=\"full\" "
                << " width= \"" << 1000 << "\""
                << " height= \"" <<  1000 << "\""
                << " xmlns=\"http://www.w3.org/2000/svg\"> "
                << endl << endl;

        for(int i=0; i<shapes.size(); ++i) {
            shapes[i]->print(filePtr);
        }
        
        filePtr << "</svg>"; // svg is closed.

        cout << "output svg file name: "<< fileName<<endl;
        cout << "--------------------------------------\n";
        
        filePtr.close();
        filePtr.clear();
        return;
    }

    // sort increasing order 
    void 
    sortShapes(vector<Shape*>& shapes)noexcept {
        Shape* temp;

        for (int i=0; i<shapes.size(); ++i){
            for (int j=i+1; j<shapes.size(); ++j) {
                if(shapes[j]->area() < shapes[i]->area()) {
                    temp = shapes[i];
                    shapes[i] = shapes[j];
                    shapes[j] = temp;
                }
            }
        }
        return;
    }
    //GLOBAL FUNCTIONS (TWO OF THEM) ENDS

    // comperison operators.
    inline bool 
    Shape::operator == (const Shape& s2)const noexcept {
        return ((*this).area() == s2.area()) ? true : false;
    }

    inline bool 
    Shape::operator != (const Shape& s2)const noexcept {
        return ((*this).area() != s2.area()) ? true : false;
    }

    inline bool 
    Shape::operator <  (const Shape& s2)const noexcept {
        return ((*this).area() < s2.area()) ? true : false;
    }

    inline bool 
    Shape::operator <= (const Shape& s2)const noexcept {
        return ((*this).area() <= s2.area()) ? true : false;
    }

    inline bool 
    Shape::operator >  (const Shape& s2)const noexcept {
        return ((*this).area() > s2.area()) ? true : false;
    }

    inline bool 
    Shape::operator >= (const Shape& s2)const noexcept {
        return ((*this).area() >= s2.area()) ? true : false;
    }
} //end of geometrical namespace.

