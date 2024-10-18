#include "timerecorddatabasemanager.h"
#include <QSqlQuery>

namespace QTimeLine {

Q_LOGGING_CATEGORY(lcTimeEntryManager, "qtimeline.timeentry.manager")

TimeRecordDatabaseManager::TimeRecordDatabaseManager(
	QSharedPointer<SqlStorage> storage, QObject *parent)
	: QObject{parent}, mStorage(storage) {}

TimeRecord TimeRecordDatabaseManager::entryFromId(const quint64 id) {
  return {};
}

TimeRecord
TimeRecordDatabaseManager::entryFromDescription(const QString &description) {
  return {};
}

void TimeRecordDatabaseManager::addEntry(
	const QSharedPointer<TimeRecord> entry) {
  if (mStorage.isNull()) {
	qWarning(lcTimeEntryManager) << "Sql storage is invalid";
	return;
  }

  auto db = mStorage->database();

  if (!db.isValid() || !db.isOpen()) {
	qWarning(lcTimeEntryManager) << "Sql storage is invalid";
	return;
  }
  QSqlQuery query;
  if (const auto tables = db.tables(); tables.isEmpty()) {
	if (!query.prepare(
			"create table IF NOT EXISTS TimeRecords (id varchar(50) PRIMARY "
			"KEY, "
			"description varchar(50), date varchar(50), begin varchar(50), "
			"end varchar(50), duration varchar(50))")) {
	  return;
	}
	if (!query.exec()) {
	  return;
	}
  }

  if (!query.prepare("INSERT INTO TimeRecords (id, description, date, begin, "
					 "end, duration) VALUES (:id, :description, :date, :begin, "
					 ":end, :duration) ")) {
	return;
  }
  query.bindValue(":id", entry->mId);
  query.bindValue(":description", entry->mDescription);
  query.bindValue(":date", entry->mDate);
  query.bindValue(":begin", entry->mBegin);
  query.bindValue(":end", entry->mEnd);
  query.bindValue(":duration", entry->mDuration);

  if (!query.exec()) {
	return;
  }

  if (!mEntryList.contains(entry)) {
	mEntryList.append(entry);
  }

  return;
}

} // namespace QTimeLine
