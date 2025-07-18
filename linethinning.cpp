#include "linethinning.h"
#include <queue>
#include <iostream>

LineThinning::LineThinning() :
    AbstractAlgorithm<cv::Mat, cv::Mat> () {}

LineThinning::LineThinning(const cv::Mat& input) :
    AbstractAlgorithm<cv::Mat, cv::Mat> (input) {}

std::vector<cv::Point2i> LineThinning::traverse (const std::vector <cv::Point2i>& boundary, std::vector <std::vector <bool> >& used) {
    std::queue <cv::Point2i> q;
    for (int i = 0; i < boundary.size(); ++i) {
        q.push (boundary[i]);
    }
    std::vector <cv::Point2i> res;
    while (!q.empty()) {
        cv::Point2i t = q.front();
        q.pop();
        for (int i = t.y-1; i <= t.y+1; ++i) {
            for (int j = t.x-1; j <= t.x+1; ++j) {
                if (!boundcheck(i,j)) {
                    continue;
                }
                if (used[i][j]) {
                    continue;
                }
                used[i][j] = true;
                if (mOutput.at <uchar> (i,j) == LineThinning::BLACK) {
                    res.push_back(cv::Point2i(j,i));
                } else {
                    q.push (cv::Point2i (j,i));
                }
            }
        }
    }
    return res;
}

bool LineThinning::boundcheck (int i, int j) {
    return i >= 0 && i < mInput.rows && j >= 0 && j < mInput.cols;
}

bool LineThinning::isBorder (const cv::Point& p) {
    return p.x <= 0 || p.y <= 0 || p.x >= mInput.cols-1 || p.y >= mInput.rows-1;
}

int LineThinning::getBlackCount (const cv::Point2i& p) {
    int res=0;
    for (int i = p.y-1; i <= p.y+1; ++i) {
        for (int j = p.x-1; j <= p.x+1; ++j) {
            if (!boundcheck (i,j) || (i == p.y && j == p.x)) {
                continue;
            }
            if (mOutput.at<uchar>(i,j) == LineThinning::BLACK) {
                res++;
            }
        }
    }
    return res;
}

int LineThinning::getChangeCount (const cv::Point2i& p) {
    if (isBorder(p)) {
        return -1;
    }
    int res=0;
    res += mOutput.at<uchar>(p.y+1,p.x)!= mOutput.at<uchar>(p.y+1, p.x+1);
    res += mOutput.at<uchar>(p.y+1,p.x+1)!= mOutput.at<uchar>(p.y, p.x+1);
    res += mOutput.at<uchar>(p.y,p.x+1)!= mOutput.at<uchar>(p.y-1, p.x+1);
    res += mOutput.at<uchar>(p.y-1,p.x+1)!= mOutput.at<uchar>(p.y-1, p.x);
    res += mOutput.at<uchar>(p.y-1,p.x)!= mOutput.at<uchar>(p.y-1, p.x-1);
    res += mOutput.at<uchar>(p.y-1,p.x-1)!= mOutput.at<uchar>(p.y, p.x-1);
    res += mOutput.at<uchar>(p.y,p.x-1)!= mOutput.at<uchar>(p.y+1, p.x-1);
    res += mOutput.at<uchar>(p.y+1,p.x-1)!= mOutput.at<uchar>(p.y+1, p.x);
    return res/2;
}

bool LineThinning::isThin (const cv::Point2i& p) {
    int blc = getBlackCount(p);
    //return false;
    return blc < 2 || blc > 6 || getChangeCount(p) > 1;
}


int LineThinning::run() {
    //std::cout << mOutput.rows << " " << mOutput.cols << std::endl;
    if (mInput.type() != CV_8UC1) {
        return eFailed;
    }
    mOutput = mInput.clone();
    //std::cout << mOutput.rows << " " << mOutput.cols << std::endl;
    std::vector <cv::Point2i> boundary;
    std::vector <cv::Point2i> result;
    std::vector <std::vector <bool> > used (mOutput.rows, std::vector <bool> (mOutput.cols, false));
    boundary.push_back(cv::Point2i(0,0));
    used[0][0] = true;
    while (!boundary.empty()) {
        std::cout << "boundary size is " << boundary.size() << std::endl;
        for (int i = 0; i < boundary.size(); ++i) {
            if (!isBorder(boundary[i]) && isThin (boundary[i])) {
                result.push_back (boundary[i]);
            }
            mOutput.at <uchar> (boundary[i]) = LineThinning::WHITE;
        }
        boundary = traverse (boundary, used);
    }
    for (int i = 0; i < result.size(); ++i) {
        mOutput.at<uchar>(result[i]) = BLACK;
    }
    return eSuccess;
}
