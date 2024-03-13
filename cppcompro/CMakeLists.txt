cmake_minimum_required(VERSION 3.10)
project(cppcompro)

set(CMAKE_CXX_STANDARD 17)
#find_package(libmongocxx REQUIRED)
#find_package(libbsoncxx REQUIRED)
#include_directories(${LIBMONGOCXX_INCLUDE_DIR})
#include_directories(${LIBBSONCXX_INCLUDE_DIR})
# 从本地库中引入外部第三方库
# 绝对引入
#include_directories("F:/tool/CXXPlugins/mongo-cxx-driver/include/mongocxx/v_noabi")
# 普通变量引入
set(MONGOCXX_DRIVER_PATH F:/tool/CXXPlugins/mongo-cxx-driver/include)
set(MONGOC_DRIVER_PATH F:/tool/CXXPlugins/mongo-c-driver/include)
include_directories("F:/tool/CXXPlugins/mongo-cxx-driver/lib")
include_directories("F:/tool/CXXPlugins/mongo-c-driver/lib")
#libmongoc-1.0
#libbson-1.0
include_directories("${MONGOC_DRIVER_PATH}/libbson-1.0")
include_directories("${MONGOC_DRIVER_PATH}/libmongoc-1.0")
include_directories("${MONGOCXX_DRIVER_PATH}/bsoncxx/v_noabi")
include_directories("${MONGOCXX_DRIVER_PATH}/mongocxx/v_noabi")
# 环境变量引入
#include_directories($ENV{MONGOCXX_PATH}/v_noabi)
# 绝对引入
link_directories("F:/tool/CXXPlugins/mongo-cxx-driver/lib")
link_directories("F:/tool/CXXPlugins/mongo-c-driver/lib")
# 预定义引入
#link_libraries(${PROJECT_SOURCE_DIR}/lib) # 我们lib文件在本文件中所处在的位置
# 环境变量引入
#link_libraries($ENV{MONGOCXX_LIB}/lib) # 通过本机的环境变量引入
add_executable(cppcompro main.cpp)
#add_library(compro_lib util/mongo-connect.hpp)
#target_link_libraries(cppcompro compro_lib)

# 绝对引入
#target_link_libraries(cppcompro ${LIBMONGOCXX_LIBRARIES})
target_link_libraries(cppcompro
        F:/tool/CXXPlugins/mongo-c-driver/lib/bson-1.0.lib
        F:/tool/CXXPlugins/mongo-c-driver/lib/mongoc-1.0.lib
)
target_link_libraries(cppcompro
        F:/tool/CXXPlugins/mongo-cxx-driver/lib/bsoncxx-v_noabi-dhs-x64-v143-mdd.lib # bsoncxx-lib
        F:/tool/CXXPlugins/mongo-cxx-driver/lib/mongocxx-v_noabi-dhs-x64-v143-mdd.lib# mongocxx-lib
#        F:/tool/CXXPlugins/mongo-cxx-driver/lib/bson-static-1.0.lib
#        F:/tool/CXXPlugins/mongo-cxx-driver/lib/mongoc-static-1.0.lib
)
set(BSONCXX_POLY_USE_STD ON)
## 普通变量引入
#set(LIB_FFMPEG "mongocxx-v_noabi-dhs-x64-v143-mdd.lib" "bsoncxx-v_noabi-dhs-x64-v143-mdd.lib")
#target_link_libraries(cppcompro ${LIBFFMPEG})
## 预定义引入
#target_link_libraries(cppcompro
#        ${PROJECT_SOURCE_DIR}/xx.lib # 当前项目中lib文件的路径
#)
