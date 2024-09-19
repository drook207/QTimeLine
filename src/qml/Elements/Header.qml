import QtQuick 2.15
import QtQuick.Layouts 2.15
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
		height: parent.height * 0.2
		color: Colors.darkGray
		border.color: Colors.lightkGray
		border.width: 2
		Column {
			width: parent.width
			height: parent.height
			Row {
				width: parent.width
				height: parent.height
				Text {
					id: hl
					color: "white"
					font.family: "Hack"
					styleColor: "#cac7c7"
					font.pointSize: 15
					anchors.margins: 10
				}

				RoundButton {}
			}
		}
	}
}
