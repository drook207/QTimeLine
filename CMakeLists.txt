cmake_minimum_required(VERSION 3.29.3)

project(QTimeline LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED Core Quick Qml)

qt_standard_project_setup()

add_subdirectory(src)
add_subdirectory(tests)

set(QT_LIBS Qt6::Core Qt6::Quick Qt6::Qml)
qt_add_executable(QTimeLine main.cpp)

target_link_libraries(QTimeLine PRIVATE ${QT_LIBS} qtimeline QTimelineControls)
