CXX	= g++
INCLUDES= -I../libindigoc
CXXFLAGS= -std=c++11 -Wall -pedantic -g $(INCLUDES)
LIBS	= $(BINDIR)/libindigoc.a -llmdb -lflatbuffers

BINDIR	?= ../bin
OBJDIR	?= ../obj
IGOOBJDIR= $(OBJDIR)/igo

TARGET  = $(BINDIR)/igo
SRCS    = main.cpp
OBJS    := $(SRCS:%.cpp=$(IGOOBJDIR)/%.o)

all: $(BINDIR) $(IGOOBJDIR) $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

$(IGOOBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BINDIR):
	mkdir -p $(BINDIR)

$(IGOOBJDIR):
	mkdir -p $(IGOOBJDIR)

clean:
	rm -f $(TARGET) $(OBJS) *~

