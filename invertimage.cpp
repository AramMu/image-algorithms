#include "invertimage.h"

InvertImage::InvertImage() :
    AbstractAlgorithm<cv::Mat, cv::Mat> () {}

InvertImage::InvertImage(const cv::Mat& input) :
    AbstractAlgorithm<cv::Mat, cv::Mat> (input) {}

//InvertImage::~InvertImage() {}

int InvertImage::run() {
    getOutput() = cv::Mat (getInput().size(), getInput().type());
    for (int i = 0; i < getInput().rows; ++i) {
        for (int j = 0; j < getInput().cols; ++j) {
            switch (getInput().type()) {
            case CV_8UC1:
                getOutput().at <uchar> (i,j) = ~getInput().at <uchar> (i,j);
                break;
            case CV_8UC3:
                for (int k = 0; k < 3; ++k) {
                    getOutput().at <cv::Vec3b>(i,j)[k] = ~getInput().at <cv::Vec3b> (i,j)[k];
                }
                break;
            default:
                return eFailedTypeMismatch;
            }
        }
    }
    return eSuccess;
}
