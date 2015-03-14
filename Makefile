ROOT_DIR := $(shell pwd)
SOURCE_DIR := $(ROOT_DIR)/source
OBJECT_DIR := $(ROOT_DIR)/objects
DEBUG_OBJECT_DIR := $(OBJECT_DIR)/debug
RELEASE_OBJECT_DIR := $(OBJECT_DIR)/release
BINARY_DIR := $(ROOT_DIR)/binaries
LIBRARY_DIR := $(ROOT_DIR)/libraries
INCLUDE_DIR := $(ROOT_DIR)/include

RELEASE_BINARY := $(BINARY_DIR)/mech
DEBUG_BINARY := $(RELEASE_BINARY)-dbg

LIBRARIES := -lSDL2main -lSDL2 -ldl -lpthread

SOURCES := $(shell find $(SOURCE_DIR) -name "*.cpp")
RELEASE_OBJECTS := $(addprefix $(RELEASE_OBJECT_DIR)/, $(notdir $(SOURCES:.cpp=.o)))
DEBUG_OBJECTS := $(addprefix $(DEBUG_OBJECT_DIR)/, $(notdir $(SOURCES:.cpp=.o)))

CXX := g++
CXXFLAGS := -std=c++11 -Wall -Werror -I $(INCLUDE_DIR) -DPLATFORM_LINUX
LDFLAGS := -L $(LIBRARY_DIR) $(LIBRARIES)

VPATH := $(shell find $(SOURCE_DIR) -type d)

TAGS := $(SOURCE_DIR)/TAGS

.PHONY: default debug release clean tags

default: release

clean:
	rm -rf $(OBJECT_DIR)
	rm -rf $(BINARY_DIR)
	rm -rf $(TAGS)

debug: CXXFLAGS += -g
debug: dirs $(DEBUG_BINARY)

release: CXXFLAGS += -O2 -DNDEBUG
release: dirs $(RELEASE_BINARY)

dirs:
	mkdir -p $(DEBUG_OBJECT_DIR)
	mkdir -p $(RELEASE_OBJECT_DIR)
	mkdir -p $(BINARY_DIR)

tags: $(TAGS)

$(RELEASE_BINARY): $(RELEASE_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(DEBUG_BINARY): $(DEBUG_OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(RELEASE_OBJECT_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DEBUG_OBJECT_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TAGS):
	find $(SOURCE_DIR) -name "*.cpp" -o -name "*.h" | etags -o $(ROOT_DIR)/TAGS -
