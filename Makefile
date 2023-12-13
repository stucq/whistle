SOURCE ?= src
OBJECT ?= obj
TARGET ?= bin

OPENCV_CPPFLAGS :=
OPENCV_LDFLAGS := -lopencv_core -lopencv_highgui -lopencv_videoio

ifeq ($(OS),Windows_NT)
	OPENCV_LDFLAGS += -lwindows
else
	OPENCV_LDFLAGS += -lX11
endif

.PHONY: all

all: $(TARGET)/opencv

$(TARGET)/opencv: $(OBJECT)/opencv/main.o $(OBJECT)/opencv/size.o
	g++ $(OBJECT)/opencv/main.o $(OBJECT)/opencv/size.o $(OPENCV_LDFLAGS) -o $(TARGET)/opencv

$(OBJECT)/opencv/main.o: $(OBJECT)/opencv $(SOURCE)/opencv/main.cpp
	g++ $(SOURCE)/opencv/main.cpp $(OPENCV_CPPFLAGS) -c -o $(OBJECT)/opencv/main.o

$(OBJECT)/opencv/size.o: $(OBJECT)/opencv $(SOURCE)/opencv/size.cpp
	g++ $(SOURCE)/opencv/size.cpp $(OPENCV_CPPFLAGS) -c -o $(OBJECT)/opencv/size.o

$(OBJECT)/opencv: $(OBJECT)
	mkdir -p $(OBJECT)/opencv

$(OBJECT):
	mkdir -p $(OBJECT)

$(TARGET):
	mkdir -p $(TARGET)
