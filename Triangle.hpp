//
// Created by kerla on 12/02/2021.
//

#ifndef FINDANGLE_Triangle_HPP
#define FINDANGLE_Triangle_HPP


#include <QString>

class Triangle {
public:
    Triangle(double ab, double bc, double ac);
    double getAngle(char angle);
    double getAngle(char angle, QString type);
    ~Triangle();
private:
    double m_ab = 0;
    double m_bc = 0;
    double m_ac = 0;
};


#endif //FINDANGLE_Triangle_HPP
