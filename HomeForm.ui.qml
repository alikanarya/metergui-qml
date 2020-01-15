import QtQuick 2.13
import QtQuick.Controls 2.13

Page {
    width: 600
    height: 400

    title: qsTr("Home")

    Label {
        text: qsTr("You are on the home page.")
        anchors.centerIn: parent
    }

    property alias loadButton : loadButton

    Button {
        id: loadButton
        x: 53
        y: 36
        text: qsTr("Klasör Seç")

    }

    Connections {
        target: loadButton
        onClicked: folderDialog.open()
    }

    Image {
        id: image
        x: 180
        y: 50
        width: 400
        height: 300
        fillMode: Image.PreserveAspectFit
        //source: "../../../Repository Data/meter/ngmeter-data/2020-01/13/20200113_000001.jpeg"
        source: "file:///D:/Engineering/Repository Data/meter/ngmeter-data/2020-01/13/20200113_000001.jpeg"
    }
}
