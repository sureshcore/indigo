CXX	= g++
CXXFLAGS=-std=c++11 -Wall -pedantic -g
LIBS=	../libindigoc.a

TARGET  = igo
SRCS    = main.cpp
OBJS    := $(SRCS:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(TARGET) $(OBJS) *~

