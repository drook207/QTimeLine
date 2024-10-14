find_package(Qt6 6.5 REQUIRED Core Quick Qml)

set_source_files_properties(Singletons/Colors.qml
							PROPERTIES QT_QML_SINGLETON_TYPE TRUE)

qt_add_qml_module(
  QTimelineControls
  URI
  QTimelineControls
  VERSION
  1.0
  QML_FILES
  Main.qml
  Elements/Header.qml
  Views/AppFrame.qml
  Singletons/Colors.qml
  Elements/RoundButton.qml
  OUTPUT_DIRECTORY
  ${CMAKE_BINARY_DIR}/QTimelineControls
  RESOURCE_PREFIX
  "qtimeline.imports")
