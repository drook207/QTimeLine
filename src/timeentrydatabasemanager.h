#pragma once

#include "sqlstorage.h"
#include <QLoggingCategory>
#include <QObject>
<<<<<<< Updated upstream
#include "timeentry.h"

namespace QTimeLine {


=======

namespace QTimeLine {

// Forwardings
class TimeEntry;
>>>>>>> Stashed changes

class TimeEntryManager : public QObject {
  Q_OBJECT
public:
  explicit TimeEntryManager(QSharedPointer<SqlStorage> storage,
							QObject *parent = nullptr);

  TimeEntry entryFromId(const quint64 id);
  TimeEntry entryFromDescription(const QString &description);

  bool add(const TimeEntry &entry) const;

signals:

private:
  QSharedPointer<SqlStorage> mStorage{};
};

} // namespace QTimeLine

Q_DECLARE_LOGGING_CATEGORY(lcTimeEntryManager)
