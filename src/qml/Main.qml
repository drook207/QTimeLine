import QtQuick
import QTimelineControls
import QtQuick.Controls

Window {
	width: 500
	height: 600
	visible: true
	title: qsTr("QTimeline")
	color: Colors.darkGray
	property bool isStarted: false
	TimeRecordModel {
		id: timeRecord
	}

	Connections {
		target: timeRecord
		function onStopped(record) {
			TimeRecordDatabaseManager.addEntry(record)
		}
	}

	Component.onCompleted: timeRecord.Description = "Project: xyz, Issue: 001"
	Row {
		anchors.fill: parent
		spacing: 10

		Text {
			id: description
			text: timeRecord.Description
			color: Colors.fontColor
			font.pointSize: 10
		}

		Text {
			id: currentTime
			color: Colors.fontColor
			font.pointSize: 15
			text: timeRecord.Duration
		}
		Button {
			id: startBtn
			flat: true
			onClicked: {
				isStarted === true ? timeRecord.stop() : timeRecord.start()
				isStarted = !isStarted
				startBtn.highlighted = !startBtn.highlighted
			}
			text: isStarted === true ? "Stop" : "Start"
		}
	}
}
