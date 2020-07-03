#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_widget = new QWidget;
    btn_back = new QPushButton;
    btn_forword = new QPushButton;
    btn_reload = new QPushButton;
    btn_load = new QPushButton;
    btn_history = new QPushButton;
    line_address = new QLineEdit;
    line_value = new QLineEdit;
    m_vbox = new QVBoxLayout;
    m_hbox = new QHBoxLayout;
    m_tab = new MyTabWidget;

    btn_back->setText("◂");
    btn_forword->setText("▸");
    btn_reload->setText("↺");
    btn_load->setText("GO");
    btn_history->setText("≡");

    line_value->setEnabled(false);

    m_hbox->addWidget(btn_back);
    m_hbox->addWidget(btn_forword);
    m_hbox->addWidget(btn_reload);
    m_hbox->addWidget(line_address);
    m_hbox->addWidget(btn_load);
    m_hbox->addWidget(btn_history);
    m_vbox->addLayout(m_hbox);
    m_vbox->addWidget(m_tab);
    m_vbox->addWidget(line_value);

    m_tab->setTabsClosable(true);
    m_tab->newTab();

    m_hbox->setMargin(0);
    m_vbox->setMargin(0);
    m_hbox->layout()->setSpacing(0);
    m_vbox->layout()->setSpacing(0);
    m_widget->setLayout(m_vbox);

    this->setCentralWidget(m_widget);

    m_desktopWidget = QApplication::desktop();
    m_deskRect = m_desktopWidget->availableGeometry();
    resize(m_deskRect.width(),m_deskRect.height());

    connect(m_tab,&MyTabWidget::tabCloseRequested,m_tab,&MyTabWidget::closeTab);
    connect(m_tab,&MyTabWidget::tabBarClicked,this,[=](){
        qDebug() << m_tab->currentIndex();
    });
    connect(btn_load,&QPushButton::clicked,this, [=](){
        m_tab->loadWeb(line_address->text());
    });
}

MainWindow::~MainWindow()
{

}
