#ifndef MYTABWIDGET_H
#define MYTABWIDGET_H

#include <QTableWidget>
#include <QWebEngineView>
#include <QList>

class MyTabWidget : public QTabWidget
{
Q_OBJECT
public:
    MyTabWidget(QWidget *parent = nullptr) : QTabWidget(parent){ }
    void closeTab(int index);
    void newTab();
    void loadWeb(QString url);
    QList<QWebEngineView *> views();

protected:
    void mouseDoubleClickEvent(QMouseEvent* e);

private:
    QList<QWebEngineView *> m_views;

};
#endif // MYTABWIDGET_H
