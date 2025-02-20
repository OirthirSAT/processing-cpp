#ifndef MARCHING_SQUARES_HPP
#define MARCHING_SQUARES_HPP
#include <vector>
#include <tuple>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <optional>

using namespace cv;
using namespace std;

typedef std::vector<std::vector<std::tuple<int,int,int>>> _NUMERICAL_ARRAY;   
        typedef std::tuple<int,int> _POINT;
        typedef std::vector<std::vector<float>> _2D_Array;
        typedef std::tuple<_POINT,_POINT> Edge;

class MarchingSquares {
    private: 
        
    public:
        MarchingSquares();

        static std::pair<size_t, size_t> _getShape(const _2D_Array& array);

        static cv::Mat _readfile(const std::string& filename, float downsample_factor);
        static _2D_Array _otsu_segmentation(cv::Mat& image);
        static std::tuple<std::map<_POINT, bool>, int, int> _point_array(_2D_Array image);
        static int _get_value(const std::map<_POINT, bool>& state_dict, int i , int j);
        static std::optional<std::vector<std::tuple<_POINT, _POINT>>> _generate_edges(int i, int j, int index);
        static std::vector<std::vector<std::tuple<_POINT, _POINT>>> _list_vectors(const std::map<_POINT, bool>& state_dict, int x_len, int y_len); 
        static std::vector<std::vector<_POINT>> _vector_shapes(const std::vector<std::vector<Edge>>& vectors);
        static void _show_coastline(const cv::Mat& image, const std::vector<std::vector<_POINT>>& shapes);

};

#endif



