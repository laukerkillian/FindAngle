//
// Created by kerla on 27/02/2021.
//

#include "SvgLoader.h"
#include <QDir>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>

SvgLoader::SvgLoader(QWidget *parent) : QSvgWidget(parent) {
    setFixedSize(300, 300);
}

SvgLoader::SvgLoader(QString *content, QWidget *parent) : QSvgWidget(parent) {

}

void SvgLoader::writefile(QString content, int viewboxX, int viewboxY) {
    QString filename  = QDir::currentPath() + "/Data.svg";
    QFile file (filename);
    if ( file.open(QIODevice::ReadWrite) )
    {
        file.resize(0); // clear the file
        QTextStream stream( &file );

        stream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<svg xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" width=\"50pt\" height=\"50pt\" viewBox=\"0 0 " + QString::number(viewboxX) + " " + QString::number(viewboxY) + "\" version=\"1.2\">\n" << content << "\n</svg>";
        //qDebug() << stream.readAll();
        file.close();
        this->load(filename);
    }
}

void SvgLoader::polynome(int ax, int ay, int bx, int by, int cx, int cy) {
    int viewboxX = ax;
    if(bx > viewboxX) {
        viewboxX = bx;
    }
    if(cx > viewboxX) {
        viewboxX = cx;
    }
    viewboxX += 1;
    int viewboxY = ay;
    if(by > viewboxY) {
        viewboxY = by;
    }
    if(cy > viewboxY) {
        viewboxY = cy;
    }
    viewboxY += 1;

    writefile(QString("<polygon points=\"" + QString::number(ax) +  " " + QString::number(ay) +  ", " + QString::number(bx) +  " " + QString::number(by) +  ", " + QString::number(cx) +  " " + QString::number(cy) +  "\" />"), viewboxX, viewboxY);
}

void SvgLoader::triangleInvalide() {
    QString filename  = QDir::currentPath() + "/Invalide.svg";
    QFile file (filename);
    if ( file.open(QIODevice::ReadWrite) )
    {
        file.resize(0); // clear the file
        QTextStream stream( &file );

        stream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?><svg width=\"300pt\" height=\"25pt\" version=\"1.2\" viewBox=\"0 0 300 25\" xmlns=\"http://www.w3.org/2000/svg\"><text x=\"10\" y=\"20\" fill=\"#0000ff\" font-family=\"Times New Roman\" font-size=\"20px\" stroke=\"#00ff00\" xmlns=\"http://www.w3.org/2000/svg\">Le triangle ne peut être tracé (inégalité triangulaire) </text></svg>";
        //qDebug() << stream.readAll();
        file.close();
        this->load(filename);
    }
}
