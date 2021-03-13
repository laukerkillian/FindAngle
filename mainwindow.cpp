//
// Created by kerla on 26/02/2021.
//

#include "mainwindow.h"
#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <Triangle.hpp>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->init();
}

void MainWindow::init() {
    this->setWindowIcon(QIcon("../assets/logo.png"));
    this->setWindowTitle("FindAngle");
    m_main = new QWidget(this);

    m_main_layout = new QVBoxLayout();
    m_main->setLayout(m_main_layout);

    // widget svg
    m_svg_widget_container = new QHBoxLayout();
    m_main_layout->addLayout(m_svg_widget_container);

    m_svg_widget = new SvgLoader(this);
    m_svg_widget->polynome(0, 0, 100, 0, 100, 100);
    m_svg_widget_container->addWidget(m_svg_widget);
    // add in main layout

    m_forms_container = new QHBoxLayout();
    m_main_layout->addLayout(m_forms_container);

    // longueurs
        m_longeur_container = new QFormLayout();
        m_forms_container->addLayout(m_longeur_container);

            m_ab_input = new QDoubleSpinBox(this);
            m_longeur_container->addRow("Longeur AB", m_ab_input);

            m_bc_input = new QDoubleSpinBox(this);
            m_longeur_container->addRow("Longeur BC", m_bc_input);

            m_ac_input = new QDoubleSpinBox(this);
            m_longeur_container->addRow("Longeur AC", m_ac_input);

    // angles
        m_angle_container = new QFormLayout();
        m_forms_container->addLayout(m_angle_container);

            m_A_input = new QDoubleSpinBox(this);
            m_A_input->setReadOnly(true);
            m_angle_container->addRow("Angle Â", m_A_input);

            m_B_input = new QDoubleSpinBox(this);
            m_B_input->setReadOnly(true);
            m_angle_container->addRow("Angle B̂", m_B_input);

            m_C_input = new QDoubleSpinBox(this);
            m_C_input->setReadOnly(true);
            m_angle_container->addRow("Angle Ĉ", m_C_input);

    this->setCentralWidget(m_main);

    m_ab_input->setValue(6);
    m_bc_input->setValue(4);
    m_ac_input->setValue(4);

    m_triangle = new Triangle(m_ab_input->value(), m_bc_input->value(), m_ac_input->value());

    m_A_input->setValue(m_triangle->getAngle('A'));
    m_B_input->setValue(m_triangle->getAngle('B'));
    m_C_input->setValue(m_triangle->getAngle('C'));

    changeTriangle();

    connect(m_ab_input, SIGNAL(valueChanged(double)), this, SLOT(changeTriangle()));
    connect(m_bc_input, SIGNAL(valueChanged(double)), this, SLOT(changeTriangle()));
    connect(m_ac_input, SIGNAL(valueChanged(double)), this, SLOT(changeTriangle()));
}

MainWindow::~MainWindow() {
    delete m_main;
    delete m_triangle;

    m_triangle = nullptr;
    m_main = nullptr;
    m_svg_widget = nullptr;
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    //qDebug() << "salut";
    QWidget::resizeEvent(event);
}

void MainWindow::changeTriangle() {
    delete m_triangle;
    m_triangle = new Triangle(m_ab_input->value(), m_bc_input->value(), m_ac_input->value());

    m_A_input->setValue(m_triangle->getAngle('A'));
    m_B_input->setValue(m_triangle->getAngle('B'));
    m_C_input->setValue(m_triangle->getAngle('C'));

    double hypotenus = m_ab_input->value();
    char hypotenusIs ('A');
    bool validTriangle = true;
    if(m_bc_input->value() > hypotenus) {
        hypotenus = m_bc_input->value();
        hypotenusIs = 'B';
    }
    if(m_ac_input->value() > hypotenus) {
        hypotenus = m_ab_input->value();
        hypotenusIs = 'C';
    }
    if(hypotenusIs == 'C' && hypotenus >= (m_ab_input->value() + m_bc_input->value())) {
        validTriangle = false;
    }else if(hypotenusIs == 'A' && hypotenus >= (m_ac_input->value() + m_bc_input->value())){
        validTriangle = false;
    }else if(hypotenusIs == 'B' && hypotenus >= (m_ab_input->value() + m_ac_input->value())) {
        validTriangle = false;
    }

    if(!validTriangle) {
        m_svg_widget->triangleInvalide();
    }else{
        double f1 = m_triangle->getAngle('A');
        double p = m_ac_input->value() * m_triangle->getAngle('B');
        double f2 = -m_triangle->getAngle('B'); // on a pas mis le + p
        double f3 = 0;

        // quand f3 == f1
        double x1 = f1 != 0 ? f3 / f1 : 0; // 0
        double y1 = f3 * x1; // 0
        // quand f3 ==f2
        double x2 = f2 != 0 ? -p / f2 : 0;
        double y2 = f3 * p; // 0
        // quand f1 == f2
        double x3 = (f2 - f1) != 0 ? -p / (f2 - f1) : 0;
        double y3 = f1 * x3;

        x1 *= 1000;
        y1 *= 1000;
        x2 *= 1000;
        y2 *= 1000;
        x3 *= 1000;
        y3 *= 1000;

        m_svg_widget->polynome(x1, y1, x2, y2, x3, y3);
    }
}
