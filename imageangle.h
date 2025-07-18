#ifndef IMAGEANGLE_H
#define IMAGEANGLE_H

#include "abstractalgorithm.h"
#include <opencv2/imgproc.hpp>

class ImageAngle : public AbstractAlgorithm<std::pair<cv::Mat,cv::Mat>, cv::Mat> {
public:
    enum State {
        eSuccess, eFailedTypeMismatch, eFailedSizeMismatch, eFailed
    };
    ImageAngle();
    ImageAngle(const std::pair<cv::Mat,cv::Mat>& input);
    virtual int run();
};

#endif // IMAGEANGLE_H
