#include "timerecordmodel.h"
#include <QDateTime>
#include <QUuid>

namespace QTimeLine {

TimeRecordModel::TimeRecordModel(QObject *parent) : QObject{parent} {

  mTick.setInterval(INTERVAL);
  mDuration = QTime::fromString("00::00::00", "hh::mm::ss");
  connect(&mTick, &QTimer::timeout, this, [this]() {
	auto t = mDuration.addSecs(1);
	setDuration(t);
  });
}

void TimeRecordModel::start() {
  mTick.start();
  mBegin = mDuration.currentTime().toString();
}

void TimeRecordModel::stop() {
  mTick.stop();
  auto record = QSharedPointer<TimeRecord>(new TimeRecord);
  record->mId = QUuid::createUuid().toString();
  record->mDuration = mDuration.toString();
  record->mDescription = mDescription;
  record->mDate = QDateTime::currentDateTime().date().toString();
  record->mEnd = mDuration.currentTime().toString();
  record->mBegin = mBegin;
  auto duration = QTime::fromString("00::00::00", "hh::mm::ss");
  setDuration(duration);

  emit stopped(record);
}

QString TimeRecordModel::Duration() const { return mDuration.toString(); }

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
