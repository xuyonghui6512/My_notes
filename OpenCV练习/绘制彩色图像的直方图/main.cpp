#include<iostream>
#include<opencv2/opencv.hpp>
#include<vector>

using namespace std;
using namespace cv;

Mat getHistImg(const MatND& hist)
{
    double maxVal=0;
    double minVal=0;

    //找到直方图中的最大值和最小值
    minMaxLoc(hist,&minVal,&maxVal,0,0);
    int histSize=hist.rows;
    Mat histImg(histSize,histSize,CV_8U,Scalar(255));
    // 设置最大峰值为图像高度的90%
    int hpt=static_cast<int>(0.9*histSize);

    for(int h=0;h<histSize;h++)
    {
        float binVal=hist.at<float>(h);
        int intensity=static_cast<int>(binVal*hpt/maxVal);
        line(histImg,Point(h,histSize),Point(h,histSize-intensity),Scalar::all(0));
    }

    return histImg;
}

int main(  )  
{  
    Mat Image=imread("1.jpg");
    Mat src_gray;
    cvtColor(Image,src_gray,CV_RGB2GRAY);
    const int channels[]={0};
    const int histSize[]={256};//BGR通道色值
    float hrange[2]={0,255};
    const float* range[]={hrange};
    MatND hist,hist_b,hist_g,hist_r;
    calcHist(&Image,1,channels,Mat(),hist,1,histSize,range);
    Mat himg,hbimg,hgimg,hrimg;
    himg=getHistImg(hist);
    imshow("1",himg);
    waitKey(0);
    //return 0;
    vector<Mat> RGBimg;
    split(Image,RGBimg);
    calcHist(&RGBimg[0],1,channels,Mat(),hist_b,1,histSize,range);
    calcHist(&RGBimg[1],1,channels,Mat(),hist_g,1,histSize,range);
    calcHist(&RGBimg[2],1,channels,Mat(),hist_r,1,histSize,range);
    hbimg=getHistImg(hist_b);
    hgimg=getHistImg(hist_g);
    hrimg=getHistImg(hist_r);
    MatND backproj;
    calcBackProject(&src_gray,1,0,hist_b,backproj,range,1);
    imshow("dage",backproj);
    imshow("b",hbimg);
    imshow("g",hgimg);
    imshow("r",hrimg);

    waitKey(0);


}  
