#include "mywebview.h"

QWebEngineView *MyWebView::createWindow(QWebEnginePage::WebWindowType type)
{
    if(type==QWebEnginePage::WebBrowserBackgroundTab){
        m_tab->newTab();
        return m_tab->views().at(m_tab->tabBar()->count()-1);
    }else if(type==QWebEnginePage::WebBrowserTab||type==QWebEnginePage::WebBrowserWindow){
        m_tab->newTab();
        m_tab->setCurrentIndex(m_tab->tabBar()->count()-1);
        return m_tab->views().at(m_tab->tabBar()->count()-1);
    }
    return this;
}

void MyWebView::getTabWidget(MyTabWidget *tabWidget){
    m_tab = tabWidget;
}
