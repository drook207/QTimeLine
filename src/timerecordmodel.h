#pragma once

#include "timerecord.h"
#include <QElapsedTimer>
#include <QObject>
#include <QTimer>

namespace QTimeLine {

class TimeRecordModel : public QObject {
  Q_OBJECT
  static constexpr auto INTERVAL = 1000U;

public:
  explicit TimeRecordModel(QObject *parent = nullptr);
  Q_INVOKABLE void start();
  Q_INVOKABLE void stop();

  [[nodiscard]] QTime Duration() const;
  void setDuration(const QTime &newDuration);

  [[nodiscard]] QString Description() const;
  void setDescription(const QString &newDescription);

signals:
  void stopped(QSharedPointer<TimeRecord> entry);

  void DurationChanged();

  void DescriptionChanged();

private:
  QElapsedTimer mElapsedTimer{};
  QTimer mTick{};
  QTime mDuration{};
  QString mDescription{};
  Q_PROPERTY(QTime Duration READ Duration WRITE setDuration NOTIFY
				 DurationChanged FINAL)
  Q_PROPERTY(QString Description READ Description WRITE setDescription NOTIFY
				 DescriptionChanged FINAL)
};

} // namespace QTimeLine
