import QtQuick 2.13
import QtQuick.Controls 2.13
import Qt.labs.platform 1.0 as NativeDialogs
//import com.guiobject 1.0
//import QtQuick.Window 2.11
//import TableModel 0.1

ApplicationWindow {
    id: window
    visible: true
    width: 1000
    height: 480
    title: qsTr("Stack")

    /*GuiObject {
        id: guiobject
    }*/

    header: ToolBar {
        contentHeight: toolButton.implicitHeight

        ToolButton {
            id: toolButton
            text: stackView.depth > 1 ? "\u25C0" : "\u2630"
            font.pixelSize: Qt.application.font.pixelSize * 1.6
            onClicked: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }
        }

        Label {
            text: stackView.currentItem.title
            anchors.centerIn: parent
        }
    }

    Drawer {
        id: drawer
        width: window.width * 0.66
        height: window.height

        Column {
            anchors.fill: parent

            ItemDelegate {
                text: qsTr("Page 1")
                width: parent.width
                onClicked: {
                    stackView.push("Page1Form.ui.qml")
                    drawer.close()
                }
            }
            ItemDelegate {
                text: qsTr("Page 2")
                width: parent.width
                onClicked: {
                    stackView.push("Page2Form.ui.qml")
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stackView
        initialItem: "HomeForm.ui.qml"
        anchors.fill: parent



    }

    NativeDialogs.FolderDialog {
        id: folderDialog
        folder: "file:///D:/Engineering/Repository Data/meter/ngmeter-data"
        //currentFolder: viewer.folder
        onAccepted: {
            //console.log(currentFolder)
            //guiFns.setPath(currentFolder)
            //GuiObject.setPath(currentFolder)
            GIO.setPath(currentFolder)

        }
    }

    /*Window {
        visible: true
        width: 640
        height: 480
        title: qsTr("Hello World")
        color: '#222222'

        TableView {
            id: tableView

            columnWidthProvider: function (column) { return 300; }
            rowHeightProvider: function (column) { return 60; }
            anchors.fill: parent
            leftMargin: rowsHeader.implicitWidth
            topMargin: columnsHeader.implicitHeight
            model: TableModel {}
            delegate: Item {
                Text {
                    text: display
                    anchors.fill: parent
                    anchors.margins: 10

                    color: '#aaaaaa'
                    font.pixelSize: 15
                    verticalAlignment: Text.AlignVCenter
                }
            }
            Rectangle { // mask the headers
                z: 3
                color: "#222222"
                y: tableView.contentY
                x: tableView.contentX
                width: tableView.leftMargin
                height: tableView.topMargin
            }

            Row {
                id: columnsHeader
                y: tableView.contentY
                z: 2
                Repeater {
                    model: tableView.columns > 0 ? tableView.columns : 1
                    Label {
                        width: tableView.columnWidthProvider(modelData)
                        height: 35
                        text: "Column" + modelData
                        color: '#aaaaaa'
                        font.pixelSize: 15
                        padding: 10
                        verticalAlignment: Text.AlignVCenter

                        background: Rectangle { color: "#333333" }
                    }
                }
            }
            Column {
                id: rowsHeader
                x: tableView.contentX
                z: 2
                Repeater {
                    model: tableView.rows > 0 ? tableView.rows : 1
                    Label {
                        width: 180
                        height: tableView.rowHeightProvider(modelData)
                        text: "Row" + modelData
                        color: '#aaaaaa'
                        font.pixelSize: 15
                        padding: 10
                        verticalAlignment: Text.AlignVCenter

                        background: Rectangle { color: "#333333" }
                    }
                }
            }

            ScrollIndicator.horizontal: ScrollIndicator { }
            ScrollIndicator.vertical: ScrollIndicator { }
        }
    }*/

}
