#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

    int main(int argc,char* argv)  
    {  
        Mat img = imread("蓝色笔筒.jpg",1);  
      
        Mat imgHSV;    
        imshow("1",img);
        //蓝色笔筒颜色的HSV范围  
        int iLowH = 10/2;
        int iHighH = 80/2;
      
        int iLowS = 10 *255/100;     
        int iHighS = 100 *255/100;
      
        int iLowV = 10*255/100;    
        int iHighV = 100*255/100;
      
        cvtColor(img, imgHSV, COLOR_BGR2HSV);//转为HSV  
      
        imshow("hsv.jpg",imgHSV);  
      
        Mat imgThresholded;  
      
        inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image    
      
        //开操作 (去除一些噪点)  如果二值化后图片干扰部分依然很多，增大下面的size  
        Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));    
        morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);    
        
        //闭操作 (连接一些连通域)    
        morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);    
        
        namedWindow("Thresholded Image",CV_WINDOW_NORMAL);  
        imshow("Thresholded Image", imgThresholded);   
          
        //这里是自定义的求取形心函数，当然用连通域计算更好  
        //Point center;  
        //center = GetCenterPoint(imgThresholded);//获取二值化白色区域的形心  
      
        //circle(img, center, 100, Scalar(0,0,255), 5, 8, 0);//绘制目标位置  
        imshow("end.jpg", img);  
      
        waitKey(0);  
    }
