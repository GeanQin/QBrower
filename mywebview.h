#ifndef MYWEBVIEW_H
#define MYWEBVIEW_H

#include "mytabwidget.h"
#include <QWebEngineView>
#include <QWebEnginePage>

class MyWebView : public QWebEngineView
{
Q_OBJECT
public:
    MyWebView(QWidget *parent = nullptr) : QWebEngineView(parent){ }
    void getTabWidget(MyTabWidget *tabWidget);

protected:
    QWebEngineView *createWindow(QWebEnginePage::WebWindowType type);

private:
    MyTabWidget *m_tab;

};

#endif // MYWEBVIEW_H
