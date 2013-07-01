#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QProcess>
#include <QDebug>

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
    _dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     ".",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);

    //_dir = "../GamePlay";

    showLog();

}

void MainWindow::showLog()
{

    QProcess log;
    log.setWorkingDirectory( _dir );
    qDebug() << "working dir:" << log.workingDirectory();
    //TODO ограничение в 10 коммитов!
    log.start("git", QStringList() << "log" << "--oneline" << "--abbrev-commit" << "--all" << "--decorate=full" << /*"-n 10" <<*/ "--children" );
    if (!log.waitForStarted()) return;

    //log.write("Qt rocks!");
    log.closeWriteChannel();

    if (!log.waitForFinished()) return;

    QByteArray result = log.readAll();

    ui->textEdit->setText( result );

}
