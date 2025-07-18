#include "imagehog.h"

ImageHog::ImageHog() :
    AbstractAlgorithm<cv::Mat, std::vector<int> > () {}

ImageHog::ImageHog(const cv::Mat& input, int divCount) :
    AbstractAlgorithm<cv::Mat, std::vector<int> > (input),
    divCount (divCount) {}

int ImageHog::run (){
    if (divCount <= 0) {
        return eFailedInvalidCount;
    }
    if (mInput.type() != CV_32FC1) {
        return eFailedTypeMismatch;
    }
    mOutput = std::vector <int> (divCount);
    const double pi = 3.1425;
    for (int i = 0; i < mInput.rows; ++i) {
        for (int j = 0; j < mInput.cols; ++j) {
            int ind = mInput.at<float> (i,j) / (2*pi) * divCount;
            if (ind < 0 || ind >= divCount) {
                return eFailedAngleOutOfRange;
            }
            mOutput[ind]++;
        }
    }
    return eSuccess;
}
