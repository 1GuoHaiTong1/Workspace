cmake_minimum_required(VERSION 2.6)

project(main)

message("Project Name: " ${PROJECT_NAME})

#设置编译参数
set(CMAKE_C_FLAGS "-g -Wall")

#设置执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out)

# 添加头文件路径
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加第三方库(add)头文件路径
#include_directories(${PROJECT_SOURCE_DIR}/src/lib/add/include)

#添加库文件搜索路径
#link_directories(${PROJECT_SOURCE_DIR}/src/lib/add/lib)

# 递归获取目录下所有的C文件
file(GLOB_RECURSE cpp_files ${PROJECT_SOURCE_DIR}/source/*.cpp ${PROJECT_SOURCE_DIR}/main/*.cpp)

# 生成执行文件
add_executable(${PROJECT_NAME} ${cpp_files})

# 执行文件链接外部库文件
#target_link_libraries(${PROJECT_NAME} add)

