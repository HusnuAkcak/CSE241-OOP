src = src
obj = main.o composedShape.o circle.o rectangle.o triangle.o polygon.o polyline.o
FLAG =  -std=c++11

output : $(obj)
	g++ $(FLAG) $(obj) -o output

main.o : main.cpp
	g++ $(FLAG) -c main.cpp

%.o : $(src)/%.cpp $(src)/%.h
	g++ $(FLAG) -c $<

clean :
	rm *.o output

# main.o : $(src)/main.cpp
# 	g++  -g -Wno-deprecated -std=c++11 -c main.cpp
