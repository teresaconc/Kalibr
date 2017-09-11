cmake_minimum_required(VERSION 2.8)

project(ethz_apriltag2)

set(CFLAGS="-O0 -g")
set( CXXFLAGS="-O0 -g")
find_package(catkin_simple REQUIRED)
catkin_simple()
ADD_DEFINITIONS(-DASLAM_USE_ROS )
find_package(Boost REQUIRED COMPONENTS system serialization filesystem)
#find_package(catkin REQUIRED COMPONENTS cmake_modules)
#include_directories(${catkin_INCLUDE_DIRS})


find_package(Eigen REQUIRED)

#catkin_package(
 #   DEPENDS eigen opencv 
  #  INCLUDE_DIRS include ${Eigen_INCLUDE_DIRS}
   # LIBRARIES ${PROJECT_NAME}
#)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/)

find_package(OpenCV REQUIRED)

add_definitions(-fPIC -O3)
#include_directories(include  ${Eigen_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS})
add_definitions(-DGTEST_USE_OWN_TR1_TUPLE=0)


cs_add_library(${PROJECT_NAME} 
	src/Edge.cc
	src/FloatImage.cc
	src/Gaussian.cc
	src/GLine2D.cc
	src/GLineSegment2D.cc
	src/GrayModel.cc
	src/Homography33.cc
	src/MathUtil.cc
	src/Quad.cc
	src/Segment.cc
	src/TagDetection.cc
	src/TagDetector.cc
	src/TagFamily.cc
	src/UnionFindSimple.cc
)
#library
#file(GLOB SOURCE_FILES "src/*.cc")
#add_library(${PROJECT_NAME}  ${SOURCE_FILES})
SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS} -lpthread")
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} ${catkin_LIBRARIES}  ${Boost_LIBRARIES})

#demo
if(NOT APPLE)
  add_executable(apriltags_demo src/example/apriltags_demo.cpp src/example/Serial.cpp)
  target_link_libraries(apriltags_demo ${PROJECT_NAME} v4l2)
endif()

cs_install()
cs_export()

