src =src
obj = main.o base.o shape.o composedShape.o circle.o rectangle.o triangle.o

output : $(obj)
	g++ -std=c++11 $(obj) -o output

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

%.o : $(src)/%.cpp $(src)/%.h
	g++ -std=c++11 -c $<

clean :
	rm *.o output
