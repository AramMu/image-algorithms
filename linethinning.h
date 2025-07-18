#ifndef LINETHINNING_H
#define LINETHINNING_H
#include <abstractalgorithm.h>
#include <opencv2/imgproc.hpp>

class LineThinning : public AbstractAlgorithm<cv::Mat, cv::Mat> {
public:
    enum State {
        eSuccess, eNothingToDo, eFailed
    };

    LineThinning();
    LineThinning(const cv::Mat& input);
    virtual int run();

private:
    std::vector<cv::Point2i> traverse (const std::vector <cv::Point2i>& boundary, std::vector<std::vector<bool> > &used);
    bool boundcheck (int i, int j);
    bool isBorder (const cv::Point& p);
    bool isThin (const cv::Point2i& p);
    int getBlackCount (const cv::Point2i& p);
    int getChangeCount (const cv::Point2i& p);

    static const uchar BLACK = 0;
    static const uchar WHITE = -1;
};

#endif // LINETHINNING_H
