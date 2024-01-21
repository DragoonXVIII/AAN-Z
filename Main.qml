import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow
{
    visible: true
    width: 1600
    height: 900
    title: "AAN-Z: Numerical Analysis Algorithms POLLUB"
    color: "#fdd1b4"

    maximumWidth: width
    maximumHeight: height
    minimumWidth: width
    minimumHeight: height

    StackView
    {
        id: algorithmsWorkSpace
        width: parent.width / 10 * 7
        height: parent.height / 10 * 7
        anchors.centerIn: parent
        visible: false

        initialItem: num_Systems
    }

    Rectangle
    {
        id: num_Systems
        anchors.fill: parent
        color: "orange"
    }


    Item
    {
        id: menu
        width: parent.width / 10 * 7
        height: parent.height / 10 * 7
        anchors.centerIn: parent
        visible: true

        ListModel
        {
            id: algorithmsModel
            ListElement { name: "Numeral systems"; source: "Num_Systems.qml" }
            ListElement { name: "Horner's method"; source: "Horner.qml" }
            ListElement { name: "Lagrange's Interpolation"; source: "Lagrange.qml" }
            ListElement { name: "Newton's Interpolation"; source: "Newton.qml" }
            ListElement { name: "Neville's Formula"; source: "Neville.qml" }
            ListElement { name: "Hermite Interpolation"; source: "Hermite.qml" }
            ListElement { name: "Least Squares Method"; source: "Least_Squares_Method.qml" }
            ListElement { name: "Numerical Integration (examples)"; source: "Num_Integration.qml" }
        }

        GridView
        {
            id: algorithmsView
            width: parent.width
            height: parent.height

            cellWidth: parent.width / 4
            cellHeight: parent.height / 2

            model: algorithmsModel

            delegate: Item
            {
                id: algorithTile
                width: algorithmsView.cellWidth
                height: algorithmsView.cellHeight

                Rectangle
                {
                    id: rectangleTile
                    width: parent.width/10*9
                    height: parent.height/10*9
                    anchors.centerIn: parent
                    color: "#ED2939"
                    Column
                    {
                        width: parent.width
                        spacing: 10
                        Image
                        {
                            anchors.horizontalCenter: parent.horizontalCenter
                            sourceSize: Qt.size(rectangleTile.width/10*7, rectangleTile.width/10*7)
                            //width: rectangleTile.width/10*7
                            //height: rectangleTile.width/10*7
                            fillMode: Image.PreserveAspectFit
                            source: "qrc:/assets/assets/icon.svg"
                        }
                        Text
                        {
                            width: parent.width
                            text: model.name
                            font.family: "Consolas"
                            font.bold: true
                            horizontalAlignment: Text.AlignHCenter
                            font.pixelSize: 24
                            color: "#ffffff"
                            wrapMode: Text.WordWrap
                        }
                    }
                }

                MouseArea
                {
                    anchors.fill: parent
                    onClicked:
                    {
                        backButton.visible = true;
                        menu.visible = false;
                        algorithmsWorkSpace.visible = true;

                    }
                }
            }
        }
    }

    Rectangle
    {
        id: backButton
        width: 64
        height: 64
        anchors.top: parent.top
        anchors.left: parent.left

        visible: false
        color: "transparent"

        Image
        {
            sourceSize: Qt.size(32, 32)
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            source: "qrc:/assets/assets/back.svg"
            fillMode: Image.PreserveAspectFit
        }


        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                backButton.visible = false;
                algorithmsWorkSpace.visible = false;
                menu.visible = true;
            }
        }
    }
}


/*import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow
{
    visible: true
    width: 1600
    height: 900
    title: "AAN-Z: Numerical Analysis Algorithms POLLUB"
    color: "blue"

    ListModel
    {
        id: titlesModel
        ListElement { name: "Numeral systems"; source: "Num_Systems.qml" }
        ListElement { name: "Horner's method"; source: "Horner.qml" }
        ListElement { name: "Lagrange's Interpolation"; source: "Lagrange.qml" }
        ListElement { name: "Newton's Interpolation"; source: "Newton.qml" }
        ListElement { name: "Neville's Formula"; source: "Neville.qml" }
        ListElement { name: "Hermite Interpolation"; source: "Hermite.qml" }
        ListElement { name: "Least Squares Method"; source: "Least_Squares_Method.qml" }
        ListElement { name: "Numerical Integration (examples)"; source: "Num_Integration.qml" }
    }

    Item
    {
        width: parent.width/10*7
        height: parent.height/10*7

        GridView
        {
            id: algorithmsView;
            width: parent.width;
            height: parent.height;
            cellHeight: height/2
            cellWidth: width/8
            model: titlesModel
            delegate:  Item
            {
                Rectangle
                {
                    width: parent.width/10*9
                    height: parent.height/10*9
                    color: "red"
                }

            }
        }
    }

    Rectangle
    {
        id: backButton
        width: parent.width/16
        height: parent.height/16
        anchors.top: parent.top
        anchors.left: parent.left
        color: "yellow"
        Image
        {
            anchors.fill: parent
            source: "qrc:/assets/back.svg"
            fillMode: Image.PreserveAspectFit
        }

        visible: false
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                // Tutaj wracamy do głównego widoku po kliknięciu przycisku "Cofnij"
                listView.visible = true;
                backButton.visible = false;
            }
        }
    }
}
*/
