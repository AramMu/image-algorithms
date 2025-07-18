#ifndef LINEARSEGMENTATION_H
#define LINEARSEGMENTATION_H
#include "segmentation.h"

class LinearSegmentation : public Segmentation {
public:
    LinearSegmentation();
    LinearSegmentation(const cv::Mat& input, double threshold);
    virtual int run();
    double getThreshold () const {
        return mThreshold;
    }

    void setThreshold (double threshold) {
        mThreshold = threshold;
    }

    int getComponentCount();

private:
    std::vector <cv::Point> getNeighbours(const cv::Point& p);
    double distance (const cv::Point& p1, const cv::Point& p2);
    void traverse (const cv::Point& st, std::vector <std::vector <bool> >& used, int val);
    double mThreshold;
    int mCompCount = -1;
};

#endif // LINEARSEGMENTATION_H
