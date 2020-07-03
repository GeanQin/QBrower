#include "mytabwidget.h"
#include "mywebview.h"
#include <QDebug>
#include <QWidget>
#include <QApplication>
#include <QHBoxLayout>

void MyTabWidget::mouseDoubleClickEvent(QMouseEvent* e){
    this->newTab();
    this->setCurrentIndex(this->tabBar()->count()-1);
}

void MyTabWidget::closeTab(int index){
    this->removeTab(index);
    m_views.removeAt(index);
    if(this->tabBar()->count()==0){
        QApplication* app;
        app->quit();
    }
}

void MyTabWidget::newTab(){
    MyWebView *new_view = new MyWebView;
    new_view->getTabWidget(this);
    m_views.append(new_view);
    this->addTab(new_view,"No title");
}

void MyTabWidget::loadWeb(QString url){
    m_views.at(this->currentIndex())->load(QUrl(url));
}

QList<QWebEngineView *> MyTabWidget::views(){
    return m_views;
}
