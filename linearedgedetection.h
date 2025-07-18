#ifndef LINEAREDGEDETECTION_H
#define LINEAREDGEDETECTION_H
#include "edgedetection.h"

class LinearEdgeDetection : public EdgeDetection {
public:
    LinearEdgeDetection();
    LinearEdgeDetection(const cv::Mat& input, double threshold);

    virtual int run();

    double getThreshold () const {
        return mThreshold;
    }

    void setThreshold (double threshold) {
        mThreshold = threshold;
    }

private:
    std::vector <cv::Point> getNeighbours(const cv::Point& p);
    double distance (const cv::Point& p1, const cv::Point& p2);
    double mThreshold;
};

#endif // LINEAREDGEDETECTION_H
