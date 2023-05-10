#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
#include<time.h>
#include<vector>
using namespace cv;
using namespace std;

int main()
{
    clock_t start = 0;
    start = clock();

    // serial execution 
    for (int k = 0; k <10; k++)
    {
        string i = "yash.jpg";
        Mat image = imread(i, IMREAD_COLOR);
        resize(image, image, { 500,500 }, 0, 0, cv::INTER_NEAREST);

        Mat grayImage(image.rows, image.cols, CV_8UC1);
        mutex m;
        parallel_for_(Range(0, image.rows), [&](const Range& range) {
            for (int i = range.start; i < range.end; i++) {
                for (int j = 0; j < image.cols; j++) {
                    m.lock();
                    grayImage.at<uchar>(i, j) = (0.3 * image.at<Vec3b>(i, j)[0] + 0.59 * image.at<Vec3b>(i, j)[1] + 0.11 * image.at<Vec3b>(i, j)[2]);
                    m.unlock();
                }
            }
            });

        Mat reversedImage;
        //flip(image, reversedImage, 1);
        mutex m2;
        parallel_for_(Range(0, reversedImage.rows), [&](const Range& range) {
            for (int i = range.start; i < range.end; i++) {
                m2.lock();
                flip(reversedImage.row(i), reversedImage.row(i), 1);
                m2.unlock();
            }
            });
    }

    start = clock() - start;
    std::cout << "TIME TAKEN IN SEQUENTIAL EXECUTION : " << start<<endl;

    start = 0;
    start = clock();

    //parallel execution 

    for (int k = 0; k <10; k++)
    {
        
        string i = "yash.jpg";
        Mat image = imread(i, IMREAD_COLOR);
        resize(image, image, { 500,500 }, 0, 0, cv::INTER_NEAREST);

        Mat grayMirroredImage(image.rows, image.cols, CV_8UC1);
        mutex m;
        parallel_for_(Range(0, image.rows), [&](const Range& range) {
            for (int i = range.start; i < range.end; i++) {
                for (int j = 0; j < image.cols; j++) {
               
                    grayMirroredImage.at<uchar>(i, j) = (0.3 * image.at<Vec3b>(i, j)[0] + 0.59 * image.at<Vec3b>(i, j)[1] + 0.11 * image.at<Vec3b>(i, j)[2]);

                }
                flip(grayMirroredImage.row(i), grayMirroredImage.row(i), 1);
            }
        });
       
    }
    start = clock() - start;
    std::cout << " TIME TAKE IN PARALLEL EXECUTION : "<<start<<endl;


    string i = "yash.jpg";
    Mat image = imread(i, IMREAD_COLOR);

    Mat grayMirroredImage(image.rows, image.cols, CV_8UC1);
    mutex m;
    parallel_for_(Range(0, image.rows), [&](const Range& range) {
        for (int i = range.start; i < range.end; i++) {
            for (int j = 0; j < image.cols; j++) {
               
                grayMirroredImage.at<uchar>(i, j) = (0.3*image.at<Vec3b>(i, j)[0] + 0.59*image.at<Vec3b>(i, j)[1] + 0.11*image.at<Vec3b>(i, j)[2]) ;
            }
            flip(grayMirroredImage.row(i), grayMirroredImage.row(i), 1);
        }
        });


    // sharpen filter 
    Mat image1 = imread("yash.jpg", IMREAD_COLOR);
    Mat Filter1= (Mat_<float>(3, 3) << 0,-1,0,
        -1,5,-1,
        0,-1,0);
    Mat Image1;
    filter2D(image1, Image1, -1, Filter1);

    //strong edge detection
    Mat image2 = imread("yash.jpg", IMREAD_COLOR);
    Mat Filter = (Mat_<float>(3, 3) << -1,-2,-1,
        0,0,0,
        1, 2, 1);
    filter2D(image2, image2, -1, Filter);

    imshow("strong edge detect image",image2);

    imshow("sharpen image",Image1);

    imshow("original", image);

    imshow("gray mirrored image ", grayMirroredImage);

    waitKey(0);
    return 0;
}