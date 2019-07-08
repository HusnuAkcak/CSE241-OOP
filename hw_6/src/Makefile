FLAGS := -g -Wno-deprecated --std=c++11 -pedantic -Wall
SRCS := main.cpp hashSet.cpp arrayList.cpp linkedList.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

.PHONY: all clean

all: prog

prog: $(OBJS)
	$(CXX) $(FLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(FLAGS) -c -MMD -o $@ $<

clean:
	$(RM) prog $(OBJS) $(DEPS)

-include $(DEPS)
