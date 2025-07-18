#ifndef IMAGEGRADIENT_H
#define IMAGEGRADIENT_H
#include "abstractalgorithm.h"
#include <opencv2/imgproc.hpp>

class ImageGradient : public AbstractAlgorithm<cv::Mat, std::pair<cv::Mat,cv::Mat> > {
public:
    enum State {
        eSuccess, eFailedTypeMismatch, eFailed
    };
    ImageGradient();
    ImageGradient(const cv::Mat& img);
    virtual int run();
};

#endif // IMAGEGRADIENT_H
