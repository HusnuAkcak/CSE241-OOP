src = src
obj = main.o base.o calc.o fill_container.o circle.o rectangle.o triangle.o export.o presentation.o
output : $(obj)
	g++ $(obj) -std=c++11 -o output

main.o : main.cpp
	g++ -std=c++11 -c main.cpp

%.o : $(src)/%.cpp $(src)/%.h
	g++ -std=c++11 -c $<

clean :
	rm *.o output
