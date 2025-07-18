#include "linearedgedetection.h"
#include <vector>
#include <iostream>
LinearEdgeDetection::LinearEdgeDetection() :
    EdgeDetection() {}

LinearEdgeDetection::LinearEdgeDetection(const cv::Mat& input, double threshold):
    EdgeDetection(input),
    mThreshold(threshold) {}

std::vector <cv::Point> LinearEdgeDetection::getNeighbours(const cv::Point& p) {
    std::vector<cv::Point> res;
    for (int i = p.y-1; i <= p.y+1; ++i) {
        for (int j = p.x-1; j <= p.x+1; ++j) {
            if (i >= 0 && i < mInput.rows && j >= 0 && j < mInput.cols && i!=p.y && j!=p.x) {
                res.push_back (cv::Point(j,i));
            }
        }
    }
    return res;
}

double LinearEdgeDetection::distance (const cv::Point& p1, const cv::Point& p2) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += std::abs(int (mInput.at<cv::Vec3b>(p1)[i]) - int(mInput.at<cv::Vec3b>(p2)[i]));
    }
    return sum;
}

int LinearEdgeDetection::run() {
    mOutput = cv::Mat (mInput.size(), CV_8UC1);
    //const cv::Vec3b BLACK(0,0,0);
    //const cv::Vec3b WHITE(255,255,255);
    const uchar BLACK(0);
    const uchar WHITE(255);
    for (int i = 0; i < mInput.rows; ++i) {
        for (int j = 0; j < mInput.cols; ++j) {
            std::vector <cv::Point> neighbors = getNeighbours (cv::Point(j,i));
            double maxDif = 0;
            for (int k = 0; k < neighbors.size(); ++k) {
                maxDif = std::max (maxDif, distance (cv::Point(j,i), neighbors[k]));
            }
            //std::cout << maxDif << std::endl;
            if (maxDif > mThreshold) {
                mOutput.at <uchar> (i,j) = WHITE;
            } else {
                mOutput.at <uchar> (i,j) = BLACK;
            }
        }
    }

    return 1;
}
