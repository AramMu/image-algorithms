#include "segmentation.h"

Segmentation::Segmentation() :
    AbstractAlgorithm<cv::Mat, cv::Mat>() {}

Segmentation::Segmentation(const cv::Mat &input) :
    AbstractAlgorithm<cv::Mat, cv::Mat>(input) {}

Segmentation::~Segmentation() {}
