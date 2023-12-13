#include <chrono>
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <system_error>

#include "size.hpp"

#define FILENAME "whistle.mp4"
#define START_TIME 0 // change this!

int main(int argc, char *argv[]) {
  cv::namedWindow("whistle", cv::WINDOW_NORMAL);
  cv::setWindowProperty("whistle", cv::WND_PROP_FULLSCREEN,
                        cv::WINDOW_FULLSCREEN);

  Size *size = new Size();
  cv::Mat empty = cv::Mat::zeros(size->height, size->width, CV_8UC1);

  while (1) {
    // 1. write blank screen

    cv::imshow("whistle", empty);

    // 2. check the time

    auto time = std::chrono::system_clock::now();

    int timestamp = std::chrono::duration_cast<std::chrono::seconds>(
                        time.time_since_epoch())
                        .count();

    if (timestamp == START_TIME)
      break;

    // 3. check for escape

    char input = cv::waitKey();

    if (input == 27)
      break;
  }

  cv::VideoCapture capture(FILENAME);

  if (!capture.isOpened()) {
    std::cerr << "error: could not find the file " FILENAME << std::endl;
    return -1;
  }

  cv::Mat frame;

  while (1) {
    if (!capture.read(frame))
      break;

    cv::imshow("whistle", frame);

    char input = cv::waitKey(33);

    if (input == 27)
      break;
  }

  capture.release();
  cv::destroyWindow("whistle");

  return 0;
}
