#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

#pragma comment(lib, "opencv_core231d.lib")
#pragma comment(lib, "opencv_highgui231d.lib")
#pragma comment(lib, "opencv_imgproc231d.lib")

using namespace cv;
using namespace std;

#define HIST_DIM1

int main( int argc, char argv ) {
#ifdef HIST_DIM1
//----------------------example 1-------------------------------//
    Mat src, dst;
    /// Load image
    src = imread("1.jpg");

    if (!src.data) {
        cout << "load image failed" << endl;
        return -1;
    }

    /// Separate the image in 3 places ( R, G and B )
    vector<Mat> rgb_planes;
#define SHOW_HSV
#ifdef SHOW_HSV
    Mat hsv;
    cvtColor(src, hsv, COLOR_BGR2HSV);
    split(hsv, rgb_planes);
#else
    split(src, rgb_planes );
#endif
    /// Establish the number of bins
    int histSize = 256;

    /// Set the ranges ( for R,G,B) )
    float range[] = {0, 255};
    const float *histRange = {range};

    bool uniform = true;
    bool accumulate = false;

    Mat r_hist, g_hist, b_hist;

    /// Compute the histograms:
    calcHist(&rgb_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&rgb_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
    calcHist(&rgb_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);

    // Draw the histograms for R, G and B
    int hist_w = 600;
    int hist_h = 400;
    int bin_w = cvRound((double) hist_w / histSize);

    Mat rgb_hist[3];
    for (int i = 0; i < 3; ++i) {
        rgb_hist[i] = Mat(hist_h, hist_w, CV_8UC3, Scalar::all(0));
    }

    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

    /// Normalize the result to [ 0, histImage.rows-10]
    normalize(r_hist, r_hist, 0, histImage.rows - 10, NORM_MINMAX);
    normalize(g_hist, g_hist, 0, histImage.rows - 10, NORM_MINMAX);
    normalize(b_hist, b_hist, 0, histImage.rows - 10, NORM_MINMAX);

    /// Draw for each channel
    for (int i = 1; i < histSize; i++) {
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
             Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))),
             Scalar(0, 0, 255), 1);
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
             Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))),
             Scalar(0, 255, 0), 1);
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
             Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))),
             Scalar(255, 0, 0), 1);
    }

    for (int j = 0; j < histSize; ++j) {
        int val = saturate_cast<int>(r_hist.at<float>(j));
        rectangle(rgb_hist[0], Point(j * 2 + 10, rgb_hist[0].rows), Point((j + 1) * 2 + 10, rgb_hist[0].rows - val),
                  Scalar(0, 0, 255), 1, 8);

        val = saturate_cast<int>(g_hist.at<float>(j));
        rectangle(rgb_hist[1], Point(j * 2 + 10, rgb_hist[1].rows), Point((j + 1) * 2 + 10, rgb_hist[1].rows - val),
                  Scalar(0, 255, 0), 1, 8);

        val = saturate_cast<int>(b_hist.at<float>(j));
        rectangle(rgb_hist[2], Point(j * 2 + 10, rgb_hist[2].rows), Point((j + 1) * 2 + 10, rgb_hist[2].rows - val),
                  Scalar(255, 0, 0), 1, 8);
    }

    /// Display
    namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE);
    namedWindow("wnd");
    imshow("calcHist Demo", histImage);
    imshow("wnd", src);

    imshow("R", rgb_hist[0]);
    imshow("G", rgb_hist[1]);
    imshow("B", rgb_hist[2]);
#endif
    }