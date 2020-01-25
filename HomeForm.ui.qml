import QtQuick 2.13
import QtQuick.Controls 2.13
import QtQuick.Controls 1.4 as OldControls
import TableModel 0.1

Page {
    width: 1000
    height: 400
    focusPolicy: Qt.NoFocus

    title: qsTr("Home")

    Label {
        text: qsTr("Dosya Adı:")
        anchors.verticalCenterOffset: 179
        anchors.horizontalCenterOffset: -61
        anchors.centerIn: parent
    }

    property alias loadButton : loadButton

    Button {
        id: loadButton
        x: 27
        y: 53
        text: qsTr("Klasör Seç")

    }

    Connections {
        target: loadButton
        onClicked: folderDialog.open()
    }

    BorderImage {
        id: borderImage
        x: 254
        y: 53
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
        x: 647
        y: 53
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

    Label {
        id: lbl_filename
        x: -9
        y: 0
        text: GIO.fileName
        anchors.verticalCenterOffset: 179
        anchors.horizontalCenterOffset: 56
        anchors.centerIn: parent
    }

    Label {
        id: lbl_dbconn
        x: 0
        y: -6
        color: (lbl_dbconn.text === "DB -"
                ? 'red'
                : lbl_dbconn.text === "DB +"
                  ? 'green'
                  : 'yellow')
        text: GIO.lbl_dbConn
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        anchors.centerIn: parent
        anchors.horizontalCenterOffset: -46
        anchors.verticalCenterOffset: -170
    }

    Label {
        id: lbl_webserverConn
        x: 3
        y: -9
        color: (lbl_webserverConn.text === "WEB -"
                    ? 'red'
                    : lbl_webserverConn.text === "WEB +"
                    ? 'green'
                    : 'yellow')
        text: GIO.lbl_webserverConn
        anchors.verticalCenterOffset: -170
        horizontalAlignment: Text.AlignLeft
        anchors.centerIn: parent
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: 105
    }

    Button {
        id: querryButton
        x: 27
        y: 117
        width: 65
        text: qsTr("Sorgu")
        checked: true
    }

    BusyIndicator {
        id: busyIndicator
        x: 112
        y: 117
        running: GIO.busyIndicatorState
    }

    Connections {
        target: querryButton
        onClicked: {
            GIO.queryImage()
            //busyIndicator.running = true
        }
    }

    TextEdit {
        id: resultEdit
        x: 27
        y: 185
        width: 111
        height: 31
        color: "#ce0a0a"
        text: GIO.result
        font.italic: true
        font.underline: false
        font.bold: true
        font.pixelSize: 22
        horizontalAlignment: Text.AlignHCenter

        Rectangle {
            anchors.fill: parent
            anchors.margins: -border.width
            z: -1
            border.width: 1
            color: "#00ff7b"
        }
        MouseArea {
            id: resultEditMouseArea
            anchors.fill: parent
            propagateComposedEvents: true
        }
    }

    Button {
        id: insertButton
        x: 98
        y: 117
        width: 65
        text: qsTr("DB")
        checked: true
    }

    Connections {
        target: insertButton
        onClicked: {
            GIO.resultFixed = checkFixed.checked;
            GIO.setResult(resultEdit.text);
            checkFixed.checked = false;
        }
    }

    CheckBox {
        id: checkFixed
        x: 169
        y: 117
        text: qsTr("Fixed")
        checked: false
    }

    Connections {
        target: resultEditMouseArea
        onClicked: {
            checkFixed.checked = true;
            resultEdit.forceActiveFocus();
        }
    }

    GridView {
        id: gridView
        x: 722
        y: 53
        width: 140
        height: 140
        delegate: Item {
            x: 5
            height: 50
            Column {
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    x: 5
                    text: name
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                spacing: 5
            }
        }
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        cellWidth: 70
        cellHeight: 70
    }

    ListModel {
        id: libraryModel
        ListElement {
            title: "A Masterpiece"
            author: "Gabriel"
        }
        ListElement {
            title: "Brilliance"
            author: "Jens"
        }
        ListElement {
            title: "Outstanding"
            author: "Frederik"
        }
    }

    Rectangle {
        id: rectangle
        x: 716
        y: 190
        width: 200
        height: 200
        color: "#ffffff"
        TableView {
            anchors.fill: parent
            columnSpacing: 1
            rowSpacing: 1
            clip: true

            model: TableModel {}

            delegate: Rectangle {
                implicitWidth: 100
                implicitHeight: 50
                Text {
                    text: display
                }
            }
        }
    }




}
