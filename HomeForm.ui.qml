import QtQuick 2.13
import QtQuick.Controls 2.13

Page {
    width: 700
    height: 400
    focusPolicy: Qt.NoFocus

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

    property alias imageslider : imageslider

    Slider {
        id: imageslider
        x: 638
        y: 27
        width: 48
        height: 300
        snapMode: Slider.SnapAlways
        focus: GIO.sliderFocus
        focusPolicy: Qt.StrongFocus
        from: 0
        to: GIO.filesInDirListSize-1
        orientation: Qt.Vertical
        stepSize: 1.0
        wheelEnabled: false
        live: false
        value: GIO.fileIndex

    }

    Connections {
        target: imageslider
        onMoved: GIO.setIndex(imageslider.value)
    }

}
