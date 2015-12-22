CXX	=  g++
CXXFLAGS=  -std=c++11 -Wall -pedantic -g

BINDIR	?= ../bin
OBJDIR	?= ../obj
ICOBJDIR=  $(OBJDIR)/libindigoc
ICGENDIR=  $(OBJDIR)/libindigoc_gen

TARGET  =  $(BINDIR)/libindigoc.a
SRCS    =  indigo.cpp package.cpp pass.cpp sourcefile.cpp loadpackage.cpp \
	   packagedb.cpp scheduler.cpp topleveldecl.cpp
OBJS	:= $(SRCS:%.cpp=$(ICOBJDIR)/%.o)
DEFSRCS	=  pdbfmt.fbs
GENHDRS	:= $(DEFSRCS:%.fbs=$(ICGENDIR)/%_generated.h)
INCLUDES=  -I$(ICGENDIR)

all: $(BINDIR) $(ICOBJDIR) $(ICGENDIR) $(TARGET)

$(TARGET): $(OBJS)
	$(AR) r $(TARGET) $(OBJS)

$(ICOBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

$(BINDIR) $(ICOBJDIR) $(ICGENDIR):
	mkdir -p $(BINDIR) $(ICOBJDIR) $(ICGENDIR)

$(GENHDRS): $(DEFSRCS)
	flatc --cpp -o $(ICGENDIR) $<

depend: $(GENHDRS)
	$(CXX) -MM $(CXXFLAGS) $(INCLUDES) $(SRCS) | sed 's|[^.]\{1,\}\.o:|$(ICOBJDIR)/&|' >deps.mk

clean:
	rm -f $(TARGET) $(OBJS) $(GENHDRS) *~

$(ICOBJDIR)/packagedb.o: $(ICGENDIR)/pdbfmt_generated.h

-include deps.mk
