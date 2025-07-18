#include <iostream>
#include "abstractalgorithm.h"
#include "invertimage.h"
#include "linethinning.h"
#include "imagegradient.h"
#include "imageangle.h"
#include "imagehog.h"
#include "edgedetection.h"
#include "linearedgedetection.h"
#include "linearsegmentation.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <random>

std::mt19937 mGenerator (time (nullptr));
std::uniform_int_distribution<int> mRandDist(0,255);

cv::Vec3b randColor () {
    int r = mRandDist(mGenerator);
    int g = mRandDist(mGenerator);
    int b = mRandDist(mGenerator);
    return cv::Vec3b (b,g,r);
}

int main() {
    cv::Mat img = cv::imread("data/segmentimg.png", cv::IMREAD_COLOR);
    cv::imshow("aaa", img);
    cv::waitKey(0);
    LinearSegmentation lnSeg (img, 5);
    if (lnSeg.run()!=LinearSegmentation::eSuccess) {
        std::cout << "FAILED!!!";
        return 0;
    }
    cv::Mat res(img.size(), CV_8UC3);
    std::vector <cv::Vec3b> colors(lnSeg.getComponentCount());
    cv::Mat seg = lnSeg.getOutput();
    for (int i = 0; i < colors.size(); ++i) {
        colors[i] = randColor ();
    }
    for (int i = 0; i < seg.rows; ++i) {
        for (int j = 0; j < seg.cols; ++j) {
            res.at<cv::Vec3b>(i,j) = colors [seg.at<int> (i,j)];
        }
    }
    cv::imshow("bbb",res);
    cv::waitKey(0);

    return 0;
}
