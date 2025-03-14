#include "../include/marching_squares.hpp"
#include <vector>
#include <variant>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>
#include <optional>

using namespace cv;
using namespace std;

MarchingSquares::MarchingSquares()
{

}

std::pair<size_t,size_t> MarchingSquares::_getShape(const _2D_Array& array) {
    size_t rows = array.size();
    size_t cols = rows > 0 ? array[0].size() : 0;
    return {rows,cols};
}


cv::Mat MarchingSquares::_readfile(const std::string& filename, float downsample_factor) {

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

    // _NUMERICAL_ARRAY numerical_array(image_hsv.rows, std::vector<std::tuple<int,int,int>>(image_hsv.cols));
    // for (int i = 0; i < image_hsv.rows ; i++) {
    //     for (int j = 0; j< image_hsv.cols ; j++) {

    //         Vec3b pixel = image_hsv.at<Vec3b>(i,j);
    //         numerical_array[i][j] = std::make_tuple(pixel[0],pixel[1],pixel[2]); 

    //     }
    // }
    return image_hsv;
}   

_2D_Array MarchingSquares::_otsu_segmentation(cv::Mat& image) {
    
    cv::Mat hue_channel;
    cv::extractChannel(image, hue_channel, 0);

    cv::Mat binary_image;
    float otsu_thresh = cv::threshold(hue_channel, binary_image, 0,255, cv::THRESH_BINARY | cv::THRESH_OTSU);

    _2D_Array processed_image(binary_image.rows, std::vector<float>(binary_image.cols));

    for (int i = 0; i < binary_image.rows; ++i) {
        for (int j = 0; j < binary_image.cols; ++j) {
            processed_image[i][j] = static_cast<float>(binary_image.at<uchar>(i,j));
        }
    }

    return processed_image;


}
// May need to use a custom comparator to order the states dictionary
// differently ie ordering by y fixed value first.

// static int MarchingSquares::_sort_key(_POINT point) {
//     return std::get<1>(point) * 100 + std::get<0>(point);
// }
std::tuple<std::map<_POINT, bool>, int, int> MarchingSquares::_point_array(_2D_Array image){
    std::vector<_POINT> black_list;
    std::vector<_POINT> white_list;

    auto shape = _getShape(image);
    size_t x = shape.first - 1;
    size_t y = shape.second - 1;

    for (int i=0; i < x+1; ++i) {
        for (int j=0; j < y+1; ++j) {
            if (image[i][j] == 1) {
                black_list.push_back(std::make_tuple(j, x-i));
            }
            else { 
                white_list.push_back(std::make_tuple(j,x-i));
            }
        }
    }

    std::map<_POINT, bool> state_dict;
    std::vector<int> xblack;
    std::vector<int> yblack;

    for (int i =0; i < black_list.size(); ++i) {
        xblack.push_back(std::get<0>(black_list[i]));
        yblack.push_back(std::get<1>(black_list[i]));
        state_dict[black_list[i]] = true;
    }

    std::vector<int> xwhite;
    std::vector<int> ywhite;
    for (int i =0; i < white_list.size(); ++i) {
        xwhite.push_back(std::get<0>(white_list[i]));
        ywhite.push_back(std::get<1>(white_list[i]));
        state_dict[white_list[i]] = false;
    }

    return std::make_tuple(state_dict,x,y);
}

int MarchingSquares::_get_value(const std::map<_POINT, bool>& state_dict, int i, int j) {
    
    int A = state_dict.at(std::make_tuple(i,j));
    int B = state_dict.at(std::make_tuple(i + 1,j));
    int C = state_dict.at(std::make_tuple(i,j + 1));
    int D = state_dict.at(std::make_tuple(i + 1,j + 1));
    
    return A + B * 2+ C * 4 + D * 8;
 }

std::optional<std::vector<std::tuple<_POINT, _POINT>>> MarchingSquares::_generate_edges(int i, int j, int index) {

    int x = i;
    int y = j;

    std::vector<std::tuple<_POINT,_POINT>> vector;
    _POINT start;
    _POINT end;

    switch (index) {
        case 0:
        case 15:
            return std::nullopt;

        case 1:
        case 14:
            start = std::make_tuple(x+0.5,y);
            end = std::make_tuple(x,y+0.5);
            vector.push_back(std::make_tuple(start,end));
            break;

        case 2:
        case 13:
            start = std::make_tuple(x+0.5,y);
            end = std::make_tuple(x+1,y+0.5);
            vector.push_back(std::make_tuple(start,end));
            break;

        case 3:
        case 12:
            start = std::make_tuple(x,y+0.5);
            end = std::make_tuple(x+1,y+0.5);
            vector.push_back(std::make_tuple(start,end));
            break;

        case 4:
        case 11:
            start = std::make_tuple(x,y+0.5);
            end = std::make_tuple(x+0.5,y+1);
            vector.push_back(std::make_tuple(start,end));
            break;

        case 5:
        case 10:
            start = std::make_tuple(x+0.5,y);
            end = std::make_tuple(x+0.5,y+1);
            vector.push_back(std::make_tuple(start,end));
            break;

        case 6:
            start = std::make_tuple(x+1,y+0.5);
            end = std::make_tuple(x+0.5,y+1);
            vector.push_back(std::make_tuple(start,end));
            start = std::make_tuple(x+0.5,y);
            end = std::make_tuple(x,y+0.5);
            vector.push_back(std::make_tuple(start,end));
            break;

        case 7:
        case 8:
            start = std::make_tuple(x+1,y+0.5);
            end = std::make_tuple(x+0.5,y+1);
            vector.push_back(std::make_tuple(start,end));
            break;

        case 9:
            start = std::make_tuple(x,y+0.5);
            end = std::make_tuple(x+0.5,y+1);
            vector.push_back(std::make_tuple(start,end));
            start = std::make_tuple(x+0.5,y);
            end = std::make_tuple(x+1,y+0.5);
            vector.push_back(std::make_tuple(start,end));
            break;

        default:
            return std::nullopt; // unexpected cases
        
    }
    return vector;
 }

std::vector<std::vector<std::tuple<_POINT, _POINT>>> MarchingSquares::_list_vectors(const std::map<_POINT, bool>& state_dict, int x_len, int y_len) {
    std::vector<std::vector<std::tuple<_POINT, _POINT>>> vectors;

    for (int j = 1; j < y_len; ++j) {

        for (int i = 1; i < x_len; ++i) {
          
            int index = _get_value(state_dict, i , j);

            if (index == 6 || index == 9) {

                std::optional<std::vector<std::tuple<_POINT, _POINT>>> double_vec = _generate_edges(i,j,index);
                
                if (double_vec.has_value() && !double_vec->empty()) {
                    vectors.emplace_back(std::vector<std::tuple<_POINT,_POINT>>{double_vec-> at(0)});
                    vectors.emplace_back(std::vector<std::tuple<_POINT,_POINT>>{double_vec-> at(1)});
                }
            }
            else {
                std::optional<std::vector<std::tuple<_POINT, _POINT>>> edges = _generate_edges(i,j,index);
                if (edges.has_value() && !edges->empty()) {
                    vectors.push_back(*edges);
                }
                
            }
                    
            
            
        }
    }
    return vectors;
 }

using Edge = std::tuple<_POINT, _POINT>;

std::vector<std::vector<_POINT>> MarchingSquares::_vector_shapes(const std::vector<std::vector<Edge>>& vectors) {
    std::vector<std::vector<_POINT>> shapes;
    std::set<int> indices;
    

    for (int i = 0; i < static_cast<int>(vectors.size()); i++) {
        indices.insert(i);
    }


    while (!indices.empty()) {
        std::vector<_POINT> shape;
        

        int idx = *indices.begin();
        indices.erase(indices.begin());


        Edge seg = vectors[idx][0];
        _POINT start = std::get<0>(seg);
        _POINT end   = std::get<1>(seg);
        shape.push_back(start);
        shape.push_back(end);

        bool matched = true;
        

        while (matched) {
            matched = false;

            for (auto it = indices.begin(); it != indices.end(); ) {
                int cur = *it;
                Edge curEdge = vectors[cur][0];
                _POINT curStart = std::get<0>(curEdge);
                _POINT curEnd   = std::get<1>(curEdge);
                

                if (curStart == end) {
                    end = curEnd;
                    shape.push_back(end);
                    it = indices.erase(it);
                    matched = true;
                    break; // break out to restart the search
                } else if (curEnd == end) {
                    end = curStart;
                    shape.push_back(end);
                    it = indices.erase(it);
                    matched = true;
                    break;
                } else if (curStart == start) {
                    start = curEnd;
                    shape.insert(shape.begin(), start);
                    it = indices.erase(it);
                    matched = true;
                    break;
                } else if (curEnd == start) {
                    start = curStart;
                    shape.insert(shape.begin(), start);
                    it = indices.erase(it);
                    matched = true;
                    break;
                } else {
                    ++it;
                }
            }
        }
        shapes.push_back(shape);
    }


    std::sort(shapes.begin(), shapes.end(), [](const std::vector<_POINT>& a, const std::vector<_POINT>& b) {
        return a.size() > b.size();
    });
    return shapes;
}


void MarchingSquares::_show_coastline(const cv::Mat& image, const std::vector<std::vector<_POINT>>& shapes) {
    cv::Mat displayImage;
    

    if (image.channels() == 3) {
        cv::cvtColor(image, displayImage, cv::COLOR_HSV2BGR);
    } else {
        // If single-channel, convert to BGR.
        cv::cvtColor(image, displayImage, cv::COLOR_GRAY2BGR);
    }
    
    // Draw each shape on the image
    for (const auto& shape : shapes) {
        std::vector<cv::Point> pts;
        for (const auto& pt : shape) {
            double x, y;
            std::tie(x, y) = pt;
            pts.push_back(cv::Point(static_cast<int>(x), static_cast<int>(y)));
        }

        cv::polylines(displayImage, pts, false, cv::Scalar(0, 0, 255), 2);  // Red color for coastline
    }
    

    cv::imshow("Coastline", displayImage);
    cv::waitKey(0);  // Wait for a key press to close the window
 

 }

    
 






