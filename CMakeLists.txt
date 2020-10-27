cmake_minimum_required(VERSION 3.17)
project(analytic_expression)

set(CMAKE_CXX_STANDARD 20)

# 自动调用moc，uic，rcc处理qt的扩展部分
set(CMAKE_AUTOMOC on)
set(CMAKE_AUTOUIC on)
set(CMAKE_AUTORCC on)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

# 屏蔽控制台
set(CMAKE_EXE_LINKER_FLAGS"${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

add_executable(analytic_expression
        src/main.cpp
        src/mainWindow.cpp
        src/mainWindow.h
        src/RPN.h
        src/RPN.cpp
        src/DAL.h
        src/DAL.cpp)

# 把对应Qt模块的库链接进程序
target_link_libraries(${PROJECT_NAME}
        Qt5::Core Qt5::Gui Qt5::Widgets
        )