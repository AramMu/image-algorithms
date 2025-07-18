#include "linearsegmentation.h"
#include <queue>

LinearSegmentation::LinearSegmentation() :
    Segmentation() {}

LinearSegmentation::LinearSegmentation(const cv::Mat& input, double threshold):
    Segmentation(input),
    mThreshold(threshold) {}

std::vector <cv::Point> LinearSegmentation::getNeighbours(const cv::Point& p) {
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

double LinearSegmentation::distance (const cv::Point& p1, const cv::Point& p2) {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum += std::abs(int (mInput.at<cv::Vec3b>(p1)[i]) - int(mInput.at<cv::Vec3b>(p2)[i]));
    }
    return sum;
}

void LinearSegmentation::traverse (const cv::Point& st, std::vector <std::vector <bool> >& used, int val) {
    std::queue <cv::Point> q;
    q.push (st);
    used [st.y][st.x] = true;
    //mOutput.at<int> (st) = val;
    while (!q.empty()) {
        cv::Point t = q.front();
        q.pop();
        mOutput.at<int> (t) = val;
        std::vector <cv::Point> ne = getNeighbours(t);
        for (int i = 0; i < ne.size(); ++i) {
            if (!used[ne[i].y][ne[i].x] && distance(t, ne[i]) < mThreshold) {
                used[ne[i].y][ne[i].x] = true;
                q.push (ne[i]);
            }
        }
    }
}

int LinearSegmentation::run() {
    if (mInput.type() != CV_8UC3) {
        return eFailedTypeMismatch;
    }
    mOutput = cv::Mat (mInput.size(), CV_32SC1, cv::Scalar (-1));
    std::vector <std::vector <bool> > used (mInput.rows, std::vector <bool> (mInput.cols, false));
    int k = 0;
    for (int i = 0; i < used.size(); ++i) {
        for (int j = 0; j < used[i].size(); ++j) {
            if (!used[i][j]) {
                traverse (cv::Point(j,i), used, k);
                k++;
            }
        }
    }
    mCompCount = k;
    return eSuccess;
}

int LinearSegmentation::getComponentCount() {
    return mCompCount;
}
