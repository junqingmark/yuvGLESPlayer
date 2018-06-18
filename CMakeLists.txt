CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(yuvPlayer)

set (CMAKE_CXX_CFLAGS "${CMAKE_CXX_CFLAGS} -g")

set(SRCS 
    main.cpp
    )

add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} SDL2 GLESv2 EGL)