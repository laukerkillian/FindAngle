//
// Created by kerla on 12/02/2021.
//

#include "Triangle.hpp"
#include <QString>
#include <cmath>

Triangle::Triangle(double ab, double bc, double ac) :
m_ab{ab},
m_bc{bc},
m_ac{ac}
{

}

double Triangle::getAngle(char angle) {
    double resultInRad = 0.;
    switch (angle) {
        case 'A':
            resultInRad = acos( (pow(m_ab, 2) + pow(m_ac, 2) - pow(m_bc, 2)) / (2 * m_ab * m_ac));
            break;
        case 'B':
            resultInRad = acos( (pow(m_bc, 2) + pow(m_ab, 2) - pow(m_ac, 2)) / (2 * m_bc * m_ab));
            break;
        case 'C':
            resultInRad = acos( (pow(m_bc, 2) + pow(m_ac, 2) - pow(m_ab, 2)) / (2 * m_bc * m_ac));
            break;
    }

    return resultInRad;
}

double Triangle::getAngle(char angle, QString type) {
    double resultInRad = Triangle::getAngle(angle);
    if(type == "degree") {
        return (resultInRad * 180) / M_PI;
    }else {
        return  resultInRad;
    }
    return 0.;
}


Triangle::~Triangle() {

}