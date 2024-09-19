#ifndef SQLSTORAGE_H
#define SQLSTORAGE_H

#include <QLoggingCategory>
#include <QObject>
#include <QtSql/qsqldatabase.h>

namespace QTimeLine {

/**
 * \brief The SqlStorage class
 */
class SqlStorage : public QObject {
  Q_OBJECT
 public:
  /**
   * \brief fromConnection
   * \param connectionName
   * \return
   */
  static QSharedPointer<SqlStorage> fromConnection(
	  const QString &connectionName);

  static QSharedPointer<SqlStorage> fromFile(const QString &fileName);

  QSqlDatabase database();
 signals:

 protected:
  explicit SqlStorage(QObject *parent = nullptr);

  QString mConnectionName{};

  QString mDataBaseName{};

 private:
};

}  // namespace QTimeLine

Q_DECLARE_LOGGING_CATEGORY(lcSqlStorage);

#endif  // SQLSTORAGE_H
