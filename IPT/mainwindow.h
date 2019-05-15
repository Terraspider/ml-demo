#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsView>
#include <QLabel>
#include <QApplication>
//#include <QShortcut>
#include <QDebug>
#include <QFileDialog>
#include <QDebug>
#include <iostream>
#include <QDebug>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QApplication>
#include <QCoreApplication>
#include <QPixmap>
#include <QtWidgets>
#include <QWidget>
#include <QMouseEvent>
#include <QApplication>
#include <QScrollBar>
#include <qmath.h>


#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
//#include <opencv2/opencv.hpp>
//#include <opencv2/opencv.hpp>
//#include <opencv2/highgui.hpp>

//#include <QMainWindow>
//#include <QImage>
//#ifndef QT_NO_PRINTER
//#include <QtPrintSupport/QPrinter>
//#endif
//QT_BEGIN_NAMESPACE
//class QAction;
//class QLabel;
//class QMenu;
//class QScrollArea;
//class QScrollBar;
//QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    //virtual void wheelEvent(QWheelEvent * event);

    ~MainWindow();

private slots:

    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionSelect_Defect_Image_triggered();
    void on_SelectStandardImage_clicked();
    void on_SelectTestImage_clicked();


    void on_verticalSliderInputScreen1_sliderMoved(int position);
    void on_verticalSliderInputScreen1_valueChanged(int value);


    void on_verticalSliderOutPutScreen_sliderMoved(int position);
    void on_verticalSliderOutPutScreen_sliderPressed();
    void on_verticalSliderOutPutScreen_valueChanged(int value);


    void on_actionInputImageFitWindow_triggered();

    void on_actionOutputImageFitWindow_triggered();

private:
    Ui::MainWindow *ui;

    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QImage* _image;
    QGraphicsItem *item;
    //int  *m_pPimpl;
    //double m_current_scale;
    const QColor clrBKApp;
    void ImageViewer();
    bool loadFile(const QString &);
    void BeautifyUI();

//private slots:
//    void open();
//    void saveAs();
//    void print();
//    void copy();
//    void paste();
//    void zoomIn();
//    void zoomOut();
//    void normalSize();
//    void fitToWindow();
//    void about();

//private:
//    void createActions();
//    void createMenus();
//    void updateActions();
//    bool saveFile(const QString &fileName);
//    void setImage(const QImage &newImage);
//    void scaleImage(double factor);
//    void adjustScrollBar(QScrollBar *scrollBar, double factor);

////    QImage image;
////    QLabel *imageLabel;
////    QScrollArea *scrollArea;
//    double scaleFactor;

////#ifndef QT_NO_PRINTER
////    QPrinter printer;
////#endif

//    QAction *saveAsAct;
//    QAction *printAct;
//    QAction *copyAct;
//    QAction *zoomInAct;
//    QAction *zoomOutAct;
//    QAction *normalSizeAct;
    //    QAction *fitToWindowAct;

public:
    void zoom(qreal factor, QPointF centerPoint);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
protected:
    void wheelEvent ( QWheelEvent * event );
private:
    bool isTouched;
    QPointF mousePos;
    int m_originX;
    int m_originY;
double scaleFactor;
//void scaleImage(double factor);
void fitToWindow();
void updateActions();
};

#endif // MAINWINDOW_H
