cmake_minimum_required(VERSION 3.5)

project(TaskHeadHanter VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 COMPONENTS Widgets Network PrintSupport REQUIRED)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        udpworker.h
        udpworker.cpp
        graphworker.h
        graphworker.cpp
        graphworker.ui
)


qt_add_executable(TaskHeadHanter
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

add_compile_definitions(QCUSTOMPLOT_USE_LIBRARY)
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(TaskHeadHanter PRIVATE Qt6::Widgets Qt6::Network Qt6::PrintSupport
                                                                       qcustomplot2.dll)



qt_finalize_executable(TaskHeadHanter)
