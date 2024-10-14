#pragma once

#include "timerecord.h"
#include <QElapsedTimer>
#include <QObject>
#include <QTimer>

namespace QTimeLine {

class TimeRecordModel : public QObject {
  Q_OBJECT
public:
  explicit TimeRecordModel(QObject *parent = nullptr);

signals:
  void Stop(TimeRecord entry);

private:
  TimeRecord mRecord{};
  QElapsedTimer mElapsedTimer{};
  QTimer mTick{};
  QString mDuration{};
};

} // namespace QTimeLine
