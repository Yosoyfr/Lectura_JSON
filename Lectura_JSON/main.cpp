#include <QCoreApplication>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#include <QDebug>
#include <iostream>
using namespace std;

void jsonExample(QString filename){
    QFile file;
    QString val;
    file.setFileName(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject jsonObject = d.object();
    qDebug()<< "Dimension:";
    qDebug()<< jsonObject.value(QStringLiteral("dimension")).toInt();

    QJsonObject casillas = jsonObject["casillas"].toObject();
    QJsonArray casillass_Dobles = casillas["dobles"].toArray();
    QJsonArray casillas_Triples = casillas["triples"].toArray();

    foreach (const QJsonValue & value, casillass_Dobles) {
        QJsonObject obj = value.toObject();
        qDebug()<< "Coordenada doble x y ";
        qDebug()<< obj.value(QStringLiteral("x")).toInt();
        qDebug()<< obj.value(QStringLiteral("y")).toInt();
    }
    foreach (const QJsonValue & value, casillas_Triples) {
        QJsonObject obj = value.toObject();
        qDebug()<< "Coordenada triple x y ";
        qDebug()<< obj.value(QStringLiteral("x")).toInt();
        qDebug()<< obj.value(QStringLiteral("y")).toInt();
    }
    QJsonArray diccionario = jsonObject["diccionario"].toArray();
    qDebug()<< "DICCIONARIO";
    foreach (const QJsonValue & value, diccionario) {
        QJsonObject obj = value.toObject();
        qDebug()<< "Palabra de diccionario";
        qDebug() << obj.value(QStringLiteral("palabra")).toString();\
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //jsonExample("prueba.json");


    return a.exec();
}
