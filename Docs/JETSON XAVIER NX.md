# JETSON XAVIER NX Doc

## ROS Install

### Tutorial

### 1. 

````shell
~$ sudo sh -c '. /etc/lsb-release && echo "deb http://mirrors.tuna.tsinghua.edu.cn/ros/ubuntu/ `lsb_release -cs` main" > /etc/apt/sources.list.d/ros-latest.list'
````

```shell
~$ sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
```

```shell
~$ sudo apt-get update
```

```shell
~$ sudo apt-get install ros-melodic-desktop-full
```

```shell
~$ sudo rosdep int
```

```shell
~$ rosdep update
```

### 2. 

在 ~/.bashrc 中写入

> source /opt/ros/melodic/setup.bash

```shell
~$ sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential
```

### 3.

检查是否安装成功

```shell
~$ roscore
```

### Debug

- rosdep 找不到命令

  ```shell
  ~$ sudo apt-get install python-rosdep
  ```

- rosinit 网络错误

  参考 <https://blog.csdn.net/w383117613/article/details/116784860>



## SMMR-Explore Setting For Car

### Install Cartographer

- 安装依赖

  ```shell
  ~$ sudo apt-get install ros-melodic-costmap-2d ros-melodic-cartographer-ros-msgs ros-melodic-bfl ros-melodic-move-base
  ```

- cartographer 安装参考 <https://github.com/efc-robot/Cartographer-for-SMMR>

### Build

### 1. 

安装必要包

```shell
~$ sudo apt-get install ros-melodic-uuid-msgs ros-melodic-libuvc ros-melodic-unique-id
```

### 2.

关于 MongoDB的安装参照 src/third_packages/world_canvas/warehouse_ros_mongo/README.md

```shell
~$ git clone -b 26compat https://github.com/mongodb/mongo-cxx-driver/git
```

```shell
~$ sudo apt-get install scons
```

```shell
~$ cd mongo-cxx-driver
```

```shell
~$ sudo scons --prefix=/usr/local --full --use-system-boost --disable-warnings-as-errors
```

### 3. 

devel/include 中的第三方包需要加入一些 h 文件，从<> 下载

### 4.

根据Segway RMP220 Setting Tutorial 配置 控制包

### 5.

```shell
~$ catkin_make
```

### Debug

- 找不到 OpenCV3 

  安装opencv3，参照 https://blog.csdn.net/qq_41080854/article/details/88609795

  并且把 /usr/include/opencv4 中的 opencv2 文件夹移到其上级目录中

  或者直接修改 map_merge/CMakeLists.txt 里面的 Version 为 4（不推荐，之后可能有包调用问题）

- No rule to make target "/usr/lib/aarch64-linux-gnu/libopencv_objdetect.so.3.2.0"

  ```shell
  ~$ sudo apt install libopencv3.2
  ```

  若之前安装的是 opencv3.2 系列则应该有这个 so 文件，可以选择软链接到 aarch64-linux-gnu 下

- 找不到 lua.hpp

  在 /usr 目录下搜索 lua.hpp，将 lua.h 中改为对应的 #include<lua5.*/lua.hpp>

- 编译 cartographer_ros 报错：

  ```shell
  /usr/bin/ld: /opt/abseil-cpp/install/lib/libabsl_base.a(sysinfo.cc.o): relocation R_X86_64_TPOFF32 against `_ZGVZN4absl13base_internal12GetCachedTIDEvE9thread_id' can not be used when making a shared object; recompile with -fPIC
  ```
可在abseil-cpp 的 CMakeLists.txt 中添加:

  ```cmake
  set(CMAKE_BUILD_TYPE "Release")
  SET(CMAKE_CXX_FLAGS "-std=c++11 -O3")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fPIC")
  ```
  
  再重新编译和安装 abseil-cpp
  
- 找不到 cartographer-ros-msgs 中的某些头文件

  在 catkin_ws/src 中的 CMakeLists.txt 中，直接用 include_directories() 写入文件所在路径

- 安装 torch

  参考 <https://forums.developer.nvidia.com/t/pytorch-for-jetson-version-1-9-0-now-available/72048>

  例：对于 python2.7 

  ```shell
  $ wget https://nvidia.box.com/shared/static/1v2cc4ro6zvsbu0p8h6qcuaqco1qcsif.whl -O torch-1.4.0-cp27-cp27mu-linux_aarch64.whl
  $ sudo apt-get install libopenblas-base libopenmpi-dev 
  $ pip install future torch-1.4.0-cp27-cp27mu-linux_aarch64.whl
  ```

  
