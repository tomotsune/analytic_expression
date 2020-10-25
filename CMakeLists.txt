cmake_minimum_required(VERSION 3.17)
project(analytic_expression)

set(CMAKE_CXX_STANDARD 20)

# 自动调用moc，uic，rcc处理qt的扩展部分
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTOUIC on)
set(CMAKE_AUTORCC on)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(analytic_expression
        src/main.cpp
        src/reverse_polish_notation.cpp
        src/reverse_polish_notation.h
        src/mainWindow.cpp
        src/mainWindow.h)

# 把对应Qt模块的库链接进程序
target_link_libraries(${PROJECT_NAME}
        Qt5::Core Qt5::Gui Qt5::Widgets
        )