cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(PROJECT_NAME NightBot_Menu)
project(${PROJECT_NAME})

# For the source and header files
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})

# Including the directories
target_include_directories(${PROJECT_NAME} PRIVATE
    Libs/minhook/include
    Libs/gd.h/include
    Libs/gd.h/
    Libs/cocos-headers/cocos2dx/
    Libs/cocos-headers/cocos2dx/include
    Libs/cocos-headers/cocos2dx/kazmath/include
    Libs/cocos-headers/cocos2dx/platform/win32
    Libs/cocos-headers/cocos2dx/platform/third_party/win32
    Libs/cocos-headers/cocos2dx/platform/third_party/win32/OGLES
    Libs/cocos-headers/extensions/
    Libs/imgui-hook
    Libs/imgui-hook/imgui
)

add_subdirectory(Libs/MinHook)

add_subdirectory(Libs/imgui-hook)
# Linkers
target_link_libraries(${PROJECT_NAME} minhook imgui-hook opengl32)

# cocos2dx
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/Libs/cocos-headers/cocos2dx/libcocos2d.lib)

# cocos2dx extensions
target_link_libraries(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/Libs/cocos-headers/extensions/libExtensions.lib)