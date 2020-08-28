# pybind_test

https://blog.csdn.net/oqqENvY12/article/details/103604335

https://github.com/pybind/pybind11/issues/1379

Conda py3.6:
conda install pybind11 -c conda-forge


Non-conda:
https://github.com/pybind/pybind11

mkdir build 
cmake ..
make
sudo make install


nx@nx-xavier:~/test/pybind_test/build$ make
Scanning dependencies of target example
[ 33%] Building CXX object CMakeFiles/example.dir/example.cpp.o
[ 66%] Building CXX object CMakeFiles/example.dir/ndarray_converter.cpp.o
In file included from /usr/include/python3.6m/numpy/ndarraytypes.h:1809:0,
                 from /usr/include/python3.6m/numpy/ndarrayobject.h:18,
                 from /home/nx/test/pybind_test/ndarray_converter.cpp:15:
/usr/include/python3.6m/numpy/npy_1_7_deprecated_api.h:15:2: warning: #warning "Using deprecated NumPy API, disable it by " "#defining NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION" [-Wcpp]
 #warning "Using deprecated NumPy API, disable it by " \
  ^~~~~~~
[100%] Linking CXX shared module example.cpython-36m-aarch64-linux-gnu.so
[100%] Built target example
nx@nx-xavier:~/test/pybind_test/build$ cd ..
nx@nx-xavier:~/test/pybind_test$ ls
build  CMakeLists.txt  data  example.cpp  ndarray_converter.cpp  ndarray_converter.h  README.md  test.py
nx@nx-xavier:~/test/pybind_test$ python test.py 
Traceback (most recent call last):
  File "test.py", line 1, in <module>
    from build import example
ImportError: No module named build
nx@nx-xavier:~/test/pybind_test$ python3 test.py 
Traceback (most recent call last):
  File "test.py", line 2, in <module>
    import cv2
  File "/usr/local/lib/python3.6/dist-packages/cv2/__init__.py", line 96, in <module>
    bootstrap()
  File "/usr/local/lib/python3.6/dist-packages/cv2/__init__.py", line 86, in bootstrap
    import cv2
ImportError: /usr/lib/aarch64-linux-gnu/libgomp.so.1: cannot allocate memory in static TLS block
nx@nx-xavier:~/test/pybind_test$ 
nx@nx-xavier:~/test/pybind_test$ 
