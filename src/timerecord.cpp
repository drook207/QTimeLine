#include "timerecord.h"
namespace QTimeLine {

TimeRecord::TimeRecord(const TimeRecord &entry, QObject *parent)
	: QObject{parent} {
  *this = entry;
}

TimeRecord::TimeRecord(const TimeRecord &&entry, QObject *parent) noexcept
	: QObject{parent} {
  *this = std::move(entry);
}

TimeRecord::TimeRecord(quint64 id, const QString &description,
					 const QString &date, const QString &begin,
					 const QString &end, const QString &duration)
	: mId(id), mDescription(description), mDate(date), mBegin(begin), mEnd(end),
	  mDuration(duration), mIsValid(true) {}

TimeRecord::TimeRecord(quint64 id, const QString &description,
					 const QDateTime &date, const QString &begin,
					 const QString &end, const QString &duration)
	: mId(id), mDescription(description), mDate(date.toString()), mBegin(begin),
	  mEnd(end), mDuration(duration), mIsValid(true) {}

TimeRecord &TimeRecord::operator=(const TimeRecord &other) {
  this->mId = other.mId;
  this->mDescription = other.mDescription;
  this->mDate = other.mDate;
  this->mBegin = other.mBegin;
  this->mEnd = other.mEnd;
  this->mDuration = other.mDuration;
  return *this;
}

TimeRecord &TimeRecord::operator=(TimeRecord &&other) noexcept {
  this->mId = std::move(other.mId);
  this->mDescription = std::move(other.mDescription);
  this->mDate = std::move(other.mDate);
  this->mBegin = std::move(other.mBegin);
  this->mEnd = std::move(other.mEnd);
  this->mDuration = std::move(other.mDuration);
  return *this;
}

auto operator==(const TimeRecord &lhs, const TimeRecord &rhs) -> bool const {
  return lhs.mId == rhs.mId;
}

auto operator!=(const TimeRecord &lhs, const TimeRecord &rhs) -> bool const {
  return lhs.mId != rhs.mId;
}

bool TimeRecord::isValid() const { return mIsValid; }

TimeRecord::TimeRecord() : mIsValid(false) {}
} // namespace QTimeLine
