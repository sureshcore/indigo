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
DEFSRC	=  pdbfmt.fbs
GENDEFHDR= pdbfmt_generated.h
LEXSRC	=  igolexer.l
GENLEXSRC= igolexer.tab.cpp
GENLEXHDR= igolexer.tab.h
PARSRC	=  igoparser.y
GENPARSRC= igoparser.tab.cpp
GENPARHDR= igoparser.tab.h
INCLUDES=  -I$(ICGENDIR) -I/usr/local/include

all: $(BINDIR) $(ICOBJDIR) $(ICGENDIR) $(TARGET)

$(TARGET): $(OBJS)
	$(AR) r $(TARGET) $(OBJS)

$(ICOBJDIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ -c $<

$(BINDIR) $(ICOBJDIR) $(ICGENDIR):
	mkdir -p $(BINDIR) $(ICOBJDIR) $(ICGENDIR)

$(GENDEFHDR): $(DEFSRC)
	flatc --cpp -o $(ICGENDIR) $<

$(GENLEXSRC) $(GENLEXHDR): $(LEXSRC)
	flex --outfile=$(GENLEXSRC) --header-file=$(GENLEXHDR) $(LEXSRC)

$(GENPARSRC) $(GENPARHDR): $(PARSRC)
	bison --output=$(GENPARSRC) --defines=$(GENPARHDR) $(PARSRC)

depend: $(GENDEFHDR)
	$(CXX) -MM $(CXXFLAGS) $(INCLUDES) $(SRCS) | sed 's|[^.]\{1,\}\.o:|$(ICOBJDIR)/&|' >deps.mk

clean:
	rm -f $(TARGET) $(OBJS) $(GENDEFHDR) *~

$(ICOBJDIR)/packagedb.o: $(ICGENDIR)/pdbfmt_generated.h

-include deps.mk
