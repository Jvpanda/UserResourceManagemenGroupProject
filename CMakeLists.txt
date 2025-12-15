cmake_minimum_required(VERSION 3.10)
project("FillerProjectName")

add_subdirectory(src/ResourceManagement)

file(GLOB PROJECT_SOURCES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp")

add_executable(execBinary ${PROJECT_SOURCES})

target_link_libraries(execBinary
    PUBLIC
    ResourceManagement
)
