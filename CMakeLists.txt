cmake_minimum_required(VERSION 3.16)

project(vk_qt_demo)

set(CXX_STANDARD 17)

set(CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")

    # set(Qt6_DIR /Users/tomaswu/Qt/6.6.0/macos/lib/cmake/Qt6)

    find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
    file(GLOB srcs "srcs/*.cpp" "include/*.hpp" "srcs/*.ui")
    message(${srcs})

endif()

qt_standard_project_setup()

qt_add_executable(vk_qt_demo ${srcs})

target_link_libraries(vk_qt_demo PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
