import QtQuick 2.15
import "../Singletons"
import "../Elements"

Item {
	width: parent.width
	height: parent.height
	Rectangle {
		anchors.fill: parent
		color: Colors.darkGray
		border.color: Colors.lightGray
		Header {
			headline: qsTr("Start")
			borderColor: Colors.lightGray
		}
	}
}
