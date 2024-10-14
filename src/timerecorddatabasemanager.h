#pragma once

#include "sqlstorage.h"
#include <QLoggingCategory>
#include <QObject>

#include "timerecord.h"

namespace QTimeLine {

// Forwardings
class TimeRecord;

class TimeRecordDatabaseManager : public QObject {
  Q_OBJECT
public:
  explicit TimeRecordDatabaseManager(QSharedPointer<SqlStorage> storage,
									QObject *parent = nullptr);
public slots:
  TimeRecord entryFromId(const quint64 id);
  TimeRecord entryFromDescription(const QString &description);

  bool addEntry(const TimeRecord &entry) const;

signals:

private:
  QSharedPointer<SqlStorage> mStorage{};
};

} // namespace QTimeLine

Q_DECLARE_LOGGING_CATEGORY(lcTimeEntryManager)
