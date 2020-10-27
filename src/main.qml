
	//main.qml

	import QtQuick 2.12
	import QtQuick.Controls 2.12

	ApplicationWindow {
	    width: 480;
	    height: 700;
	    color: "transparent"
	    background: null

	    Rectangle {
	        id: root
	        anchors.fill: parent
	        border.color: "lightblue"
	        border.width: 2
            color: "#EEE6E6E6"
        }
        Text {
            id: title
            text: qsTr("...")
            font{
                pointSize: 20;
                bold: true;
            }
        }
        Rectangle{

            id: contentData

            border.color: "#FFF"
            color: "transparent"

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: title.bottom;

            anchors.leftMargin: 8
            anchors.topMargin: 6
            anchors.rightMargin: 8

            radius: 5
            height: 200;

            Text {
                text: qsTr("_>")
                font{
                    pointSize: 18;
                }
            }
            TextInput{

                id: expression;
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top

                anchors.leftMargin: 8
                anchors.topMargin: 145
                anchors.rightMargin: 8
                height: 200;

                font.pointSize: 18
            }
        }

        Rectangle{
            id: options
            color: "transparent"

            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: contentData.bottom

            anchors.leftMargin: 8
            anchors.topMargin: 100
            anchors.rightMargin: 8

            Button{
                id: btn_1

                anchors.left: parent.left
                anchors.top: parent.bottom
                anchors.topMargin: 10

                text: qsTr("1.中缀表达式式到后缀表达式的转换")
                font.pointSize: 13

                onClicked: {
                    expression.
                }
            }
            Button{
                id: btn_2

                anchors.left: parent.left
                anchors.top: btn_1.bottom
                anchors.topMargin: 20

                text: qsTr("2.后缀表达式的计算")
                font.pointSize: 13
            }
            Button{
                id: btn_3

                anchors.left: parent.left
                anchors.top: btn_2.bottom
                anchors.topMargin: 20

                text: qsTr("3.中缀表达式的计算")
                font.pointSize: 13
            }
            Button{
                id: btn_4

                anchors.left: parent.left
                anchors.top: btn_3.bottom
                anchors.topMargin: 20

                text: qsTr("4.退出")
                font.pointSize: 13

                onClicked: {
                    Qt.quit();
                }
            }
        }

	}

