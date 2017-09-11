cmake_minimum_required(VERSION 2.8.3)
project(aslam_cameras_april)
set(CMAKE_BUILD_TYPE Debug)
set(CFLAGS="-O0 -g")
set( CXXFLAGS="-O0 -g")
find_package(catkin_simple REQUIRED)
catkin_simple()

find_package(OpenCV REQUIRED)

ADD_DEFINITIONS(-DASLAM_USE_ROS )
include_directories(${Eigen_INCLUDE_DIRS})

find_package(Boost REQUIRED COMPONENTS serialization system) 
cs_add_library(${PROJECT_NAME} 
  src/GridCalibrationTargetAprilgrid.cpp
  )

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${Boost_LIBRARIES})

add_definitions(-DGTEST_USE_OWN_TR1_TUPLE=0)

add_python_export_library(${PROJECT_NAME}_python python/aslam_cameras_april
  src/module.cpp
)
SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -lpthread")
target_link_libraries(${PROJECT_NAME}_python ${PROJECT_NAME})

cs_install()
cs_export()

