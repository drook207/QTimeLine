import QtQuick 2.15
import QtQuick.Layouts 2.15
import QtQuick.Controls
import "../Singletons"

Item {
	property alias headline: hl.text
	property alias borderColor: header.border.color

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
				Text {
					id: hl
					color: Colors.fontColor
					font.family: "Hack"
					styleColor: Colors.fontColor
					font.pointSize: 15
					anchors.margins: 10
				}

				Text {
					id: currentTime
					color: Colors.fontColor
					font.pointSize: 15
					anchors.margins: 10
					text: "00:00"
				}
			}
			Button {

				onClicked: {
					console.log("foo")
				}
			}
		}
	}
}
