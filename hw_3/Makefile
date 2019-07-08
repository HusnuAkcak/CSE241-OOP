src =src
obj = main.o base.o composedShape.o circle.o rectangle.o triangle.o
flag = -std=c++11
output : $(obj)
	g++ $(flag) $(obj) -o output

main.o : main.cpp
	g++ $(flag) -c main.cpp

%.o : $(src)/%.cpp $(src)/%.h
	g++ $(flag) -c $<

clean :
	rm *.o output
