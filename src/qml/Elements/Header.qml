import QtQuick 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls
import "../Singletons"
import QTimelineControls

Item {
	property alias headline: hl.text
	property alias borderColor: header.border.color
	property bool isStarted: false

	id: docroot

	width: parent.width
	height: parent.height



	Rectangle {
		id: header
		width: parent.width
		height: parent.height * 0.1
		color: Colors.darkGray
		border.color: Colors.lightGray
		border.width: 2
		Column {
			width: parent.width
			height: parent.height
			Row {
				width: parent.width
				height: parent.height
				spacing: 10

			}
		}
	}
}
