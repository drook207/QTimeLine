add_subdirectory(qml)

set(SOURCES timerecord.cpp)
set(HEADERS timerecord.h)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Sql)

set(QT_LIBS Qt6::Core Qt6::Sql)

qt_add_library(qtimeline SHARED ${SOURCES} ${HEADERS} sqlstorage.h
			   sqlstorage.cpp
			   timerecorddatabasemanager.h timerecorddatabasemanager.cpp
			   timerecordmodel.h timerecordmodel.cpp)

target_link_libraries(qtimeline PRIVATE ${QT_LIBS})
target_include_directories(qtimeline INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
