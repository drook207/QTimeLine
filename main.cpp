#include "sqlstorage.h"
#include "timerecorddatabasemanager.h"
#include "timerecordmodel.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  QObject::connect(
	  &engine, &QQmlApplicationEngine::objectCreationFailed, &app,
	  []() { QCoreApplication::exit(-1); }, Qt::QueuedConnection);
  qmlRegisterType<QTimeLine::TimeRecordModel>("QTimelineControls", 1, 0,
											  "TimeRecordModel");

  auto sqlStorage = QTimeLine::SqlStorage::fromFile("TimeRecord.db");
  if (sqlStorage.isNull()) {
	app.exit(-1);
  }

  auto timeRecordDbManager =
	  new QTimeLine::TimeRecordDatabaseManager(sqlStorage, &engine);

  engine.rootContext()->setContextProperty("TimeRecordDatabaseManager",
										   timeRecordDbManager);

  engine.addImportPath(":/qtimeline.imports");
  engine.loadFromModule("QTimelineControls", "Main");

  return app.exec();
}
