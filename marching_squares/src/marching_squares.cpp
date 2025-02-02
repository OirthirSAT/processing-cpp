#include "./../include/marching_squares.hpp"
#include <vector>
#include <variant>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

MarchingSquares::MarchingSquares()
{

}

std::pair<size_t,size_t> MarchingSquares::getShape(const _NUMERICAL_ARRAY& array) {
    size_t rows = array.size();
    size_t cols = rows > 0 ? array[0].size() : 0;
    return {rows,cols};
}


_MarchingSquares::_NUMERICAL_ARRAY MarchingSquares::readfile(const std::string& filename, float downsample_factor) {

    Mat image_bgr = imread(filename, cv::IMREAD_COLOR);
    if (image_bgr.empty()){
        cerr << "Error: Could not read image" << filename << endl;
        return {};
    }

    int new_rows = static_cast<int>(image_bgr.rows * downsample_factor);
    int new_cols = static_cast<int>(image_bgr.cols * downsample_factor);

    Mat image_resized; 
    cv::resize(image_bgr, image_resized, cv::Size(new_cols, new_rows),0, 0, cv::INTER_AREA);

    Mat image_hsv;
    cv::cvtColor(image_resized, image_hsv, cv::COLOR_BGR2HSV    );

    _NUMERICAL_ARRAY numerical_array(image_hsv.rows, std::vector<std::tuple<int,int,int>>(image_hsv.cols));
    for (int i = 0; i < image_hsv.rows ; i++) {
        for (int j = 0; j< image_hsv.cols ; j++) {

            Vec3b pixel = image_hsv.at<Vec3b>(i,j);
            numerical_array[i][j] = std::make_tuple(pixel[0],pixel[1],pixel[2]); 

        }
    }
    return numerical_array;
}   

