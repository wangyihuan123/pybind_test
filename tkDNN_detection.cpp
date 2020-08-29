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
#include "Yolo3Detection.h"

namespace py = pybind11;


    tk::dnn::Yolo3Detection yolo;
    tk::dnn::DetectionNN *detNN = &yolo;

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

py::list detect(cv::Mat& image){
    int width = image.size().width;
    int height = image.size().height;

//    py::dict obj;
//    obj["prob"] =
    float prob = 0.9;
    float class_id = 1.0;
    float x = 12.;
    float y = 13.;
    float w = 16.;
    float h = 18.;
    std::vector<float> obj{prob, class_id, x, y, w, h};
    std::vector<std::vector<float>> test_vec;
    test_vec.push_back(obj);

    py::list detections = py::cast(test_vec);

    return detections;
}

py::list tkdnnDetect(cv::Mat& image){

    std::vector<cv::Mat> batch_dnn_input;
    batch_dnn_input.push_back(image);
    detNN->update(batch_dnn_input, 1);

    std::vector<std::vector<float>> result_vector;
    for (auto box: detNN->batchDetected[0]) {
	std::vector<float> obj{box.prob, box.cl, box.x, box.y, box.w, box.h};
        result_vector.push_back(obj);
    }
    py::list detections = py::cast(result_vector);

    return detections;
}


PYBIND11_MODULE(example,m)
{
    NDArrayConverter::init_numpy();

    std::string tensorrt_file = "data/yolo4tiny_fp16_b4.rt";
    int n_classes = 80;
    int n_batch = 1;
    float conf_thresh = 0.2; // todo: change to your own
    detNN->init(tensorrt_file, n_classes, n_batch, conf_thresh);

    m.def("read_image", &read_image, "A function that read an image",
    py::arg("image"));
    m.def("show_image", &show_image, "A function that show an image",
    py::arg("image"));
    m.def("passthru", &passthru, "Passthru function", py::arg("image"));
    m.def("clone", &cloneimg, "Clone function", py::arg("image"));
    m.def("gaussian_blur_demo", &gaussian_blur_demo);
    m.def("image_filter", &image_filter);

    m.def("wangyidong", &wangyidong);
    m.def("detect", &detect);
    m.def("tkdnnDetect", &tkdnnDetect);

}

