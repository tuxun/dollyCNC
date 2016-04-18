#ifndef LIBMANAGER_H
#define LIBMANAGER_H

#include <QWidget>
#include <QToolButton>
#include <QMainWindow>
#include <QtGui>
#include <QtCore/QVariant>
#include  <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QGraphicsView>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QProgressBar>
#include <QPushButton>
#include <QStatusBar>
#include <QTabWidget>
#include <QTextBrowser>
#include <QTextEdit>
#include <QToolBar>
#include <QTreeWidget>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>
class Libmanager : public QWidget
{
    Q_OBJECT
public:
    explicit Libmanager(QWidget *parent = 0);
    QString get_path(void);

    void set_path(QString path);
    //pour n'afficher qu'un certain type
    void set_filter(QString *filter);
    QToolButton *vectorizeButton;
    QWidget *libwidget;
QTreeWidget *libTreeWidget;
  //void shit_Happen();
void refresh(void);
void closeEvent(QCloseEvent *event);

public slots:
void close(void);


private:
    QString *filter, path;
    QDir *model;

};

#endif // LIBMANAGER_H
