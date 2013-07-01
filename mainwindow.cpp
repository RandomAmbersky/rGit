#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}

void MainWindow::on_actionOpen_triggered()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     ".",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
}
