WX_CONFIG := wx-config
WX_CXXFLAGS := $(shell $(WX_CONFIG) --cxxflags)
WX_LIBS := $(shell $(WX_CONFIG) --libs)

APPLICATION := name
OBJECTS := mainframe.o app.o

LIBS += -lcurl -ljsoncpp `wx-config --libs net`
LIBS += /usr/lib/x86_64-linux-gnu/libsqlite3.so.0

CXXFLAGS += `wx-config --cxxflags net`

all: $(APPLICATION)

$(APPLICATION): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS) $(LDFLAGS) $(WX_LIBS) $(LIBS)

$(OBJECTS): %.o: %.cpp
	$(CXX) -c -o $@ $(WX_CXXFLAGS) $(CXXFLAGS) $<

.PHONY: clean
clean:
	find . -name '*~' -o -name '*.o' -o -name $(APPLICATION) | xargs rm
