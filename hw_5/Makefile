src = src
obj = main.o shape.o composedShape.o circle.o rectangle.o triangle.o polygon.o polygonDyn.o polygonVect.o point2d.o
flag = -g -std=c++11

output : $(obj)
	g++ $(flag) $(obj) -o output

main.o : main.cpp
	g++ $(flag) -c main.cpp

%.o : $(src)/%.cpp $(src)/%.h
	g++ $(flag) -c $<

clean :
	rm *.o output
