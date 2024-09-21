#include "timeentrymanager.h"
#include <QSqlQuery>

namespace QTimeLine {

Q_LOGGING_CATEGORY(lcTimeEntryManager, "qtimeline.timeentry.manager")

TimeEntryManager::TimeEntryManager(QSharedPointer<SqlStorage> storage,
								   QObject *parent)
	: QObject{parent}, mStorage(storage) {}

TimeEntry TimeEntryManager::entryFromId(const quint64 id) {}

bool TimeEntryManager::add(const TimeEntry &entry) const {
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
}

} // namespace QTimeLine
