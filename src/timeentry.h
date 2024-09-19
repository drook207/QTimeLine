#pragma once

#include <QDateTime>
#include <QObject>
namespace QTimeLine {
// forewarding

class TimeEntryManager;
/*!
 * \brief The TimeEntry class
 */
class TimeEntry : public QObject {
  Q_OBJECT
public:
  TimeEntry();
  /*!
   * \brief TimeEntry
   * \param entry
   * \param parent
   */
  explicit TimeEntry(const TimeEntry &entry, QObject *parent = nullptr);
  /*!
   * \brief TimeEntry
   * \param entry
   * \param parent
   */
  explicit TimeEntry(const TimeEntry &&entry, QObject *parent = nullptr);
  /*!
   * \brief TimeEntry
   * \param id
   * \param description
   * \param date
   * \param begin
   * \param end
   * \param duration
   */
  TimeEntry(quint64 id, const QString &description, const QString &date,
			const QString &begin, const QString &end, const QString &duration);
  /*!
   * \brief TimeEntry
   * \param id
   * \param description
   * \param date
   * \param begin
   * \param end
   * \param duration
   */
  TimeEntry(quint64 id, const QString &description, const QDateTime &date,
			const QString &begin, const QString &end, const QString &duration);

  ~TimeEntry() = default;

  /*!
   * \brief operator =
   * \param other
   * \return
   */
  TimeEntry &operator=(const TimeEntry &other);
  /*!
   * \brief operator =
   * \param other
   * \return
   */
  TimeEntry &operator=(const TimeEntry &&other);

  /*!
   * \brief operator ==
   * \param other
   * \return
   */
  bool operator==(const TimeEntry &other);

  /*!
   * \brief operator !=
   * \param other
   * \return
   */
  bool operator!=(const TimeEntry &other);

  bool isValid() const;

  friend class TimeEntryManager;

signals:

protected:
  quint64 mId{};
  QString mDescription{};
  QString mDate{};
  QString mBegin{};
  QString mEnd{};
  QString mDuration{};

private:
  bool mIsValid{};
};
} // namespace QTimeLine
