#include "imagegradient.h"
#include "opencv2/highgui.hpp"
ImageGradient::ImageGradient() :
    AbstractAlgorithm<cv::Mat, std::pair<cv::Mat,cv::Mat> > () {}

ImageGradient::ImageGradient(const cv::Mat& input) :
    AbstractAlgorithm<cv::Mat, std::pair<cv::Mat,cv::Mat> > (input) {}

int ImageGradient::run() {

    if (mInput.type() != CV_8UC1) {
        return eFailedTypeMismatch;
    }
    //cv::Mat gradX (mInput.size(), CV_32FC1);
    //cv::Mat gradY (mInput.size(), CV_32FC1);
    cv::Mat kernelX (1, 3, CV_32FC1);
    cv::Mat kernelY (3, 1, CV_32FC1);

    kernelX.at<float> (0, 0) = -1;
    kernelX.at<float> (0, 1) = 0;
    kernelX.at<float> (0, 2) = 1;
    kernelY.at<float> (0, 0) = -1;
    kernelY.at<float> (1, 0) = 0;
    kernelY.at<float> (2, 0) = 1;

    //kernelX << (-1, 0, 1);
    //kernelY << (-1, 0, 1);
    cv::filter2D(mInput, mOutput.first, CV_32F, kernelX);
    cv::filter2D(mInput, mOutput.second, CV_32F, kernelY);
    //cv::imshow ("gradx", gradX);
    //cv::imshow ("grady", gradY);
    //applyMatrix (mInput, gradX, kernelX);
    //applyMatrix (mInput, gradY, kernelY);
    //mOutput = cv::Mat (mInput.size(), CV_32FC1);
    //gradX = gradX * gradX;
    //gradY = gradY * gradY;
    //cv::multiply(gradX, gradX, gradX);
    //cv::multiply(gradY, gradY, gradY);
    //cv::sqrt (gradX+gradY, mOutput);

    return eSuccess;
}
