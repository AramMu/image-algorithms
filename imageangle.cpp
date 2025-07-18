#include "imageangle.h"

ImageAngle::ImageAngle() :
    AbstractAlgorithm<std::pair<cv::Mat,cv::Mat>, cv::Mat> () {}

ImageAngle::ImageAngle(const std::pair<cv::Mat,cv::Mat>& input):
    AbstractAlgorithm<std::pair<cv::Mat,cv::Mat>, cv::Mat> (input) {}

int ImageAngle::run() {
    if (mInput.first.size() != mInput.second.size()) {
        return eFailedSizeMismatch;
    }
    mOutput = cv::Mat (mInput.first.size(), CV_32FC1);
    for (int i = 0; i < mInput.first.rows; ++i) {
        for (int j = 0; j < mInput.first.cols; ++j) {
            mOutput.at <float> (i,j) = std::atan2(mInput.second.at<float>(i,j), mInput.first.at<float>(i,j));
            if (mOutput.at<float>(i,j) < 0) {
                mOutput.at<float>(i,j) += 6.283;
            }
        }
    }
    return eSuccess;
}
