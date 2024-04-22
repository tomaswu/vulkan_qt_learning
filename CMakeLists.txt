cmake_minimum_required(VERSION 3.18)

project(vk_qt_demo)

set(CMAKE_CXX_STANDARD 17)

set(CXX_STANDARD_REQUIRED ON)

cmake_host_system_information(RESULT _host_name QUERY HOSTNAME)
message("-- HOSTNAME environment variable is: " ${_host_name})

if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")

    # set(Qt6_DIR /Users/tomaswu/Qt/6.6.0/macos/lib/cmake/Qt6)
    # find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
    set(glfw_include "/opt/homebrew/Cellar/glfw/3.4/include")
    set(glfw_libs "/opt/homebrew/Cellar/glfw/3.4/lib")
    set(Vulkan_DIR "~/VulkanSDK/1.3.280.1/macOS/lib/cmake")
    set(glm_include  "/opt/homebrew/Cellar/glm/1.0.1/include")
    set(glm_libs "/opt/homebrew/Cellar/glm/1.0.1/lib")

elseif(_host_name STREQUAL "DESKTOP-JN9PKOL")
    message("hello windows")
    set(Vulkan_DIR "C:/VulkanSDK/1.3.268.0/cmake")
    list(APPEND CMAKE_PREFIX_PATH C:/Qt6/6.6.2/msvc2019_64)
endif()

find_package(Vulkan REQUIRED)
message(vulkan found?:: ${Vulkan_FOUND})

message(vulkan header:: ${Vulkan_INCLUDE_DIRS})
include_directories(${Vulkan_INCLUDE_DIRS})
# link_directories(${glfw_libs} ${glm_libs})

find_package(Qt6 REQUIRED COMPONENTS Gui)

file(GLOB srcs "srcs/*.cpp" "srcs/*.hpp")

qt_add_executable(vk_qt_demo ${srcs})

target_link_libraries(vk_qt_demo PRIVATE Vulkan::Vulkan Qt6::Gui)
