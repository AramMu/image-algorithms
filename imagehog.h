#ifndef IMAGEHOG_H
#define IMAGEHOG_H
#include <abstractalgorithm.h>
#include <opencv2/imgproc.hpp>

class ImageHog : public AbstractAlgorithm<cv::Mat, std::vector<int> > {
public:
    enum State {
        eSuccess, eFailedTypeMismatch, eFailedInvalidInput, eFailedInvalidCount, eFailedAngleOutOfRange, eFailed
    };

    ImageHog ();
    ImageHog (const cv::Mat& input, int divCount);
    virtual int run ();
private:
    int divCount;
};

#endif // IMAGEHOG_H
