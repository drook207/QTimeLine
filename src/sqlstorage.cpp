#include "sqlstorage.h"

#include <QFile>

namespace QTimeLine {

Q_LOGGING_CATEGORY(lcSqlStorage, "QTimeline.sqlstorage");

QSharedPointer<SqlStorage>
SqlStorage::fromConnection(const QString &connectionName) {
  if (connectionName.isEmpty()) {
	qWarning(lcSqlStorage()) << "Connetion name is empty!";
	return {};
  }

  if (!QSqlDatabase::contains(connectionName)) {
	qWarning(lcSqlStorage())
		<< "QSqlDatabase::connectionNames() does not contain: "
		<< connectionName;
	return {};
  }

  auto dataBase = QSqlDatabase::database(connectionName);
  auto result = QSharedPointer<SqlStorage>(new SqlStorage());

  result->mConnectionName = connectionName;
  result->mDataBaseName = dataBase.databaseName();

  return result;
}

QSharedPointer<SqlStorage> SqlStorage::fromFile(const QString &fileName) {
  if (fileName.isEmpty()) {
	qWarning(lcSqlStorage()) << "Connetion name is empty!";
	return QSharedPointer<SqlStorage>();
  }

  auto db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName(fileName);
  if (!db.open()) {
	qWarning(lcSqlStorage()) << "Could not open database!";
	return QSharedPointer<SqlStorage>();
  }

  auto result = QSharedPointer<SqlStorage>(new SqlStorage);
  result->mConnectionName = db.connectionName();
  result->mDataBaseName = db.databaseName();

  return result;
}

QSqlDatabase SqlStorage::database() {
  if (mDataBaseName.isEmpty() || mConnectionName.isEmpty()) {
	return QSqlDatabase();
  }
  if (!QSqlDatabase::contains(mConnectionName)) {
	qWarning(lcSqlStorage())
		<< "QSqlDatabase::connectionNames() does not contain: "
		<< mConnectionName;
	return QSqlDatabase();
  }

  return QSqlDatabase::database(mConnectionName);
}

SqlStorage::SqlStorage(QObject *parent) : QObject{parent} {}

} // namespace QTimeLine
