cmake_minimum_required(VERSION 3.10)
project(cppcompro)

set(CMAKE_CXX_STANDARD 14)
# 从本地库中引入外部第三方库
# 绝对引入
#include_directories("F:/tool/CXXPlugins/mongo-cxx-driver/include/mongocxx/v_noabi")
# 普通变量引入
set(MONGOCXX_PATH F:/tool/CXXPlugins/mongo-cxx-driver/include/mongocxx)
set(BSONCXX_PATH F:/tool/CXXPlugins/mongo-cxx-driver/include/bsoncxx)
include_directories(${MONGOCXX_PATH}/v_noabi)
include_directories(${BSONCXX_PATH}/v_noabi)
# 环境变量引入
#include_directories($ENV{MONGOCXX_PATH}/v_noabi)
# 绝对引入
link_directories("F:/tool/CXXPlugins/mongo-cxx-driver/lib")
# 预定义引入
#link_libraries(${PROJECT_SOURCE_DIR}/lib) # 我们lib文件在本文件中所处在的位置
# 环境变量引入
#link_libraries($ENV{MONGOCXX_LIB}/lib) # 通过本机的环境变量引入
add_executable(cppcompro main.cpp)
# 绝对引入
target_link_libraries(cppcompro
        F:/tool/CXXPlugins/mongo-cxx-driver/lib/bsoncxx-v_noabi-dhs-x64-v143-mdd.lib # bsoncxx-lib
        F:/tool/CXXPlugins/mongo-cxx-driver/lib/mongocxx-v_noabi-dhs-x64-v143-mdd.lib # mongocxx-lib
)
## 普通变量引入
#set(LIB_FFMPEG "mongocxx-v_noabi-dhs-x64-v143-mdd.lib" "bsoncxx-v_noabi-dhs-x64-v143-mdd.lib")
#target_link_libraries(cppcompro ${LIBFFMPEG})
## 预定义引入
#target_link_libraries(cppcompro
#        ${PROJECT_SOURCE_DIR}/xx.lib # 当前项目中lib文件的路径
#)
