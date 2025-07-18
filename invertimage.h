
#ifndef INVERTIMAGE_H
#define INVERTIMAGE_H

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <abstractalgorithm.h>

class InvertImage : public AbstractAlgorithm<cv::Mat, cv::Mat> {
public:
    enum State {
        eSuccess, eFailedTypeMismatch, eFailed
    };

    InvertImage();
    InvertImage(const cv::Mat& input);
    //~InvertImage();
    virtual int run ();
};

#endif // INVERTIMAGE_H
