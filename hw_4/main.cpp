/////////////////////////////
// CSE 241 - HW4 /////////////
// Hüsnü AKÇAK   ////////////
// 161044112     ////////////
/////////////////////////////
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "src/circle.h"
#include "src/rectangle.h"
#include "src/triangle.h"
#include "src/composedShape.h"
#include "src/polygon.h"
#include "src/polyline.h"

#define ARR_SIZE 4
using namespace std;
using namespace svg;

int main () {
  string fileName;
  ofstream filePtr;
  int i,
      contCircleRad=200,
      contRectWidth=500,
      contRectHeight=200,
      contTriEdge=500,
      smallCircleRad=50,
      smallRectWidth=20,
      smallRectHeight=30,
      smallTriEdge=30;

  ComposedShape cmpShape1 [ARR_SIZE], cmpShape2 [ARR_SIZE], cmpShape3 [ARR_SIZE];
  Polygon contShape1 [ARR_SIZE];
  Polygon smallShape1 [ARR_SIZE];
  Polygon contShape2 [ARR_SIZE];
  Polygon smallShape2 [ARR_SIZE];
  Polygon contShape3 [ARR_SIZE];
  Polygon smallShape3 [ARR_SIZE];

  Circle contCircle [ARR_SIZE];
  Circle smallCircle [ARR_SIZE];
  Rectangle contRect [ARR_SIZE];
  Rectangle smallRect [ARR_SIZE];
  Triangle contTri [ARR_SIZE];
  Triangle smallTri [ARR_SIZE];

  for (i=0; i<ARR_SIZE; ++i) {
    smallCircle[i].setRadius((i+1)/1.5*smallCircleRad);
    smallRect[i].setWidth((i+1)*smallRectWidth);
    smallRect[i].setHeight((i+1)*smallRectHeight);
    smallTri[i].setEdge((i+1)*smallTriEdge);

    contCircle[i].setRadius(contCircleRad);
    contRect[i].setWidth(contRectWidth);
    contRect[i].setHeight(contRectHeight);
    contTri[i].setEdge(contTriEdge);
  }

  for (i =0; i< ARR_SIZE; ++i) {

    contShape1[i].setCircle(contCircle[i]);
    smallShape1[i].setCircle(smallCircle[i]);
    cmpShape1[i].setContainer(contShape1[i]);
    cmpShape1[i].setSmallShape(smallShape1[i]);
    cmpShape1[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-circle_in_circle-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape1[i];
    flush(filePtr);
    filePtr.close();

    contShape2[i].setRectangle(contRect[i]);
    smallShape2[i].setCircle(smallCircle[i]);
    cmpShape2[i].setContainer(contShape2[i]);
    cmpShape2[i].setSmallShape(smallShape2[i]);
    cmpShape2[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-circle_in_rect-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape2[i];
    flush(filePtr);
    filePtr.close();

    contShape3[i].setTriangle(contTri[i]);
    smallShape3[i].setCircle(smallCircle[i]);
    cmpShape3[i].setContainer(contShape3[i]);
    cmpShape3[i].setSmallShape(smallShape3[i]);
    cmpShape3[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-circle_in_tri-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape3[i];
    flush(filePtr);
    filePtr.close();
  }

  for (i =0; i< ARR_SIZE; ++i) {

    contShape1[i].setCircle(contCircle[i]);
    smallShape1[i].setRectangle(smallRect[i]);
    cmpShape1[i].setContainer(contShape1[i]);
    cmpShape1[i].setSmallShape(smallShape1[i]);
    cmpShape1[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-rect_in_circle-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape1[i];
    flush(filePtr);
    filePtr.close();

    contShape2[i].setRectangle(contRect[i]);
    smallShape2[i].setRectangle(smallRect[i]);
    cmpShape2[i].setContainer(contShape2[i]);
    cmpShape2[i].setSmallShape(smallShape2[i]);
    cmpShape2[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-rect_in_rect-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape2[i];
    flush(filePtr);
    filePtr.close();

    contShape3[i].setTriangle(contTri[i]);
    smallShape3[i].setRectangle(smallRect[i]);
    cmpShape3[i].setContainer(contShape3[i]);
    cmpShape3[i].setSmallShape(smallShape3[i]);
    cmpShape3[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-rect_in_tri-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape3[i];
    flush(filePtr);
    filePtr.close();
  }


  for (i =0; i< ARR_SIZE; ++i) {

    contShape1[i].setCircle(contCircle[i]);
    smallShape1[i].setTriangle(smallTri[i]);
    cmpShape1[i].setContainer(contShape1[i]);
    cmpShape1[i].setSmallShape(smallShape1[i]);
    cmpShape1[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-tri_in_circle-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape1[i];
    flush(filePtr);
    filePtr.close();

    contShape2[i].setRectangle(contRect[i]);
    smallShape2[i].setTriangle(smallTri[i]);
    cmpShape2[i].setContainer(contShape2[i]);
    cmpShape2[i].setSmallShape(smallShape2[i]);
    cmpShape2[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-tri_in_rect-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape2[i];
    flush(filePtr);
    filePtr.close();

    contShape3[i].setTriangle(contTri[i]);
    smallShape3[i].setTriangle(smallTri[i]);
    cmpShape3[i].setContainer(contShape3[i]);
    cmpShape3[i].setSmallShape(smallShape3[i]);
    cmpShape3[i].optimalFit();
    fileName = "results/"+to_string((i+1))+"-tri_in_tri-shape.svg";
    filePtr.open(fileName);
    filePtr<<cmpShape3[i];
    flush(filePtr);
    filePtr.close();
  }
  cout << "Automatic shape generation is finished...\n\n";

  /*POLYLINE CLASS TEST IS START  */
  Polyline sampleLine [6];

  sampleLine[0]= contRect[0];   //Polyline takes a Rectangle object.
  //Polyline takes a Triangle object.
  contTri[0].setPeakPoint(contTri[0].getEdge()/2.0, 0);
  sampleLine[1]= contTri[0];
  //Polyline takes a Circle object.
  contCircle[0].setCenter(contCircle[0].getRadius(), contCircle[0].getRadius());
  sampleLine[2]= contCircle[0];

  vector<Polygon::Point2D> lineVector;
  Polygon::Point2D tempPoint;
  tempPoint.setCol(40);
  tempPoint.setRow(40);
  lineVector.push_back(tempPoint);
  tempPoint.setCol(25);
  tempPoint.setRow(35);
  lineVector.push_back(tempPoint);
  tempPoint.setCol(140);
  tempPoint.setRow(100);
  lineVector.push_back(tempPoint);
  tempPoint.setCol(80);
  tempPoint.setRow(15);
  lineVector.push_back(tempPoint);
  tempPoint.setCol(77);
  tempPoint.setRow(33);
  lineVector.push_back(tempPoint);

  sampleLine[3]=lineVector; // Polyline takes a Polygon::Point2D vector.

  // Polyline takes Polygon::Poin2D object.
  sampleLine[4] = Polygon::Point2D(99, 33);
  sampleLine[4] =(sampleLine[4].getPolygon() +
           Polygon(Polygon::Point2D(10, 50)));//'+' operator overloading

  contCircle[1].setCenter(contCircle[1].getRadius(), contCircle[1].getRadius());
  sampleLine[5] = Polygon(contCircle[1]); // Polyline takes Polygon object.

  for (int i=0; i<6; ++i) {
    fileName = "results/_"+to_string((i+1))+"-polyline.svg";
    filePtr.open(fileName);
    sampleLine[i].initSvgFile(filePtr);
    filePtr<<sampleLine[i];
    filePtr<<"</svg>";
    flush(filePtr);
    filePtr.close();
  }
  /*POLYLINE CLASS TEST IS END    */

  cout<< "If you want to see the result of user input enter 'y', otherwise give another entry.\n";
  char selection;
  cin >> selection;
  if(selection=='y' || selection =='Y'){
    ComposedShape cmp1;
    cmp1.input();
    cmp1.optimalFit();
    fileName = "results/user_input.svg";
    filePtr.open(fileName);
    filePtr << cmp1;
  }
  return 0;
}
