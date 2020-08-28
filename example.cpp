//
// Created by benwang on 8/24/20.
//

/**
 * example.cpp
 */
#include <pybind11/stl.h>
#include <pybind11/pybind11.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <iostream>
#include "ndarray_converter.h"

#include <vector>

namespace py = pybind11;

void show_image(cv::Mat image)
{
    cv::imshow("image_from_Cpp", image);
    cv::waitKey(0);
}

cv::Mat read_image(std::string image_name)
{
    cv::Mat image = cv::imread(image_name, 1);
    std::cout << image_name <<  " size: " << image.size().height << " " << image.size().width << std::endl;
    return image;
}

cv::Mat passthru(cv::Mat image)
{
    return image;
}

cv::Mat cloneimg(cv::Mat image)
{
    return image.clone();
}

cv::Mat gaussian_blur_demo(cv::Mat& image) {
    cv::Mat dst;
    cv::GaussianBlur(image, dst, cv::Size(7, 7),1.5,1.5);
    return dst;
}

cv::Mat image_filter(cv::Mat& image, cv::Mat& kernel){
    cv::Mat dst;
    cv::filter2D(image, dst, -1, kernel);
    return dst;
}


py::list wangyidong(cv::Mat& image){
    int width = image.size().width;
    int height = image.size().height;

    std::vector<int> test_vec{width, height};
    py::list test_list = py::cast(test_vec);

    return test_list;
}


PYBIND11_MODULE(example,m)
{
    NDArrayConverter::init_numpy();

    m.def("read_image", &read_image, "A function that read an image",
    py::arg("image"));
    m.def("show_image", &show_image, "A function that show an image",
    py::arg("image"));
    m.def("passthru", &passthru, "Passthru function", py::arg("image"));
    m.def("clone", &cloneimg, "Clone function", py::arg("image"));
    m.def("gaussian_blur_demo", &gaussian_blur_demo);
    m.def("image_filter", &image_filter);

    m.def("wangyidong", &wangyidong);
}
