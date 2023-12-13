SOURCE?=src
TARGET?=bin

.PHONY: all

all: $(TARGET)/opencv

$(TARGET)/opencv: $(TARGET) src/opencv
	g++ $(SOURCE)/opencv/main.cpp -lopencv_core -lopencv_highgui -lopencv_videoio -o $(TARGET)/opencv

$(TARGET):
	mkdir -p $(TARGET)
