#pragma once

#include <QDateTime>
#include <QObject>
namespace QTimeLine {
// forewarding

class TimeRecordDatabaseManager;
/*!
 * \brief The TimeEntry class
 */
class TimeRecord : public QObject {
  Q_OBJECT
public:
  TimeRecord();
  /*!
   * \brief TimeRecord
   * \param entry
   * \param parent
   */
  TimeRecord(const TimeRecord &entry, QObject *parent = nullptr);
  /*!
   * \brief TimeRecord
   * \param entry
   * \param parent
   */
  TimeRecord(const TimeRecord &&entry, QObject *parent = nullptr) noexcept;
  /*!
   * \brief TimeRecord
   * \param id
   * \param description
   * \param date
   * \param begin
   * \param end
   * \param duration
   */
  TimeRecord(quint64 id, const QString &description, const QString &date,
			const QString &begin, const QString &end, const QString &duration);
  /*!
   * \brief TimeRecord
   * \param id
   * \param description
   * \param date
   * \param begin
   * \param end
   * \param duration
   */
  TimeRecord(quint64 id, const QString &description, const QDateTime &date,
			const QString &begin, const QString &end, const QString &duration);

  ~TimeRecord() override = default;

  /*!
   * \brief operator =
   * \param other
   * \return
   */
  TimeRecord &operator=(const TimeRecord &other);
  /*!
   * \brief operator =
   * \param other
   * \return
   */
  TimeRecord &operator=(TimeRecord &&other) noexcept;

  /*!
   * \brief operator ==
   * \param other
   * \return
   */
  friend auto operator==(const TimeRecord &lhs,
						 const TimeRecord &rhs) -> bool const;

  /*!
   * \brief operator !=
   * \param other
   * \return
   */
  friend auto operator!=(const TimeRecord &lhs,
						 const TimeRecord &rhs) -> bool const;

  [[nodiscard]] bool isValid() const;

  friend class TimeRecordDatabaseManager;

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
