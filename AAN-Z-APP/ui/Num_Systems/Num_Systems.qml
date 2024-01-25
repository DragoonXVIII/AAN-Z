import QtQuick 2.15
import QtQuick.Controls 2.15



Rectangle
{
    id: workSpace
    color: "black"
    opacity: 0.5

    Column
    {
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20
        Row
        {
            spacing: 20
            //Input number num_System
            TextField
            {
                id: inputNumberField
                width: 200
                height: 50
                placeholderText: "Liczba"
                font.pointSize: 24
                horizontalAlignment: TextInput.AlignHCenter
                validator: IntValidator
                {
                    bottom: -2147483647; top: 2147483647;
                }
            }

            //ComboBox base num_System
            ComboBox
            {
                id: inputNumberSystemComboBox
                width: 80
                height: 50
                font.pointSize: 24
                model: ["2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"]
                currentIndex: 8
            }
        }

        Row
        {
            spacing: 20
             // Pole do wypisania liczby w wybranym systemie liczbowym
            TextField
            {
                id: outputNumberField
                width: 200
                height: 50
                placeholderText: "Wynik"
                font.pointSize: 24
                horizontalAlignment: TextInput.AlignHCenter
                readOnly: true
            }

            //ComboBox target num_System
            ComboBox
            {
                id: outputNumberSystemComboBox
                width: 80
                height: 50
                font.pointSize: 24
                model: ["2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16"]
                currentIndex: 0 // Domyślnie ustawiony na dziesiętny (10)
            }
        }

        Button
        {
            width: 200
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked:
            {
                //handle signal
            }
            text: "Oblicz"
            font.pointSize: 24
        }
    }


}
