#include "timerecordmodel.h"
#include <QUuid>

namespace QTimeLine {

TimeRecordModel::TimeRecordModel(QObject *parent) : QObject{parent} {

  mTick.setInterval(INTERVAL);

  connect(&mTick, &QTimer::timeout, this, [this]() {
	quint64 duration = mDuration;
	duration++;
	setDuration(duration);
  });
}

void TimeRecordModel::start() {
  mTick.start();
  mElapsedTimer.start();
}

void TimeRecordModel::stop() {
  mTick.stop();
  auto elapsed = mElapsedTimer.elapsed();
  auto record = QSharedPointer<TimeRecord>(new TimeRecord);
  record->mId = QUuid::createUuid().toString();
  record->mDuration = QString::number(elapsed);
  emit stopped(record);
}

QTime TimeRecordModel::Duration() const { return mDuration; }

void TimeRecordModel::setDuration(const QTime &newDuration) {
  if (mDuration == newDuration)
	return;
  mDuration = newDuration;
  emit DurationChanged();
}

QString TimeRecordModel::Description() const { return mDescription; }

void TimeRecordModel::setDescription(const QString &newDescription) {
  if (mDescription == newDescription)
	return;
  mDescription = newDescription;
  emit DurationChanged();
}

} // namespace QTimeLine
