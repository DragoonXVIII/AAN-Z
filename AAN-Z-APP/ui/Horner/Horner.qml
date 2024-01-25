import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15



Rectangle
{
    id: workSpace
    color: "black"
    opacity: 0.5

    ColumnLayout
    {
        height: parent.height/4*3
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        Layout.alignment: Qt.Horizonta;
        spacing: 10

        ComboBox
        {
            id: degreeComboBox
            width: 80
            height: 50
            font.pointSize: 24
            model: ["3", "4", "5", "6", "7", "8", "9"]
            onCurrentIndexChanged:
            {
                coefficientsModel.clear();
                for (var i=currentValue;i>0;i--)
                {
                    coefficientsModel.append({coefficients: i.toString()})
                }
                coefficientsListView.model = coefficientsModel
            }
        }

        ListModel
        {
            id: coefficientsModel
        }

        ListView
        {
            id: coefficientsListView
            width: 80
            height: 500
            model: coefficientsModel
            delegate: ItemDelegate
            {
                width: 80
                Row
                {
                    width: 80
                    Text
                    {
                        id: coefficientDegree
                        width: 50
                        height: 50
                        text: "x^" + model.coefficients + ":"
                        horizontalAlignment: TextInput.AlignRight
                    }
                    TextField
                    {
                        id: coefficient
                        width: 30
                        height: 50
                        horizontalAlignment: TextInput.AlignHCenter
                    }
                }
            }
        }

        Button
        {
            width: 200
            height: 50
            text: "calculate!"
        }
    }
}


