SOURCE?=src
TARGET?=bin

.PHONY: all

all: $(TARGET)/opencv

$(TARGET)/opencv: $(TARGET) src/opencv
	g++ \
		$(SOURCE)/opencv/main.cpp \
		$(SOURCE)/opencv/size.cpp \
		-lopencv_core \
		-lopencv_highgui \
		-lopencv_videoio \
		-lX11 \
		-o $(TARGET)/opencv

$(TARGET):
	mkdir -p $(TARGET)
