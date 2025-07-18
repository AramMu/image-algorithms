#ifndef EDGEDETECTION_H
#define EDGEDETECTION_H
#include "abstractalgorithm.h"
#include <opencv2/imgproc.hpp>

class EdgeDetection : public AbstractAlgorithm<cv::Mat,cv::Mat> {
public:
    EdgeDetection();
    EdgeDetection(const cv::Mat& input);
    virtual ~EdgeDetection();
    virtual int run() = 0;
};

#endif // EDGEDETECTION_H
