#ifndef IPTCUSTOMVIEW_HH
#define IPTCUSTOMVIEW_HH
#include <QPixmap>
#include <QtWidgets>
#include <QWidget>

class IPTCustomView :public QGraphicsView
{
public:
    IPTCustomView(QWidget* parent =0);
protected:
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // IPTCUSTOMVIEW_HH

