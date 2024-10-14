#include "timerecorddatabasemanager.h"
#include <QSqlQuery>

namespace QTimeLine {

Q_LOGGING_CATEGORY(lcTimeEntryManager, "qtimeline.timeentry.manager")

TimeRecordDatabaseManager::TimeRecordDatabaseManager(
	QSharedPointer<SqlStorage> storage, QObject *parent)
	: QObject{parent}, mStorage(storage) {}

TimeRecord TimeRecordDatabaseManager::entryFromId(const quint64 id) { return {}; }

TimeRecord
TimeRecordDatabaseManager::entryFromDescription(const QString &description) {
  return {};
}

bool TimeRecordDatabaseManager::addEntry(const TimeRecord &entry) const {
  if (mStorage.isNull()) {
	qWarning(lcTimeEntryManager) << "Sql storage is invalid";
	return false;
  }

  auto db = mStorage->database();

  if (!db.isValid() || !db.isOpen()) {
	qWarning(lcTimeEntryManager) << "Sql storage is invalid";
	return false;
  }

  QSqlQuery query;

  if (!query.prepare("INSERT INTO timeEntries (id, description, date, begin, "
					 "end, duration) VALUES (:id, :description, :date, :begin, "
					 ":end, :duration) ")) {
	return false;
  }
  query.bindValue(":id", entry.mId);
  query.bindValue(":description", entry.mDescription);
  query.bindValue(":date", entry.mDate);
  query.bindValue(":begin", entry.mBegin);
  query.bindValue(":end", entry.mEnd);
  query.bindValue(":duration", entry.mDuration);

  if (!query.exec()) {
	return false;
  }

  return true;
}

} // namespace QTimeLine
