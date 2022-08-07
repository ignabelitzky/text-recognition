#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QApplication>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTextEdit>
#include <QStatusBar>
#include <QLabel>
#include <QSplitter>
#include <QShortcut>
#include <QKeySequence>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QGraphicsPixmapItem>
#include "tesseract/baseapi.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUI();
    void createActions();
    void setupShortcuts();
    void showImage(QString);

private:
    QMenu *fileMenu;
    QMenu *helpMenu;

    QToolBar *fileToolBar;

    QGraphicsScene *imageScene;
    QGraphicsView *imageView;

    QTextEdit *editor;

    QStatusBar *mainStatusBar;
    QLabel *mainStatusLabel;

    QAction *openAction;
    QAction *saveImageAsAction;
    QAction *saveTextAsAction;
    QAction *exitAction;
    QAction *ocrAction;

    QString currentImagePath;
    QGraphicsPixmapItem *currentImage;

    tesseract::TessBaseAPI *tesseractAPI;

private slots:
    void openImage();
    void saveImageAs();
    void saveTextAs();
    void extractText();
};

#endif
