cmake_minimum_required(VERSION 3.18)

project(vk_qt_demo)

set(CXX_STANDARD 17)

set(CXX_STANDARD_REQUIRED ON)

cmake_host_system_information(RESULT _host_name QUERY HOSTNAME)
message("-- HOSTNAME environment variable is: " ${_host_name})

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")

    # set(Qt6_DIR /Users/tomaswu/Qt/6.6.0/macos/lib/cmake/Qt6)
    # find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
    message(${srcs})

elseif(_host_name STREQUAL "DESKTOP-JN9PKOL")
    set(glfw_include "D:/data/third_libs/glfw3/include")
    set(glfw_libs "D:/data/third_libs/glfw3/lib-vc2022")
    set(Vulkan_DIR "C:/VulkanSDK/1.3.268.0/cmake")

endif()

find_package(Vulkan REQUIRED)

include_directories(${glfw_include} "./include")
link_directories(${glfw_libs})

file(GLOB srcs "srcs/*.cpp" "include/*.h")

add_executable(vk_qt_demo ${srcs})

target_link_libraries(vk_qt_demo PRIVATE glfw3)
