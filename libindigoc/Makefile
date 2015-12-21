CXX	= g++
CXXFLAGS= -std=c++11 -Wall -pedantic -g

BINDIR	?= ../bin
OBJDIR	?= ../obj
ICOBJDIR= $(OBJDIR)/libindigoc

TARGET  = $(BINDIR)/libindigoc.a
SRCS    = indigo.cpp package.cpp pass.cpp sourcefile.cpp loadpackage.cpp \
	packagedb.cpp scheduler.cpp topleveldecl.cpp
OBJS    := $(SRCS:%.cpp=$(ICOBJDIR)/%.o)

all: $(BINDIR) $(ICOBJDIR) $(TARGET)

$(TARGET): $(OBJS)
	$(AR) r $(TARGET) $(OBJS)

$(ICOBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BINDIR):
	mkdir -p $(BINDIR)

$(ICOBJDIR):
	mkdir -p $(ICOBJDIR)

clean:
	rm -f $(TARGET) $(OBJS) *~

