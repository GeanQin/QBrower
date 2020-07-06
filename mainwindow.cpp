#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QWidget>
#include <QListView>
#include <QStringListModel>

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
    connect(btn_load,&QPushButton::clicked,this, [=](){
        m_tab->loadWeb(line_address->text());
    });
    connect(btn_back,&QPushButton::clicked,this, [=](){
       m_tab->views().at(m_tab->currentIndex())->back();
    });
    connect(btn_forword,&QPushButton::clicked,this, [=](){
       m_tab->views().at(m_tab->currentIndex())->forward();
    });
    connect(btn_reload,&QPushButton::clicked,this, [=](){
       m_tab->views().at(m_tab->currentIndex())->reload();
    });
    connect(btn_history,&QPushButton::clicked,this, [=](){
        QWidget *wg_history = new QWidget;
        QListView *lv_history = new QListView;
        wg_history->resize(200,500);
        wg_history->move((m_deskRect.width()-250),50);
        wg_history->setWindowTitle("History");
        wg_history->setWindowFlags(Qt::WindowTitleHint);
        QStringList list_history;
        m_history = m_tab->views().at(m_tab->currentIndex())->history();
        for(int i=0;i<m_history->items().count();i++){
            list_history.append(m_history->items().at(i).url().toString());
        }
        QStringListModel *m_model = new QStringListModel(list_history);
        lv_history->setModel(m_model);
        lv_history->resize(200,500);
        lv_history->setParent(wg_history);
        connect(lv_history,&QListView::clicked,this, [=](){
            m_tab->views().at(m_tab->currentIndex())->load(QUrl(list_history.at(lv_history->currentIndex().row())));
        });
        wg_history->show();
    });
}

MainWindow::~MainWindow()
{

}
