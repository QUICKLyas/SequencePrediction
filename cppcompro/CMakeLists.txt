cmake_minimum_required(VERSION 3.10)
project(cppcompro)

set(CMAKE_CXX_STANDARD 17)
# 在此处添加相关文件
set(SOURCE_FILES
        src/main.cpp
        src/util/mongo-op.hpp
        src/util/mongo-con.hpp
        src/conf/user.h
        src/conf/other.h
)
include_directories(
        "src/util"
        "src/conf"
)


set(INCS_DIR F:/tool/CXXPlugins/additional/includes)
set(LIBS_DIR F:/tool/CXXPlugins/additional/libs)
set(BOOST_DIR F:/tool/CXXPlugins/boost/b2-install/boost-vc143/include)
set(BOOST_LIB_DIR F:/tool/CXXPlugins/boost/b2-install/boost-vc143/lib)

find_package(Threads)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 链接外部库
include_directories(${INCS_DIR})
link_directories(${LIBS_DIR})
include_directories(${BOOST_DIR})
link_directories(${BOOST_LIB_DIR})
link_libraries(mongoc.lib mongocxx.lib bson.lib bsoncxx.lib)
#设置编译文件
add_executable(demo ${SOURCE_FILES})
target_link_libraries(demo mongocxx.dll bsoncxx.dll mongoc.dll bson.dll)
#target_link_libraries()
#target_link_libraries(plugins plugins)

#find_package(mongocxx REQUIRED)
## 配置的外部库文件 本地目录，方便使用
#set(MONGOCXX_DRIVER_PATH F:/tool/CXXPlugins/mongo-cxx-driver/include)
#set(MONGOC_DRIVER_PATH F:/tool/CXXPlugins/mongo-c-driver/include)
#set(MONGOC_LIBRARIES F:/tool/CXXPlugins/mongo-c-driver/lib)
#set(MONGOCXX_LIBRARIES F:/tool/CXXPlugins/mongo-cxx-driver/lib)
## 输出目录
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#
#include_directories("${MONGOC_DRIVER_PATH}/libbson-1.0")
#include_directories("${MONGOC_DRIVER_PATH}/libmongoc-1.0")
#include_directories("${MONGOCXX_DRIVER_PATH}/bsoncxx/v_noabi")
#include_directories("${MONGOCXX_DRIVER_PATH}/mongocxx/v_noabi")
#
#link_directories(${MONGOC_LIBRARIES})
#link_directories(${MONGOCXX_LIBRARIES})
#
#add_executable(cppcompro ${SOURCE_FILES})
#
#target_link_libraries(${PROJECT_NAME}
#        bson-1.0.dll
#        bsoncxx.dll
#        mongoc-1.0.dll
#        mongocxx.dll
#)
# old code about importing lib
##find_package(libmongocxx REQUIRED)
##find_package(libbsoncxx REQUIRED)
##include_directories(${LIBMONGOCXX_INCLUDE_DIR})
##include_directories(${LIBBSONCXX_INCLUDE_DIR})
## 从本地库中引入外部第三方库
## 绝对引入
##include_directories("F:/tool/CXXPlugins/mongo-cxx-driver/include/mongocxx/v_noabi")
## 普通变量引入
#set(MONGOCXX_DRIVER_PATH F:/tool/CXXPlugins/mongo-cxx-driver/include)
#set(MONGOC_DRIVER_PATH F:/tool/CXXPlugins/mongo-c-driver/include)
##libmongoc-1.0
##libbson-1.0
#include_directories("${MONGOC_DRIVER_PATH}/libbson-1.0")
#include_directories("${MONGOC_DRIVER_PATH}/libmongoc-1.0")
#include_directories("${MONGOCXX_DRIVER_PATH}/bsoncxx/v_noabi")
#include_directories("${MONGOCXX_DRIVER_PATH}/mongocxx/v_noabi")
## 环境变量引入
##include_directories($ENV{MONGOCXX_PATH}/v_noabi)
## 绝对引入
#link_directories("F:/tool/CXXPlugins/mongo-cxx-driver/lib")
#link_directories("F:/tool/CXXPlugins/mongo-c-driver/lib")
## 预定义引入
##link_libraries(${PROJECT_SOURCE_DIR}/lib) # 我们lib文件在本文件中所处在的位置
## 环境变量引入
##link_libraries($ENV{MONGOCXX_LIB}/lib) # 通过本机的环境变量引入
#add_executable(cppcompro src/main.cpp
#        src/util/mongoc.c)
##add_library(compro_lib util/mongo-connect.hpp)
##target_link_libraries(cppcompro compro_lib)
#
## 绝对引入
#target_link_libraries(cppcompro
#        F:/tool/CXXPlugins/mongo-cxx-driver/lib/bsoncxx-v_noabi-dhs-x64-v143-mdd.lib # bsoncxx-lib
#        F:/tool/CXXPlugins/mongo-cxx-driver/lib/mongocxx-v_noabi-dhs-x64-v143-mdd.lib# mongocxx-lib
#        F:/tool/CXXPlugins/mongo-c-driver/lib/bson-1.0.lib
#        F:/tool/CXXPlugins/mongo-c-driver/lib/mongoc-1.0.lib
#)
### 普通变量引入
##set(LIB_FFMPEG "mongocxx-v_noabi-dhs-x64-v143-mdd.lib" "bsoncxx-v_noabi-dhs-x64-v143-mdd.lib")
##target_link_libraries(cppcompro ${LIBFFMPEG})
#### 预定义引入
##target_link_libraries(cppcompro
##        ${PROJECT_SOURCE_DIR}/lib/bson-1.0.lib # 当前项目中lib文件的路径
##        ${PROJECT_SOURCE_DIR}/lib/bsoncxx-v_noabi-dhs-x64-v143-mdd.lib # 当前项目中lib文件的路径
##        ${PROJECT_SOURCE_DIR}/lib/mongoc-1.0.lib
##        ${PROJECT_SOURCE_DIR}/lib/mongocxx-v_noabi-dhs-x64-v143-mdd.lib
##)
