pragma main
import QtQuick
import QtQuick.Controls

Rectangle {
    color: "#f0f3f4"

    Column {
        anchors.centerIn: parent
        spacing: 50

        StaticText {
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Hello World!"
            font.pixelSize: 30
        }

        Switch {
            id: switchButton
            anchors.horizontalCenter: parent.horizontalCenter
            onCheckedChanged: LED.setEnabled(checked)
        }

        Item {
            anchors.horizontalCenter: parent.horizontalCenter
            width: qtLogo.width
            height: qtLogo.height

            Image {
                id: qtLogo
                source: "images/qt.png"
                opacity: switchButton.checked ? 1 : 0
                y: switchButton.checked ? 0 : 50
                Behavior on opacity { NumberAnimation { duration: 600; easing.type: Easing.OutCubic } }
                Behavior on y { NumberAnimation { duration: 600; easing.type: Easing.OutCubic } }
            }
        }
    }
}
