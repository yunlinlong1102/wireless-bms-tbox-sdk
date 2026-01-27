project(tbox_test)

#设置安装路径
SET(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/../)

#设置cmake最低版本
cmake_minimum_required(VERSION 3.5)

set (CMAKE_C_COMPILER "/opt/toolchains/ql-ag35-1806e-gcc-8.4.0-glibc-v1-toolchain/bin/arm-openwrt-linux-gnueabi-gcc" CACHE STRING "C compiler" FORCE)
set (CMAKE_CXX_COMPILER "/opt/toolchains/ql-ag35-1806e-gcc-8.4.0-glibc-v1-toolchain/bin/arm-openwrt-linux-gnueabi-g++" CACHE STRING "C++ compiler" FORCE)

#设置flags
set (CMAKE_C_FLAGS "-std=gnu99 -pthread -Wall -Wstrict-prototypes -Wno-trigraphs -O2 -fno-strict-aliasing -fno-common")
set (CMAKE_CXX_FLAGS "-std=c++11 -pthread -Wall -Wstrict-prototypes -Wno-trigraphs -O2 -fno-strict-aliasing -fno-common")


#设置头文件路径
link_directories(${PROJECT_SOURCE_DIR})
link_directories(${PROJECT_SOURCE_DIR}/src)


# 设置变量包含所有的源文件
set(SOURCE_FILES
    main.c
    # 在这里添加你的新文件
)

# 添加可执行文件 wbms
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
# 添加链接库
#target_link_libraries(${PROJECT_NAME} libtq.so libm.so libUSB2UARTSPIIIC.so libtsfile.so)
# 安装目标 bin/
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${PROJECT_SOURCE_DIR}/bin")