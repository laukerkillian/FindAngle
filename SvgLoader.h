//
// Created by kerla on 27/02/2021.
//

#ifndef TEST_SVGLOADER_H
#define TEST_SVGLOADER_H

#include <QtSvg/QSvgWidget>
#include <QString>

class SvgLoader : public QSvgWidget {
public:
     explicit SvgLoader(QWidget *parent = nullptr);
     explicit SvgLoader(QString *content = nullptr, QWidget *parent = nullptr);
     void polynome(int ax = 0, int ay = 0, int bx = 0, int by = 0, int cx = 0, int cy = 0);
     void writefile(QString content = "", int viewboxX = 30, int viewboxY = 30);
     void triangleInvalide();
};


#endif //TEST_SVGLOADER_H
