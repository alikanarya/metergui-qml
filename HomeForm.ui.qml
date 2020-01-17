import QtQuick 2.13
import QtQuick.Controls 2.13

Page {
    width: 700
    height: 400

    title: qsTr("Home")

    Label {
        text: qsTr("You are on the home page.")
        anchors.verticalCenterOffset: 173
        anchors.horizontalCenterOffset: -163
        anchors.centerIn: parent
    }

    property alias loadButton : loadButton

    Button {
        id: loadButton
        x: 53
        y: 27
        text: qsTr("Klasör Seç")

    }

    Connections {
        target: loadButton
        onClicked: folderDialog.open()
    }

    BorderImage {
        id: borderImage
        x: 232
        y: 27
        width: 400
        height: 300
        opacity: 1
        border.bottom: 0
        border.top: 0
        border.right: 0
        border.left: 0
        //source: "qrc:/qtquickplugin/images/template_image.png"
        source: GIO.imagePath

        Rectangle {
            anchors.fill: parent
            anchors.margins: -border.width
            z: -1
            border.width: 4
            //color: 'red'
            color: "transparent"
        }
    }

    Slider {
        id: imageslider
        x: 638
        y: 27
        width: 48
        height: 300
        orientation: Qt.Vertical
        stepSize: 0.2
        wheelEnabled: false
        live: false
        value: 0
    }
}
