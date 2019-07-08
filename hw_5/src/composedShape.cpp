#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "composedShape.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

using namespace std;

namespace geometrical {

  ComposedShape::ComposedShape(Shape* newContainer, Shape* newSmallShape)noexcept {
    setContainer(newContainer);
    setSmallShape(newSmallShape);
  }
  // Copy constructor
  ComposedShape::ComposedShape(ComposedShape& newCmp)throw(bad_cast) {
    Shape *newShape;
    for(int i=0; i<newCmp.composed.size(); ++i) {
      if(dynamic_cast<Circle*>(newCmp.composed[i])!=nullptr){
        newShape= new Circle(*(dynamic_cast<Circle*>(newCmp.composed[i])) );
        composed.push_back(newShape);
      }
      else if(dynamic_cast<Rectangle*>(newCmp.composed[i])!=nullptr){
        newShape= new Rectangle(*(dynamic_cast<Rectangle*>(newCmp.composed[i])) );
        composed.push_back(newShape);
      }
      else if(dynamic_cast<Triangle*>(newCmp.composed[i])!=nullptr){
        newShape= new Triangle(*(dynamic_cast<Triangle*>(newCmp.composed[i])) );
        composed.push_back(newShape);
      }
      else {
        throw bad_cast();
      }
    }
  }
  // Assignmet operator overloading.
  ComposedShape&
  ComposedShape::operator =(const ComposedShape& newCmp) throw(bad_cast) {
    Shape *newShape;

    freeVector();//controls and free the memory that is currently use by object.

    for(int i=0; i<newCmp.composed.size(); ++i) {
      if(dynamic_cast<Circle*>(newCmp.composed[i])!=nullptr){
        newShape= new Circle(*(dynamic_cast<Circle*>(newCmp.composed[i])) );
        composed.push_back(newShape);
      }
      else if(dynamic_cast<Rectangle*>(newCmp.composed[i])!=nullptr){
        newShape= new Rectangle(*(dynamic_cast<Rectangle*>(newCmp.composed[i])) );
        composed.push_back(newShape);
      }
      else if(dynamic_cast<Triangle*>(newCmp.composed[i])!=nullptr){
        newShape= new Triangle(*(dynamic_cast<Triangle*>(newCmp.composed[i])) );
        composed.push_back(newShape);
      }
      else {
        throw bad_cast();
      }
    }
  }

  ComposedShape::ComposedShape()noexcept {
    /*intentionally empty */
  }

  ComposedShape::~ComposedShape()noexcept {
    freeVector();
  }

  void
  ComposedShape::freeVector()noexcept {
    for(int i=0; i<composed.size(); ++i) {
      if(composed[i]!=nullptr) {
        delete composed[i];
        composed[i]=nullptr;
      }
    }
    composed.clear();
  }

  Shape*
  ComposedShape::getContainer()noexcept {
    if(composed.size()>=1)
      return composed[0];
    else
      return nullptr;
  }
  Shape*
  ComposedShape::getSmallShape()noexcept {
    if(composed.size()>=2)
      return composed[1];
    else
      return nullptr;
  }
  vector<Shape*>
  ComposedShape::getShape()noexcept {
    return composed;
  }

  void
  ComposedShape::setContainer(Shape* newContainer)throw(bad_cast) {

    freeVector();// if container changes, whole design must be change.
    if(dynamic_cast<Circle*>(newContainer)!=nullptr){
      Circle *c =new Circle(*(dynamic_cast<Circle*>(newContainer)));
      c->setCenter(c->getRadius() ,c->getRadius() );
      composed.push_back(c);
    }
    else if(dynamic_cast<Rectangle*>(newContainer)!=nullptr){
      Rectangle *r =new Rectangle(*(dynamic_cast<Rectangle*>(newContainer)));
      r->setStartPoint(0,0);
      composed.push_back(r);
    }
    else if(dynamic_cast<Triangle*>(newContainer)!=nullptr){
      Triangle *t =new Triangle(*(dynamic_cast<Triangle*>(newContainer)));
      t->setPeakPoint(t->getEdge()/2, 0);
      composed.push_back(t);
    }
    else {
      throw bad_cast();
    }
    composed.push_back(nullptr); // for small shape.
    return;
  }

  void
  ComposedShape::setSmallShape(Shape* newSmallShape)
                                      throw(container_unavailable, bad_cast) {
    if(composed.size()!=2) {
      cout << "size problem\n";
      throw container_unavailable();
    }

    if(dynamic_cast<Circle*>(newSmallShape)!=nullptr){
      Circle *c =new Circle(*(dynamic_cast<Circle*>(newSmallShape)));
      composed[1]=c;
    }
    else if(dynamic_cast<Rectangle*>(newSmallShape)!=nullptr){
      Rectangle *r =new Rectangle(*(dynamic_cast<Rectangle*>(newSmallShape)));
      composed[1]=r;
    }
    else if(dynamic_cast<Triangle*>(newSmallShape)!=nullptr){
      Triangle *t =new Triangle(*(dynamic_cast<Triangle*>(newSmallShape)));
      composed[1]=t;
    }
    else {
      throw bad_cast();
    }
    return;
  }

  void
  ComposedShape::drawContainer(ostream& filePtr, int width, int height) {

    filePtr  << "<svg version=\"1.1\" baseProfile=\"full\" "
          << " width= \"" << width*1.5 << "\""
          << " height= \"" << height*1.5  << "\""
          << " xmlns=\"http://www.w3.org/2000/svg\"> "
          << endl << endl;
    return;
  }

  void
  ComposedShape::initSvgFile(ostream& filePtr)throw(container_unavailable) {

    // cout << "I am init svg file\n";
    Point2D tPeakNode, tLeftBtmNode, tRightBtmNode;  //  triangle nodes
    int circleRad, rectWidth, rectHeight, triangleEdge;
    //svg file is initialized.
    if(dynamic_cast<Circle*>(composed[0])!=nullptr){
      circleRad = dynamic_cast<Circle*>(composed[0])->getRadius();
      cout << "radius of circle : "<<circleRad<<endl;
      drawContainer(filePtr, circleRad*2, circleRad*2);
    }
    else if(dynamic_cast<Rectangle*>(composed[0])!=nullptr){
      rectWidth = dynamic_cast<Rectangle*>(composed[0])->getWidth();
      rectHeight= dynamic_cast<Rectangle*>(composed[0])->getHeight();
      drawContainer(filePtr, rectWidth, rectHeight);
    }
    else if(dynamic_cast<Triangle*>(composed[0])!=nullptr){
      triangleEdge = dynamic_cast<Triangle*>(composed[0])->getEdge();
      drawContainer(filePtr, triangleEdge, triangleEdge);
    }
    else {
      throw container_unavailable();
    }
    return ;
  }

  void
  ComposedShape::optimalFit()throw(container_unavailable, smallShape_unavailable) {

    if(dynamic_cast<Circle*>(composed[0])!=nullptr){
      if(dynamic_cast<Circle*>(composed[1])!=nullptr){
        fillCircleWithCircle();
      }
      else if(dynamic_cast<Rectangle*>(composed[1])!=nullptr){
        fillCircleWithRectangle();
      }
      else if(dynamic_cast<Triangle*>(composed[1])!=nullptr){
        fillCircleWithTriangle();
      }
      else {
        throw smallShape_unavailable();
      }
    }
    else if(dynamic_cast<Rectangle*>(composed[0])!=nullptr){
      if(dynamic_cast<Circle*>(composed[1])!=nullptr){
        fillRectangleWithCircle();
      }
      else if(dynamic_cast<Rectangle*>(composed[1])!=nullptr){
        fillRectangleWithRectangle();
      }
      else if(dynamic_cast<Triangle*>(composed[1])!=nullptr){
        fillRectangleWithTriangle();
      }
      else {
        throw smallShape_unavailable();
      }
    }
    else if(dynamic_cast<Triangle*>(composed[0])!=nullptr){
      if(dynamic_cast<Circle*>(composed[1])!=nullptr){
        fillTriangleWithCircle();
      }
      else if(dynamic_cast<Rectangle*>(composed[1])!=nullptr){
        fillTriangleWithRectangle();
      }
      else if(dynamic_cast<Triangle*>(composed[1])!=nullptr){
        fillTriangleWithTriangle();
      }
      else {
        throw smallShape_unavailable();
      }
    }
    else {
      throw container_unavailable();
    }
  }

  void
  ComposedShape::fillCircleWithCircle( ) {
    Circle container, smallShape;
    Circle *newSmall;
    double theta, totalArea, coveredArea;
    int count,
        containerRad, smallShapeRad,
        tempPosCol, tempPosRow, // pos of applicant small circle.
        designRadius;           // to determine pos of small circles.


    container =*(dynamic_cast<Circle*>(composed[0]));
    smallShape =*(dynamic_cast<Circle*>(composed[1]));
    if(composed[1]!=nullptr)
      delete composed[1];
    composed.erase (composed.begin()+1); // sample small shape is erased from vector

    count=0;
    containerRad=container.getRadius();
    smallShapeRad=smallShape.getRadius();
    cout << "circle in circle is being calculated..." << endl;
    for ( designRadius = (containerRad - smallShapeRad);
          designRadius >= smallShapeRad;
          designRadius -= (smallShapeRad*2)
        ) {
      for ( theta=0; theta <= (2*PI); theta+=(DEG/1000)) {
        // Possible small circle center is calculated.
        tempPosCol =  (containerRad +(designRadius) * cos(theta));
        tempPosRow =  (containerRad +(designRadius) * sin(theta));
        if (isCircleIntersectWithOtherCircles(tempPosCol, tempPosRow) == false) {
          smallShape.setCenter(tempPosCol, tempPosRow);
          newSmall = new Circle(smallShape);
          composed.push_back(newSmall);
          ++count;
          // cout  << "last item :"<<shape.back()[0].getCol()
          //       << " count is "<< count
          //       << " des_rad :"<<designRadius<<", theta: "<<theta<<endl;
        }
      }
    }
    totalArea = (PI * containerRad * containerRad );
    coveredArea = (count* PI * (smallShapeRad*smallShapeRad) );

    showCalcResults(count, totalArea, coveredArea);
    return;
  }

  void
  ComposedShape::fillCircleWithRectangle() {
    Point2D newRect;      //  applicant small rect start pos.
    Circle container = *(dynamic_cast<Circle*>(composed[0]));
    Rectangle smallShape = *(dynamic_cast<Rectangle*>(composed[1]));
    Rectangle *newSmallShape;
    double theta, totalArea, coveredArea;
    int count,
        circleRad,
        tolerance;  // some free space btw rect and circle to prevent intersection.

    // sample small shape is erased from vector
    if(composed[1]!=nullptr)
      delete composed[1];
    composed.erase (composed.begin()+1);

    cout << "rectangle in circle is being calculated...\n";
    count=0;
    tolerance = 2;
    circleRad = container.getRadius();
    for ( theta=(3*PI/2.0); theta >(PI/2.0) ; theta-=(DEG/100) ) { //from 8th to 7th octant of circle
      //applicant rectangle's top-left point.
      newRect.setRow(circleRad + tolerance +(circleRad * sin(theta)));
      newRect.setCol(circleRad + tolerance +(circleRad * cos(theta)));

      if(theta <= PI ) {  //lowerside of the circle (SVG direction is reverse)
        newRect.setRow(newRect.getRow()- smallShape.getHeight()*2 + tolerance);
        // it is shifted inside of circle.
      }

      if(composed.size() == 0 ||
        ((abs(smallShape.getStartPointRow() - newRect.getRow()) >=
                                          (smallShape.getHeight()) ) &&
          isRectInCircle(newRect) == true &&
          isRectIntersectToTheOthers(newRect) == false )) {

        smallShape.setStartPoint(newRect.getCol(), newRect.getRow());
        newSmallShape= new Rectangle(smallShape);
        composed.push_back(newSmallShape);
        ++count;
        //cout << "0002\n";
        //applicant rectangle's top-left point.
        newRect.setRow(smallShape.getStartPointRow());
        newRect.setCol(smallShape.getStartPointCol() + smallShape.getWidth());
        // then it is started to add rectangles next to prev one as much as possible.
        while ( isRectInCircle(newRect) ==true &&
                                isRectIntersectToTheOthers(newRect) == false ) {

          smallShape.setStartPoint(newRect.getCol(), newRect.getRow());
          newSmallShape= new Rectangle(smallShape);
          composed.push_back(newSmallShape);
          ++count;

          //applicant rectangle's top-left point.
          newRect.setRow(smallShape.getStartPointRow());
          newRect.setCol(smallShape.getStartPointCol() + smallShape.getWidth());
          //cout << "0003\n";

        }
      }
    }

    totalArea = (PI * circleRad * circleRad);
    coveredArea = (count*smallShape.getWidth()*smallShape.getHeight());
    showCalcResults(count, totalArea, coveredArea);
    return;
  }

  void
  ComposedShape::fillCircleWithTriangle() {
    Circle container =*(dynamic_cast<Circle*>(composed[0]));
    Triangle smallShape =*(dynamic_cast<Triangle*>(composed[1]));
    Triangle *newSmallShape=nullptr;
    Point2D newTri;      // last added small triangle.
    double theta, totalArea, coveredArea, height;
    bool reversed;
    int count, circleRad, triEdge,
        tolerance;// some free space btw triangle and circle to prevent intersection.

    if(composed[1]!=nullptr)
      delete composed[1];
    composed.erase (composed.begin()+1); // sample small shape is erased from vector
    cout << "triangle in circle is being calculated...\n";
    circleRad = container.getRadius();
    triEdge = smallShape.getEdge();
    height = sqrt(3.0)*triEdge/2.0;
    count=0;
    tolerance=triEdge/2;

    for ( theta=(3*PI/2.0); theta >=(PI/2) ; theta-=(DEG/100) ) { //from 8th to 7th octant of circle

      //applicant triangle's top-left point.
      newTri.setRow(circleRad+(circleRad * sin(theta)));
      if(theta>PI)//upside of the circle
        newTri.setCol(circleRad +tolerance + (circleRad * cos(theta)) );
      else  //underside of the circle
        newTri.setCol(circleRad +(tolerance*1.5) + (circleRad * cos(theta)) );

      //following if statement is a temporary solution and should be improved.
      if(isTriInCircle(newTri)==false )
        newTri.setCol(newTri.getCol()+(1.5*triEdge));

      // isTriInCirce function should be made strong and then it will be enought
      // to call only inTriInCircle in this statement.
      if((composed.size()== 0 ||
          (abs(smallShape.getPeakPointRow() - (newTri.getRow())) >= height)) &&
          isTriInCircle(newTri) ==true){

        smallShape.setPeakPoint(newTri.getCol(), newTri.getRow());
        //pushing to composed vector
        newSmallShape= new Triangle(smallShape);
        composed.push_back(newSmallShape);

        //applicant's top-left point.
        newTri.setRow(newTri.getRow() );
        newTri.setCol(newTri.getCol()+triEdge );
        // then it is started to add triangles next to prev one as much as possible.
        while ( isTriInCircle(newTri) ==true) {

          smallShape.setPeakPoint(newTri.getCol(), newTri.getRow());
          newSmallShape= new Triangle(smallShape);
          composed.push_back(newSmallShape);
          ++count;

          //applicant triangle's top-left.
          newTri.setRow(newTri.getRow());
          newTri.setCol(newTri.getCol() + triEdge);
        }
      }
    }
    totalArea = (PI * circleRad * circleRad);
    coveredArea = count*(sqrt(3.0)*(triEdge*triEdge)/4.0);
    showCalcResults(count, totalArea, coveredArea);
    return;
  }

  void
  ComposedShape::fillRectangleWithCircle() {
    Rectangle container =*(dynamic_cast<Rectangle*>(composed[0]));
    Circle smallShape =*(dynamic_cast<Circle*>(composed[1]));
    Circle *newSmallShape=nullptr;
    double totalArea, coveredArea;
    int count,
        horizSmallCircleNum, vertSmallCircleNum, //expected values
        r, c,       //  loop variables
        circleRad;  //  radius of the small circle
    if(composed[1]!=nullptr)
      delete composed[1];
    composed.erase (composed.begin()+1); // sample small shape is erased from vector
    circleRad = smallShape.getRadius();
    count=0;
    //  small circle numbers are calculated in horizontal and vertical.
    if(( container.getWidth() < circleRad*2) || (container.getHeight() < circleRad*2)) {
      cout << "Unfortunately, any circle could not be fit to the main container.\n";
      return;
    }
    else  {
        horizSmallCircleNum  = container.getWidth()/ (circleRad*2);
        vertSmallCircleNum = container.getHeight()/ (circleRad*2);
    }
    cout << "circle in rectangle is being calculated...\n";
    //  center of circles are determined.
    for (r=0;  r < vertSmallCircleNum; ++r) {
      for (c = 0; c < horizSmallCircleNum; ++c) {
        smallShape.setCenter(c*(circleRad*2)+circleRad, r*(circleRad*2)+circleRad);
        newSmallShape= new Circle(smallShape);
        composed.push_back(newSmallShape);
        ++count;
      }
    }
    totalArea = (container.getHeight()*container.getWidth());
    coveredArea = (count * PI*circleRad*circleRad );
    showCalcResults(count, totalArea, coveredArea);
    return;
  }

  //This function could be seperated two function.
  void
  ComposedShape::fillRectangleWithRectangle() {
    Rectangle container =*(dynamic_cast<Rectangle*>(composed[0]));
    Rectangle smallShape =*(dynamic_cast<Rectangle*>(composed[1]));
    Rectangle vertSmallShape;   //  height and width of small shape are swapped
    Rectangle *newSmallShape;
    double totalArea, coveredArea;
    int smallRectWidth, smallRectHeight, containerWidth, containerHeight;
    int count,              //  counter
        r, c;               //  loop variables

    smallRectWidth = smallShape.getWidth();
    smallRectHeight = smallShape.getHeight();
    containerWidth = container.getWidth();
    containerHeight = container.getHeight();

    if( (smallRectWidth * smallRectHeight) > (containerWidth*containerHeight) ){
      cout<< "Unfortunately, any small rectangle can not be fit to the main Container.\n";
      return;
    }

    vertSmallShape.setWidth(smallShape.getHeight());
    vertSmallShape.setHeight(smallShape.getWidth());

    // cout << "================================================================\n";
    // cout << "starting \n";
    // cout << "rect:"<<smallRectHeight << ", " <<smallRectWidth<<endl
    //     << "vertRect:"<<vertSmallShape.getHeight() <<", "<< vertSmallShape.getWidth()<<endl;
    // cout << "contd: "<<((containerHeight % smallRectHeight) <= (containerHeight % smallRectWidth))
    //      <<endl;
    // cout << "first : " << (containerHeight % smallRectHeight) <<endl;
    // cout << "sec : " << (containerHeight % smallRectWidth) <<endl;

    count=0;
    // It is wanted to keep as less as possible unused area at the top of stack.
    if((containerHeight % smallRectHeight) <= (containerHeight % smallRectWidth)){
      if(composed[1]!=nullptr)
        delete composed[1];
      composed.erase (composed.begin()+1); // sample small shape is erased from vector
      cout << "rectangle in rectangle is being calculated...\n";
      // cout <<"mh,mw: "
      //      <<(containerHeight % smallRectHeight) << ", "
      //      << (containerHeight % smallRectWidth)
      //      <<endl<<endl;

      // if normal form of smallShape is more efficient.
      for( r=0; r<=(containerHeight - smallRectHeight); r+= smallRectHeight){
        for ( c=0; c<= (containerWidth- smallRectWidth); c+= smallRectWidth ) {
          smallShape.setStartPoint(c, r);
          newSmallShape= new Rectangle(smallShape);
          composed.push_back(newSmallShape);
          ++count;
        }
      }

      //if we still have some area to fit rotated rectangle.
      if(   ((container.getStartPointCol() + vertSmallShape.getWidth()) <=
            (containerWidth) ) &&
            (containerHeight >= vertSmallShape.getHeight())
        ) {
            for ( c = container.getStartPointCol() + smallRectWidth;
                  vertSmallShape.getWidth() <= (containerWidth - c);
                  c += vertSmallShape.getWidth()
              ) {
                for ( r = 0;
                      vertSmallShape.getHeight() <= (containerHeight- r);
                      r += vertSmallShape.getHeight()
                ){
                  vertSmallShape.setStartPoint(c, r);
                  newSmallShape= new Rectangle(smallShape);
                  composed.push_back(newSmallShape);
                  ++count;
            }
          }
      }

      totalArea = (containerWidth * containerHeight);
      coveredArea =count*(smallRectWidth * smallRectHeight);
      showCalcResults(count, totalArea, coveredArea);
    }
    else {
      // if vertical version of small shape is more efficient "width" and
      // "height" are swapped then this function is recalled.
      *(dynamic_cast<Rectangle*>(composed[1])) = vertSmallShape;
      smallShape =*(dynamic_cast<Rectangle*>(composed[1]));
      fillRectangleWithRectangle();
    }
    return;
  }

  void
  ComposedShape::fillRectangleWithTriangle() {
    Rectangle container =*(dynamic_cast<Rectangle*>(composed[0]));
    Triangle smallShape =*(dynamic_cast<Triangle*>(composed[1]));
    Triangle *newSmallShape;
    double totalArea, coveredArea;
    int triEdge, containerWidth, containerHeight,
        count,  //  counter
        h,      //  height of the triangle
        r,c;    //  loop variables

    count = 0;
    cout << "triangle in rectangle is being calculated.\n";
    triEdge=smallShape.getEdge();
    containerWidth=container.getWidth();
    containerHeight = container.getHeight();
    h = (double(triEdge)/2.0) * (sqrt(3.0));
    if(composed[1]!=nullptr)
      delete composed[1];
    composed.erase (composed.begin()+1); // sample small shape is erased from vector

    //  plain triangles
    for( r=0; r<=(containerHeight - h); r+=h ) {
    for(c = double(triEdge)/ 2.0; c<=(containerWidth-(triEdge/2)); c += triEdge){
        smallShape.setPeakPoint(c,r);
        smallShape.setRotationAngle(0);
        newSmallShape= new Triangle(smallShape);
        composed.push_back(newSmallShape);
        ++count;
    }
    }

    //  reverse triangles
    for( r= h; r<= (containerHeight); r+= h ) {
    for( c= triEdge; c<= (containerWidth- triEdge); c+= triEdge ) {
      smallShape.setPeakPoint(c,r);
      smallShape.setRotationAngle(180);
      newSmallShape= new Triangle(smallShape);
      composed.push_back(newSmallShape);
      ++count;
    }
    }

    totalArea = (containerWidth * containerHeight);
    coveredArea =count* (double(triEdge* triEdge* sqrt(3))/ 4.0);
    showCalcResults(count, totalArea, coveredArea);
    return;
  }

  void
  ComposedShape::fillTriangleWithCircle() {
    Triangle container =*(dynamic_cast<Triangle*>(composed[0]));
    Circle smallShape =*(dynamic_cast<Circle*>(composed[1]));
    Circle *newSmallShape=nullptr;
    double radius, height, totalArea, coveredArea;
    int containerEdge,count, i, c, r;
    if(composed[1]!=nullptr)
      delete composed[1];
    composed.erase (composed.begin()+1); // sample small shape is erased from vector
    cout << "circle in triangle is being calculated.\n";
    count =0;
    i=0;
    containerEdge = container.getEdge();
    container.setPeakPoint(containerEdge/2, 0);
    radius = smallShape.getRadius();
    height = double(containerEdge)/2.0*(sqrt(3.0));
    for ( r =  height-radius; r >= (radius); r -= radius/sqrt(3.0)   ){
      for ( c= ((sqrt(3.)*i+2)*radius/sqrt(3.));
            c<= (r/sqrt(3.0)*2.0) -radius/sqrt(3.);
            c+= radius) {
        if(isCircleIntersectWithOtherCircles(c,r)==false){
          smallShape.setCenter(c,r);
          newSmallShape= new Circle(smallShape);
          composed.push_back(newSmallShape);
          ++count;
        }
      }
      ++i;
    }

    totalArea = (containerEdge*containerEdge)*sqrt(3)/4.0;
    coveredArea = count *( PI * radius* radius);
    showCalcResults(count, totalArea, coveredArea);
    return;
  }

  void
  ComposedShape::fillTriangleWithRectangle() {
    Triangle container =*(dynamic_cast<Triangle*>(composed[0]));
    Rectangle smallShape =*(dynamic_cast<Rectangle*>(composed[1]));
    Rectangle *newSmallShape=nullptr;
    double tHeight, r, c, i, totalArea, coveredArea;
    int count, triEdge, rectWidth, rectHeight;
    if(composed[1]!=nullptr)
      delete composed[1];
    composed.erase (composed.begin()+1); // sample small shape is erased from vector
    cout << "rectangle in triangle is being calculated.\n";
    i=1;
    count=0;
    rectWidth = smallShape.getWidth();
    rectHeight  = smallShape.getHeight();
    triEdge = container.getEdge();
    container.setPeakPoint(triEdge/2, 0);
    tHeight  = double(triEdge/2.0)*sqrt(3);
    for(r= tHeight- rectHeight; r>= (rectWidth/2.0)*sqrt(3.0); r-= rectHeight){
      for ( c = i*(rectHeight/sqrt(3.0));
            c <= triEdge-(i/sqrt(3.0)*rectHeight)-rectWidth;
            c += rectWidth
          ) {
            smallShape.setStartPoint(c, r);
            newSmallShape = new Rectangle(smallShape);
            composed.push_back(newSmallShape);
            ++count;
          }
          ++i;
        }

    totalArea = (triEdge*triEdge)*sqrt(3)/4.0;
    coveredArea = count*(rectWidth* rectHeight);
    showCalcResults(count, totalArea, coveredArea);
    return;
  }

  void
  ComposedShape::fillTriangleWithTriangle() {
    Triangle container =*(dynamic_cast<Triangle*>(composed[0]));
    Triangle smallShape =*(dynamic_cast<Triangle*>(composed[1]));
    Triangle *newSmallShape=nullptr;
    double  mainHeight, smallHeight,
            containerEdge, smallShapeEdge,
            totalArea, coveredArea, r, c, i;
    int count;
    if(composed[1]!=nullptr)
      delete composed[1];
    composed.erase (composed.begin()+1); // sample small shape is erased from vector
    cout << "triangle in triangle is being calculated.\n";
    i=1;
    count=0;
    containerEdge =container.getEdge();
    smallShapeEdge =smallShape.getEdge();
    container.setPeakPoint(containerEdge/2, 0);
    mainHeight  = double(containerEdge /2.0)*sqrt(3);
    smallHeight = double(smallShapeEdge / 2.0)*sqrt(3);

    for(r=mainHeight-smallHeight; r >= -smallHeight; r-=smallHeight ){
      //  plain small triangles are being determined.
      for ( c = i*((smallShapeEdge)/2.0);
            c <= (containerEdge - ((i/2.0)*smallShapeEdge));
            c += (smallShapeEdge)
      ) {
        smallShape.setPeakPoint(c,r);
        smallShape.setRotationAngle(0);
        newSmallShape = new Triangle(smallShape);
        composed.push_back(newSmallShape);
        ++count;
      }

      // reverse small triangles are being determined.
      for ( c = (i+1)*smallShapeEdge/2.0;
            c <= (containerEdge- ((i+1)*smallShapeEdge)/2);
            c += (smallShapeEdge)
      ) {
        smallShape.setPeakPoint(c,(r+smallHeight));
        smallShape.setRotationAngle(180);
        newSmallShape = new Triangle(smallShape);
        composed.push_back(newSmallShape);
        ++count;
      }
      ++i;
    }

    totalArea = (containerEdge*containerEdge)*sqrt(3)/4.0;
    coveredArea = count*((smallShapeEdge*smallShapeEdge)*sqrt(3)/4.0);
    showCalcResults(count, totalArea, coveredArea);
    return;
  }

  // In this case circle is small shape
  bool
  ComposedShape::isCircleIntersectWithOtherCircles(int smallCircleCenterCol,
                                                      int smallCircleCenterRow) {
    if(composed.size()<2)
      return false;

    Circle smallShape = *(dynamic_cast<Circle*>(composed[1]));
    Circle *circlePtr;
    bool intersect;
    double distance;
    int i;

    i=1;
    intersect = false;
    while ( intersect == false && i< composed.size() && composed[i]!=nullptr ) {
      // cout <<"first \n";
      circlePtr = dynamic_cast<Circle*>(composed[i]);
      // cout <<"sec \n";
      distance = sqrt( pow(((circlePtr->getCenterCol()-smallShape.getRadius() )-
                                                    smallCircleCenterCol), 2) +
                      pow((circlePtr->getCenterRow() - smallCircleCenterRow), 2) );
      if ( distance < (smallShape.getRadius()*2) )
        intersect = true;
      else {
        // cout << "circle center col: "<<composed[i][0].getCol()<<endl;
        // cout << "circle center row: "<<composed[i][0].getRow()<<endl;
        // cout << "i: "<<i<<endl;
      }
      ++i;
    }
    return intersect;
  }

  // in this case container is Circle and triangle is smallShape
  bool
  ComposedShape::isTriInCircle(Point2D &newTri){
    if(composed.size()<2)
      return true;
    Circle container =*(dynamic_cast<Circle*>(composed[0]));
    Triangle smallShape =*(dynamic_cast<Triangle*>(composed[1]));

    bool fit;
    double dist1, dist2, dist3;
    int circleRad;
    Point2D up, rightDown, leftDown;

    circleRad= container.getRadius();
    // applicant rectangle vertices.
    up     = newTri;
    leftDown.setRow(newTri.getRow() + sqrt(3.0)/2.0*smallShape.getEdge());
    leftDown.setCol(newTri.getCol() - smallShape.getEdge()/2 );
    rightDown.setRow(newTri.getRow() + sqrt(3.0)/2.0*smallShape.getEdge());
    rightDown.setCol(newTri.getCol() + smallShape.getEdge()/2 );

    // dist between new final point and main container center.
    dist1 =  calcDistBtwTwoPoint(up.getCol(), circleRad, up.getRow(), circleRad);
    dist2 =  calcDistBtwTwoPoint(leftDown.getCol(), circleRad, leftDown.getRow(), circleRad);
    dist3 =  calcDistBtwTwoPoint(rightDown.getCol(), circleRad, rightDown.getRow(), circleRad);

    if ( (dist1 >= circleRad) || (dist2 >= circleRad) || (dist3 >= circleRad) )
      return false;
    else
      return true;
  }

  // in this case container is a circle and small shape is a rectagnle.
  bool
  ComposedShape::isRectInCircle(Point2D &newRect) {
    Circle container;
    Rectangle smallShape;
    double dist1, dist2, dist3, dist4;
    int radius;
    Point2D rightUp, rightDown, leftUp, leftDown;

    radius = container.getRadius();
    // applicant rectangle vertices.
    leftUp     = newRect;
    leftDown.setRow(newRect.getRow() + smallShape.getHeight());
    leftDown.setCol(newRect.getCol());
    rightUp.setRow(newRect.getRow());
    rightUp.setCol(newRect.getCol() + smallShape.getWidth());
    rightDown.setRow(newRect.getRow() + smallShape.getHeight());
    rightDown.setCol(newRect.getCol() + smallShape.getWidth());

    // dist between new final point and main container center.
    dist1 = calcDistBtwTwoPoint(leftUp.getCol(), radius, leftUp.getRow(), radius);
    dist2 = calcDistBtwTwoPoint(leftDown.getCol(), radius, leftDown.getRow(), radius);
    dist3 = calcDistBtwTwoPoint(rightUp.getCol(), radius, rightUp.getRow(), radius);
    dist4 = calcDistBtwTwoPoint(rightDown.getCol(), radius, rightDown.getRow(), radius);


    if ((dist1 >= radius) || (dist2 >= radius) || (dist3 >= radius) || (dist4 >= radius))
      return false;
    else
      return true;
  }

  // in this case small shape is rectangle
  bool
  ComposedShape::isRectIntersectToTheOthers(Point2D & newRect) {
    Rectangle smallShape=*(dynamic_cast<Rectangle*>(composed[1]));
    bool intersect;
    int i;
    double distVert, distHoriz;

    intersect = false;
    i=1;
    while ( intersect == false && i<composed.size() ) {
      Rectangle *currRect = dynamic_cast<Rectangle*>(composed[i]);
      distVert  = abs((currRect->getStartPointRow()) - newRect.getRow());
      distHoriz = abs((currRect->getStartPointCol()) - newRect.getCol());

      if( distVert < smallShape.getHeight() &&
          distHoriz < smallShape.getWidth()    ){
        intersect = true;
      }
      ++i;
    }
    return intersect;
  }

  void
  ComposedShape::showCalcResults(int count, int totalArea, int coveredArea) {
    cout  << "\nResults...\n"
          << count<< " number small shape is fitted to main container.\n"
          << "Main container area : " << totalArea << endl
          << "Covered area : "        << coveredArea << endl
          << "Left empty space :" << totalArea - coveredArea << endl <<endl;
    return;
  }

  double
  ComposedShape::area()const {
    double totalArea=0;
    for(int i=0; i<composed.size(); ++i)
      totalArea += (composed[i]->area());
    return totalArea;
  }

  double
  ComposedShape::perimeter()const {
    double totalPerimeter=0;
    for(int i=0; i<composed.size(); ++i)
      totalPerimeter += (composed[i]->perimeter());
    return totalPerimeter;
  }

  ostream&
  operator << (ostream& outputStream, ComposedShape& cs) {

    cs.initSvgFile(outputStream);
    cs.print(outputStream);
    outputStream << "</svg>";
  }

   // print function, prints the shape in a svg file
  ostream&
  ComposedShape::print(ostream& outputStream) noexcept {
    for(int i=0; i<composed.size(); ++i) {
      composed[i]->print(outputStream);
    }
    return outputStream;
  }

  ComposedShape&
  ComposedShape::operator ++() noexcept {
    for(int i=0; i<composed.size(); ++i)
      composed[i]->operator++();
    return *this;
  }
  ComposedShape&
  ComposedShape::operator --() noexcept {
    for(int i=0; i<composed.size(); ++i)
      composed[i]->operator--();
    return *this;
  }
  ComposedShape&
  ComposedShape::operator ++(int) noexcept {
    ComposedShape *temp =new ComposedShape(*this);
    for(int i=0; i<composed.size(); ++i)
      composed[i]->operator++();
    return *temp;
  }
  ComposedShape&
  ComposedShape::operator --(int) noexcept {
    ComposedShape *temp =new ComposedShape(*this);
    for(int i=0; i<composed.size(); ++i)
      composed[i]->operator--();
    return *temp;
  }

  // comperison operators.
  bool ComposedShape::operator == (const Shape& sh2)const noexcept {
    double s1Area=0, s2Area=0;
    const ComposedShape *s2= dynamic_cast<const ComposedShape*>(&sh2);
    for(int i=0; i<composed.size(); ++i)
      s1Area += (composed[i]->area());

    for(int i=0; i<s2->composed.size(); ++i)
      s2Area += s2->composed[i]->area();

    if(s1Area == s2Area)
      return true;
    else
      return false;
  }
  bool ComposedShape::operator != (const Shape& sh2)const noexcept {
    double s1Area=0, s2Area=0;
    const ComposedShape *s2= dynamic_cast<const ComposedShape*>(&sh2);
    for(int i=0; i<composed.size(); ++i)
      s1Area += (composed[i]->area());

    for(int i=0; i<s2->composed.size(); ++i)
      s2Area += s2->composed[i]->area();

    if(s1Area == s2Area)
      return true;
    else
      return false;
  }
  bool ComposedShape::operator <  (const Shape& sh2)const noexcept {
    double s1Area=0, s2Area=0;
    const ComposedShape *s2= dynamic_cast<const ComposedShape*>(&sh2);
    for(int i=0; i<composed.size(); ++i)
      s1Area += (composed[i]->area());

    for(int i=0; i<s2->composed.size(); ++i)
      s2Area += s2->composed[i]->area();

    if(s1Area < s2Area)
      return true;
    else
      return false;
  }
  bool ComposedShape::operator <= (const Shape& sh2)const noexcept {
    double s1Area=0, s2Area=0;
    const ComposedShape *s2= dynamic_cast<const ComposedShape*>(&sh2);
    for(int i=0; i<composed.size(); ++i)
      s1Area += (composed[i]->area());

    for(int i=0; i<s2->composed.size(); ++i)
      s2Area += s2->composed[i]->area();
    if(s1Area <= s2Area)
      return true;
    else
      return false;
  }
  bool ComposedShape::operator >  (const Shape& sh2)const noexcept {
    double s1Area=0, s2Area=0;
    const ComposedShape *s2= dynamic_cast<const ComposedShape*>(&sh2);

    for(int i=0; i<composed.size(); ++i)
      s1Area += (composed[i]->area());

    for(int i=0; i<s2->composed.size(); ++i)
      s2Area += s2->composed[i]->area();

    if(s1Area > s2Area)
      return true;
    else
      return false;
  }
  bool ComposedShape::operator >= (const Shape& sh2)const noexcept {
    double s1Area=0, s2Area=0;
    const ComposedShape *s2= dynamic_cast<const ComposedShape*>(&sh2);

    for(int i=0; i<composed.size(); ++i)
      s1Area += (composed[i]->area());

    for(int i=0; i<s2->composed.size(); ++i)
      s2Area += s2->composed[i]->area();

    if(s1Area >= s2Area)
      return true;
    else
      return false;
  }

} //end of geometrical namespace
