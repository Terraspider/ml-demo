#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsView>
using namespace cv;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    imageLabel = new QLabel;
//    imageLabel->setBackgroundRole(QPalette::Base);
//    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
//    imageLabel->setScaledContents(true);

//    scrollArea = new QScrollArea;
//    scrollArea->setBackgroundRole(QPalette::Dark);
//    scrollArea->setWidget(imageLabel);
//    setCentralWidget(scrollArea);

//    setWindowTitle(tr("Image Viewer"));
//    resize(500, 400);

    ui->actionOpen = new QAction(tr("&Open...;"), this);
    ui->actionOpen->setShortcut(tr("Ctrl+b"));



    //ui->fitToWindowAct = new QAction(tr("&Fit to Window"), this);
//    ui->actionzoomIn->setEnabled(false);
//    ui->actionzoomIn->setCheckable(true);
  //  ui->actionzoomIn->setShortcut(tr("Ctrl+F"));
    connect(ui->actionInputImageFitWindow, SIGNAL(triggered()), this, SLOT(fitToWindow()));

    BeautifyUI();
    // Let me handle your events
//    ui->InputScreen_1->installEventFilter(this);
//    //ui->InputScreen_1->setAcceptDrops(100);
//    ui->verticalSliderInputScreen1->setRange(0, 100);
//    QObject::connect(ui->InputScreen_1, SIGNAL(valueChanged(int)), ui->verticalSliderInputScreen1, SLOT(setValue(int)));
//    //QObject::connect(ui->verticalSliderInputScreen1, SIGNAL(valueChanged(int)),ui->InputScreen_1, SLOT(setValue(int)));

//      ui->verticalSliderInputScreen1->setValue(50);
//      ui->InputScreen_1->setResizeAnchor(QGraphicsView::AnchorViewCenter );

  //  QObject::connect(ui->verticalSliderInputScreen1, SIGNAL(valueChanged(int)), ui->InputScreen_1, SLOT(setZoomLevel(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString imagePath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "",
                tr("JPEG (*.bmp *.jpeg);;PNG (*.png)" )
                );
    cv::Mat img = cv::imread(imagePath.toStdString());
    if (img.empty())
        return;
    // Since OpenCV uses BGR order, we need to convert it to RGB
    cv::cvtColor(img, img, CV_BGR2RGB);
    _image = new QImage(img.size().width, img.size().height, QImage::Format_RGB888);

    // Copy cv::Mat to QImage
    memcpy(_image->scanLine(0), (unsigned char*)img.data, _image->width() * _image->height() * img.channels());

    _image->load(imagePath);

    image = QPixmap::fromImage(*_image);
    item=new QGraphicsPixmapItem(QPixmap::fromImage(*_image));
    scene = new QGraphicsScene(this);

    scene->addPixmap(image);
    scene->setSceneRect(image.rect());

    ui->InputScreen_1->setScene(scene);
    ui->OutPutScreen->setScene(scene);

    ui->InputScreen_1->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatioByExpanding);
    ui->OutPutScreen->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatioByExpanding);
    scene->addItem(item);

}

void MainWindow::on_actionSelect_Defect_Image_triggered()
{
    QString imagePath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "",
                tr("JPEG (*.bmp *.jpeg);;PNG (*.png)" )
                );

    //
    cv::Mat img = cv::imread(imagePath.toStdString());
    if (img.empty())
        return;
    // Since OpenCV uses BGR order, we need to convert it to RGB
    cv::cvtColor(img, img, CV_BGR2RGB);
    _image = new QImage(img.size().width, img.size().height, QImage::Format_RGB888);

    // Copy cv::Mat to QImage
    memcpy(_image->scanLine(0), (unsigned char*)img.data, _image->width() * _image->height() * img.channels());
    // Resize the window to fit video dimensions
   // resize(img.size().width, img.size().height);

    //imageObject = new QImage();
    _image->load(imagePath);

    image = QPixmap::fromImage(*_image);

    scene = new QGraphicsScene(this);
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui->InputScreen_2->setScene(scene);
    ui->InputScreen_2->fitInView(scene->itemsBoundingRect(),Qt::KeepAspectRatioByExpanding);
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}



void MainWindow::on_SelectStandardImage_clicked()
{
 //on_actionOpen_triggered();

    //QString path = '/home/ashiq/OpencvTest';
//    QString path = "/Somepath/mypath";
//    QString  command("python");
//    QStringList params = QStringList() << "opencvtest.py";

//    QProcess *process = new QProcess();
//    //process->startDetached(command, params, path, &processID);
//    process->waitForFinished();
//    process->close();

    QString  program( "/home/ashiq/OpencvTest" );
    QStringList  args = QStringList() << "opencvtest.py";
    //int exitCode = QProcess::execute( program, args );
}

void MainWindow::on_SelectTestImage_clicked()
{
on_actionSelect_Defect_Image_triggered();
}

void MainWindow::BeautifyUI()
{
   // optImgFile.LoadQssFile(strPathQssFile,qApp);

    //Set the application background color
    QPalette *paletteApp=new QPalette();
    paletteApp->setColor(QPalette::Background,clrBKApp);
    this->setPalette(*paletteApp);
    delete paletteApp;
}

void MainWindow::on_verticalSliderOutPutScreen_sliderPressed()
{
   ui->OutPutScreen->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}

void MainWindow::on_verticalSliderOutPutScreen_sliderMoved(int position)
{
//     ui->OutPutScreen->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
//     const qreal factor = 1.01;
//     qreal viewScaleValue = qPow(factor, position);//-position to invert the scale
//     QMatrix matrix;
//     matrix.scale(viewScaleValue, viewScaleValue);
//     ui->OutPutScreen->setMatrix(matrix);
}

void MainWindow::on_verticalSliderOutPutScreen_valueChanged(int value)
{
      ui->OutPutScreen->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
      //ui->OutPutScreen->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
      double scaleFactor;
      scaleFactor = pow(1.1,((value - 100) / 100.0));
      ui->OutPutScreen->scale(scaleFactor,scaleFactor);
}

void MainWindow::on_verticalSliderInputScreen1_sliderMoved(int position)
{
    ui->InputScreen_1->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
    const qreal factor = 1.01;
    qreal viewScaleValue = qPow(factor, position);//-position to invert the scale
    QMatrix matrix;
    matrix.scale(viewScaleValue, viewScaleValue);
    ui->InputScreen_1->setMatrix(matrix);

}

void MainWindow::on_verticalSliderInputScreen1_valueChanged(int value)
{
//    ui->InputScreen_1->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
//    //double scale = pow(5.0, (ui->verticalSliderInputScreen1->value() / 4000.0));
//    // Scale the view / do the zoom
//    double scaleFactor = 1.15;
//    QMatrix matrix;
//    if(value > 0) {
//        // Zoom in
//     matrix.scale(scaleFactor, scaleFactor);

//    } else {
//        // Zooming out
//      matrix.scale(1.0 / scaleFactor, 1.0 / scaleFactor);
//    }


//    float z ;
//    if(value==0 )
//        z=0.1;
//    else
//        z  = value*0.01;

//    scene->update();
//    ui->InputScreen_1->transform();
//    double m_current_scale;
//    const double scale_inverse = 1.0 / (double)m_current_scale;
//    ui->InputScreen_1->scale(scale_inverse, scale_inverse);
//    m_current_scale = z;

//    ui->InputScreen_1->scale(z,z);
}


void MainWindow::wheelEvent ( QWheelEvent * e)
{
    if (e->modifiers().testFlag(Qt::ControlModifier)){ // zoom only when CTRL key pressed
        int numSteps = e->delta() / 15 / 8;

        if (numSteps == 0) {
            e->ignore();
            return;
        }
        qreal sc = pow(1.25, numSteps); // I use scale factor 1.25
        QGraphicsView * view = new QGraphicsView(this) ;
        view->setScene(scene);
        this->zoom(sc, view->mapToScene(e->pos()));
        e->accept();
    }
}

void MainWindow::zoom(qreal factor, QPointF centerPoint)
{
    QMatrix matrix;
    matrix.scale(factor, factor);
    //centerOn(centerPoint);
}


void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::MiddleButton)
    {
        // Store original position.
        m_originX = event->x();
        m_originY = event->y();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
//    QGraphicsView * view = new QGraphicsView(this) ;
//    view->setScene(scene);
//    if (event->buttons() & Qt::MidButton)
//    {

//        double m_originX = this->pos().x();
//        double m_originY = this->pos().y();
//        QPointF oldp = mapToScene(m_originX, m_originY);
//        QPointF newP = mapToScene(event->pos());
//        QPointF translation = newp - oldp;

//        translate(translation.x(), translation.y());

//        m_originX = event->x();
//        m_originY = event->y();
//    }
}

void MainWindow::fitToWindow()
{
    int x;
//    bool fitToWindow = ui->actionzoomIn->isChecked();
//    scrollArea->setWidgetResizable(fitToWindow);
//    if (!ui->actionzoomIn)
//    {
//       ui->InputScreen_1->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
//    }
  updateActions();
}

void MainWindow::updateActions()
{
    ui->InputScreen_1->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}

void MainWindow::on_actionInputImageFitWindow_triggered()
{
//    if((ui->InputScreen_1->setScene(scene)))
//    {
//     ui->InputScreen_1->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
//    }
//    else
//        return;
}

void MainWindow::on_actionOutputImageFitWindow_triggered()
{
    ui->OutPutScreen->fitInView(scene->sceneRect(),Qt::KeepAspectRatio);
}
