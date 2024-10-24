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

	Row {
		anchors.fill: parent
		spacing: 5
		Rectangle {
			width: parent.width / 3
			height: 40
			color: Colors.darkGray
			border.color: Colors.lightGray
			TextInput {
				anchors.fill: parent
				text: timeRecord.Description

				font.pointSize: 15
				color: Colors.fontColor
				onAccepted: timeRecord.Description = text
			}
		}
		Rectangle {
			width: parent.width / 3
			height: 40
			color: Colors.darkGray
			border.color: Colors.lightGray
			Text {
				id: currentTime
				anchors.centerIn: parent
				color: Colors.fontColor
				font.pointSize: 15
				text: timeRecord.Duration
			}
		}
		Rectangle {
			width: parent.width / 3
			height: 40
			color: Colors.darkGray
			border.color: Colors.lightGray
			Button {
				id: startBtn
				flat: true
				anchors.centerIn: parent
				onClicked: {
					isStarted === true ? timeRecord.stop() : timeRecord.start()
					isStarted = !isStarted
					startBtn.highlighted = !startBtn.highlighted
				}
				text: isStarted === true ? "Stop" : "Start"
			}
		}
	}
}
