CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC_DIR = nowindow

ifeq ($(OS),Windows_NT)
	SRCS = $(SRC_DIR)/nogui.cpp \
				 $(SRC_DIR)/cmd_windows.cpp \
				 log.cpp \
				 start.cpp
else 
	SRCS = $(SRC_DIR)/terminal_linux.cpp \
				 $(SRC_DIR)/nogui.cpp \
				 log.cpp \
				 start.cpp
endif

OBJS = $(SRCS:.cpp=.o)
TARGET = lublu

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
