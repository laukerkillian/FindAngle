//
// Created by kerla on 26/02/2021.
//

#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include "SvgLoader.h"
#include <QDoubleSpinBox>
#include <Triangle.hpp>

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event) override;
    ~MainWindow() override;

public slots:
    void changeTriangle();

private:
    void init();
    QWidget *m_main;
    QVBoxLayout *m_main_layout;
    //svg renderer
    QHBoxLayout *m_svg_widget_container;
        SvgLoader *m_svg_widget;
    QHBoxLayout *m_forms_container;
        QFormLayout *m_longeur_container;
            QDoubleSpinBox  *m_ab_input; // longeur c
            QDoubleSpinBox  *m_bc_input; // longeur a
            QDoubleSpinBox  *m_ac_input; // longeur b
        QFormLayout *m_angle_container;
            QDoubleSpinBox  *m_A_input; // angle A
            QDoubleSpinBox  *m_B_input; // angle B
            QDoubleSpinBox  *m_C_input; // angle C

            Triangle *m_triangle;
};


#endif //TEST_MAINWINDOW_H
