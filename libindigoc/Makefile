CXX	=  g++
CXXFLAGS=  -std=c++11 -Wall -pedantic -g
CXXGENFLAGS=-std=c++11 -g

BINDIR	?= ../bin
OBJDIR	?= ../obj
ICOBJDIR=  $(OBJDIR)/libindigoc/obj
ICGENDIR=  $(OBJDIR)/libindigoc/gen

TARGET  =  $(BINDIR)/libindigoc.a
SRCS    =  indigo.cpp package.cpp pass.cpp sourcefile.cpp sourcecode.cpp \
	   loadpackage.cpp packagedb.cpp scheduler.cpp topleveldecl.cpp
OBJS	:= $(SRCS:%.cpp=$(ICOBJDIR)/%.o)
DEFSRC	=  pdbfmt.fbs
GENDEFHDR= $(ICGENDIR)/pdbfmt_generated.h
LEXSRC	=  igolexer.l
GENLEXSRC= $(ICGENDIR)/igolexer.tab.cpp
GENLEXHDR= $(ICGENDIR)/igolexer.tab.h
PARSRC	=  igoparser.y
GENPARSRC= $(ICGENDIR)/igoparser.tab.cpp
GENPARHDR= $(ICGENDIR)/igoparser.tab.h
GENSRCS	 = $(GENLEXSRC) $(GENPARSRC)
GENOBJS	:= $(GENSRCS:%.cpp=%.o)
INCLUDES=  -I$(ICGENDIR) -I/usr/local/include

all: $(BINDIR) $(ICOBJDIR) $(ICGENDIR) $(TARGET)

$(TARGET): $(OBJS) $(GENOBJS)
	$(AR) r $(TARGET) $(OBJS) $(GENOBJS)

$(ICOBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

$(ICGENDIR)/%.o: $(ICGENDIR)/%.cpp
	$(CXX) $(CXXGENFLAGS) $(INCLUDES) -o $@ -c $<

$(BINDIR) $(ICOBJDIR) $(ICGENDIR):
	mkdir -p $(BINDIR) $(ICOBJDIR) $(ICGENDIR)

$(GENDEFHDR): $(DEFSRC)
	flatc --cpp -o $(ICGENDIR) $<

$(GENLEXSRC) $(GENLEXHDR): $(LEXSRC) $(GENPARHDR)
	flex --outfile=$(GENLEXSRC) --header-file=$(GENLEXHDR) $(LEXSRC)

$(GENPARSRC) $(GENPARHDR): $(PARSRC)
	bison --output=$(GENPARSRC) --defines=$(GENPARHDR) $(PARSRC)

depend: $(GENDEFHDR) $(GENLEXHDR) $(GENPARHDR)
	$(CXX) -MM $(CXXFLAGS) $(INCLUDES) $(SRCS) | sed 's|[^.]\{1,\}\.o:|$(ICOBJDIR)/&|' >deps.mk

clean:
	rm -f $(TARGET) $(OBJS) $(GENOBJS) $(GENDEFHDR) $(GENLEXSRC) $(GENLEXHDR) $(GENPARSRC) $(GENPARHDR) *~


-include deps.mk
