CXX	=g++
CXXFLAGS=-std=c++11 -Wall -pedantic -g
LIBS=	-llmdb -lcapnp -lkj

TARGET  = libindigoc.a
SRCS    = indigo.cpp package.cpp pass.cpp sourcefile.cpp loadpackage.cpp \
	packagedb.cpp scheduler.cpp topleveldecl.cpp
OBJS    := $(SRCS:%.cpp=%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) r $(TARGET) $(OBJS)

clean:
	rm -f $(TARGET) $(OBJS) *~

