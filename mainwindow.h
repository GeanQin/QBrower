#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mytabwidget.h"
#include <QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTabWidget>
#include <QLineEdit>
#include <QDesktopWidget>
#include <QWebEngineHistory>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QDesktopWidget *m_desktopWidget;
    QRect m_deskRect;
    QWidget *m_widget;
    QVBoxLayout *m_vbox;
    QHBoxLayout *m_hbox;
    MyTabWidget *m_tab;
    QPushButton *btn_back;
    QPushButton *btn_forword;
    QPushButton *btn_reload;
    QPushButton *btn_load;
    QPushButton *btn_history;
    QLineEdit *line_address;
    QLineEdit *line_value;
    QWebEngineHistory *m_history;
};

#endif // MAINWINDOW_H
