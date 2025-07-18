#include "edgedetection.h"

EdgeDetection::EdgeDetection() :
    AbstractAlgorithm<cv::Mat, cv::Mat>() {}

EdgeDetection::EdgeDetection(const cv::Mat &input) :
    AbstractAlgorithm<cv::Mat, cv::Mat>(input) {}

EdgeDetection::~EdgeDetection() {}
