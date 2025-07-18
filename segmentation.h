#ifndef SEGMENTATION_H
#define SEGMENTATION_H
#include "abstractalgorithm.h"
#include "opencv2/imgproc.hpp"
class Segmentation : public AbstractAlgorithm<cv::Mat, cv::Mat> {
public:
    Segmentation();
    Segmentation(const cv::Mat& input);
    enum State {
        eSuccess, eFailedTypeMismatch, eFailed
    };
    virtual ~Segmentation();
    virtual int run() = 0;
};

#endif // SEGMENTATION_H
