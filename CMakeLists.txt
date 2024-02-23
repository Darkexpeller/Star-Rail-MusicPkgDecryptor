cmake_minimum_required(VERSION 3.12)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(FireReborn VERSION 0.1.0)
set(SRC
    ./src/main.cpp
    ./src/Firefly.h
    ./src/Firefly.cpp
)

list(LENGTH SRC NUM_SOURCE_FILES)  #the number of cpp files


if(${NUM_SOURCE_FILES}>4)  #version >=3.12 !!
set(CMAKE_BUILD_PARALLEL_LEVEL 5)
endif()
add_executable(${PROJECT_NAME} ${SRC})



# 生成动态链接库
# add_library(my_library SHARED ${SOURCE_FILES})

# 设置 DLL 的版本号
# set_target_properties(my_library PROPERTIES VERSION 1.0)

# 安装 DLL 文件
# install(TARGETS my_library DESTINATION lib)