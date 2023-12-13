#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

#define FILENAME "whistle.mp4"

int main(int argc, char *argv[]) {
  cv::namedWindow("whistle", cv::WINDOW_NORMAL);
  cv::setWindowProperty("whistle", cv::WND_PROP_FULLSCREEN,
                        cv::WINDOW_FULLSCREEN);

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
