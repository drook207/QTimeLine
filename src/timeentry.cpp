#include "timeentry.h"
namespace QTimeLine {

TimeEntry::TimeEntry(const TimeEntry &entry, QObject *parent)
	: QObject{parent} {
  *this = entry;
}

TimeEntry::TimeEntry(const TimeEntry &&entry, QObject *parent)
	: QObject{parent} {
  *this = std::move(entry);
}

TimeEntry::TimeEntry(quint64 id, const QString &description,
					 const QString &date, const QString &begin,
					 const QString &end, const QString &duration)
	: mId(id), mDescription(description), mDate(date), mBegin(begin), mEnd(end),
	  mDuration(duration), mIsValid(true) {}

TimeEntry::TimeEntry(quint64 id, const QString &description,
					 const QDateTime &date, const QString &begin,
					 const QString &end, const QString &duration)
	: mId(id), mDescription(description), mDate(date.toString()), mBegin(begin),
	  mEnd(end), mDuration(duration), mIsValid(true) {}

TimeEntry &TimeEntry::operator=(const TimeEntry &other) {
  this->mId = other.mId;
  this->mDescription = other.mDescription;
  this->mDate = other.mDate;
  this->mBegin = other.mBegin;
  this->mEnd = other.mEnd;
  this->mDuration = other.mDuration;
  return *this;
}

TimeEntry &TimeEntry::operator=(const TimeEntry &&other) {
  this->mId = std::move(other.mId);
  this->mDescription = std::move(other.mDescription);
  this->mDate = std::move(other.mDate);
  this->mBegin = std::move(other.mBegin);
  this->mEnd = std::move(other.mEnd);
  this->mDuration = std::move(other.mDuration);
  return *this;
}

bool TimeEntry::operator==(const TimeEntry &other) {
  return this->mId == other.mId;
}

bool TimeEntry::operator!=(const TimeEntry &other) {
  return this->mId != other.mId;
}

bool TimeEntry::isValid() const { return mIsValid; }

TimeEntry::TimeEntry() : mIsValid(false) {}
} // namespace QTimeLine
