#include <vector>
#include <tuple>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

class MarchingSquares {
    private: 
        typedef std::vector<std::vector<std::tuple<int,int,int>>> _NUMERICAL_ARRAY;   
        typedef std::tuple<int,int> _POINT;
        typedef std::vector<std::vector<float>> _2D_Array;
    public:
        MarchingSquares();

        std::pair<size_t, size_t> getShape(const _NUMERICAL_ARRAY& array);

        cv::Mat readfile(const std::string& filename, float downsample_factor);
        std::tuple<float, cv::Mat> _otsu_segmentation(cv::Mat& image);
        std::tuple<std::map<_POINT, bool>, int, int> _point_array(_2D_Array image);
        int _get_value(std::map(_POINT, bool));
        
};


