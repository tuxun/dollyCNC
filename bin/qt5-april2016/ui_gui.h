/********************************************************************************
** Form generated from reading UI file 'gui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_H
#define UI_GUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gui
{
public:
    QAction *actionQuitter;
    QAction *actionV_rifier_mahine;
    QAction *actionInfo;
    QAction *actionManuel;
    QAction *actionDebug;
    QAction *actionNouvelle;
    QAction *actionConnecter;
    QAction *actionLibrary_path;
    QAction *actionLittle_height_1024px;
    QAction *actionNormal_15_fullscreen_test;
    QAction *actionAutodetect;
    QAction *actionImport;
    QAction *actionToggle_Library;
    QWidget *centralWidget;
    QTabWidget *verticalTabWidget;
    QWidget *tab_2;
    QTabWidget *dessin;
    QWidget *gridTabWidget_2Page1;
    QGridLayout *gridLayout_3;
    QPushButton *testmoveButton;
    QGraphicsView *graphicsView;
    QWidget *tab_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QWidget *tab_3;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QTreeWidget *browserWidget;
    QWidget *widget;
    QPushButton *pushButton_2;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *label_3;
    QTextEdit *gcodesendText;
    QPushButton *getstatutButton;
    QComboBox *deviceMenu;
    QTextBrowser *textBrowser;
    QPushButton *initButton;
    QLabel *dri_statelabel;
    QLabel *dev_filelabel;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *gcodesendButton;
    QPushButton *pushButton;
    QPushButton *drawtocodeButton;
    QWidget *verticalTabWidgetPage1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *moinschaudButton;
    QProgressBar *tempbare;
    QPushButton *pluschaudButton;
    QGridLayout *gridLayout;
    QPushButton *bgButton;
    QPushButton *hButton;
    QPushButton *bButton;
    QPushButton *hgButton;
    QPushButton *hdButton;
    QPushButton *bdButton;
    QPushButton *gButton;
    QPushButton *dButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *runstopbutton;
    QLabel *movewaylabel;
    QMenuBar *menuBar;
    QMenu *menuM;
    QMenu *menuStatut;
    QMenu *menuAide;
    QMenu *menuSettings;
    QMenu *menuScreen_size;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *gui)
    {
        if (gui->objectName().isEmpty())
            gui->setObjectName(QStringLiteral("gui"));
        gui->setWindowModality(Qt::NonModal);
        gui->resize(640, 559);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gui->sizePolicy().hasHeightForWidth());
        gui->setSizePolicy(sizePolicy);
        gui->setDockNestingEnabled(true);
        gui->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::VerticalTabs);
        actionQuitter = new QAction(gui);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionV_rifier_mahine = new QAction(gui);
        actionV_rifier_mahine->setObjectName(QStringLiteral("actionV_rifier_mahine"));
        actionInfo = new QAction(gui);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionManuel = new QAction(gui);
        actionManuel->setObjectName(QStringLiteral("actionManuel"));
        actionDebug = new QAction(gui);
        actionDebug->setObjectName(QStringLiteral("actionDebug"));
        actionNouvelle = new QAction(gui);
        actionNouvelle->setObjectName(QStringLiteral("actionNouvelle"));
        actionConnecter = new QAction(gui);
        actionConnecter->setObjectName(QStringLiteral("actionConnecter"));
        actionLibrary_path = new QAction(gui);
        actionLibrary_path->setObjectName(QStringLiteral("actionLibrary_path"));
        actionLittle_height_1024px = new QAction(gui);
        actionLittle_height_1024px->setObjectName(QStringLiteral("actionLittle_height_1024px"));
        actionNormal_15_fullscreen_test = new QAction(gui);
        actionNormal_15_fullscreen_test->setObjectName(QStringLiteral("actionNormal_15_fullscreen_test"));
        actionAutodetect = new QAction(gui);
        actionAutodetect->setObjectName(QStringLiteral("actionAutodetect"));
        actionImport = new QAction(gui);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionToggle_Library = new QAction(gui);
        actionToggle_Library->setObjectName(QStringLiteral("actionToggle_Library"));
        centralWidget = new QWidget(gui);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalTabWidget = new QTabWidget(centralWidget);
        verticalTabWidget->setObjectName(QStringLiteral("verticalTabWidget"));
        verticalTabWidget->setGeometry(QRect(0, 0, 641, 511));
        sizePolicy.setHeightForWidth(verticalTabWidget->sizePolicy().hasHeightForWidth());
        verticalTabWidget->setSizePolicy(sizePolicy);
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        dessin = new QTabWidget(tab_2);
        dessin->setObjectName(QStringLiteral("dessin"));
        dessin->setGeometry(QRect(29, 9, 591, 461));
        dessin->setMinimumSize(QSize(400, 400));
        dessin->setAcceptDrops(true);
        dessin->setTabsClosable(true);
        gridTabWidget_2Page1 = new QWidget();
        gridTabWidget_2Page1->setObjectName(QStringLiteral("gridTabWidget_2Page1"));
        gridLayout_3 = new QGridLayout(gridTabWidget_2Page1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        testmoveButton = new QPushButton(gridTabWidget_2Page1);
        testmoveButton->setObjectName(QStringLiteral("testmoveButton"));

        gridLayout_3->addWidget(testmoveButton, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(gridTabWidget_2Page1);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_3->addWidget(graphicsView, 1, 0, 1, 1);

        dessin->addTab(gridTabWidget_2Page1, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        layoutWidget = new QWidget(tab_4);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 479, 26));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        doubleSpinBox_2 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(1);
        doubleSpinBox_2->setMinimum(0.5);
        doubleSpinBox_2->setSingleStep(0.1);

        horizontalLayout_3->addWidget(doubleSpinBox_2);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        doubleSpinBox = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(0.5);
        doubleSpinBox->setSingleStep(0.1);

        horizontalLayout_3->addWidget(doubleSpinBox);

        dessin->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayoutWidget_2 = new QWidget(tab_3);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(9, 10, 481, 200));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        browserWidget = new QTreeWidget(gridLayoutWidget_2);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        browserWidget->setHeaderItem(__qtreewidgetitem);
        browserWidget->setObjectName(QStringLiteral("browserWidget"));

        gridLayout_4->addWidget(browserWidget, 5, 0, 1, 1);

        widget = new QWidget(gridLayoutWidget_2);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout_4->addWidget(widget, 6, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_4->addWidget(pushButton_2, 4, 0, 1, 1);

        dessin->addTab(tab_3, QString());
        verticalTabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 521, 463));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        gcodesendText = new QTextEdit(gridLayoutWidget);
        gcodesendText->setObjectName(QStringLiteral("gcodesendText"));

        gridLayout_2->addWidget(gcodesendText, 3, 1, 1, 1);

        getstatutButton = new QPushButton(gridLayoutWidget);
        getstatutButton->setObjectName(QStringLiteral("getstatutButton"));

        gridLayout_2->addWidget(getstatutButton, 9, 0, 1, 1);

        deviceMenu = new QComboBox(gridLayoutWidget);
        deviceMenu->setObjectName(QStringLiteral("deviceMenu"));

        gridLayout_2->addWidget(deviceMenu, 2, 1, 1, 1);

        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        gridLayout_2->addWidget(textBrowser, 9, 1, 1, 1);

        initButton = new QPushButton(gridLayoutWidget);
        initButton->setObjectName(QStringLiteral("initButton"));

        gridLayout_2->addWidget(initButton, 2, 0, 1, 1);

        dri_statelabel = new QLabel(gridLayoutWidget);
        dri_statelabel->setObjectName(QStringLiteral("dri_statelabel"));

        gridLayout_2->addWidget(dri_statelabel, 0, 1, 1, 1);

        dev_filelabel = new QLabel(gridLayoutWidget);
        dev_filelabel->setObjectName(QStringLiteral("dev_filelabel"));

        gridLayout_2->addWidget(dev_filelabel, 1, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        gcodesendButton = new QPushButton(gridLayoutWidget);
        gcodesendButton->setObjectName(QStringLiteral("gcodesendButton"));

        verticalLayout_2->addWidget(gcodesendButton);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        drawtocodeButton = new QPushButton(gridLayoutWidget);
        drawtocodeButton->setObjectName(QStringLiteral("drawtocodeButton"));

        verticalLayout_2->addWidget(drawtocodeButton);


        gridLayout_2->addLayout(verticalLayout_2, 3, 0, 1, 1);

        verticalTabWidget->addTab(tab, QString());
        verticalTabWidgetPage1 = new QWidget();
        verticalTabWidgetPage1->setObjectName(QStringLiteral("verticalTabWidgetPage1"));
        verticalLayout = new QVBoxLayout(verticalTabWidgetPage1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        moinschaudButton = new QPushButton(verticalTabWidgetPage1);
        moinschaudButton->setObjectName(QStringLiteral("moinschaudButton"));

        horizontalLayout_2->addWidget(moinschaudButton);

        tempbare = new QProgressBar(verticalTabWidgetPage1);
        tempbare->setObjectName(QStringLiteral("tempbare"));
        tempbare->setValue(24);

        horizontalLayout_2->addWidget(tempbare);

        pluschaudButton = new QPushButton(verticalTabWidgetPage1);
        pluschaudButton->setObjectName(QStringLiteral("pluschaudButton"));

        horizontalLayout_2->addWidget(pluschaudButton);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        bgButton = new QPushButton(verticalTabWidgetPage1);
        bgButton->setObjectName(QStringLiteral("bgButton"));

        gridLayout->addWidget(bgButton, 3, 0, 1, 1);

        hButton = new QPushButton(verticalTabWidgetPage1);
        hButton->setObjectName(QStringLiteral("hButton"));

        gridLayout->addWidget(hButton, 1, 1, 1, 1);

        bButton = new QPushButton(verticalTabWidgetPage1);
        bButton->setObjectName(QStringLiteral("bButton"));

        gridLayout->addWidget(bButton, 3, 1, 1, 1);

        hgButton = new QPushButton(verticalTabWidgetPage1);
        hgButton->setObjectName(QStringLiteral("hgButton"));

        gridLayout->addWidget(hgButton, 1, 0, 1, 1);

        hdButton = new QPushButton(verticalTabWidgetPage1);
        hdButton->setObjectName(QStringLiteral("hdButton"));

        gridLayout->addWidget(hdButton, 1, 2, 1, 1);

        bdButton = new QPushButton(verticalTabWidgetPage1);
        bdButton->setObjectName(QStringLiteral("bdButton"));

        gridLayout->addWidget(bdButton, 3, 2, 1, 1);

        gButton = new QPushButton(verticalTabWidgetPage1);
        gButton->setObjectName(QStringLiteral("gButton"));

        gridLayout->addWidget(gButton, 2, 0, 1, 1);

        dButton = new QPushButton(verticalTabWidgetPage1);
        dButton->setObjectName(QStringLiteral("dButton"));

        gridLayout->addWidget(dButton, 2, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        runstopbutton = new QPushButton(verticalTabWidgetPage1);
        runstopbutton->setObjectName(QStringLiteral("runstopbutton"));

        horizontalLayout->addWidget(runstopbutton);

        movewaylabel = new QLabel(verticalTabWidgetPage1);
        movewaylabel->setObjectName(QStringLiteral("movewaylabel"));

        horizontalLayout->addWidget(movewaylabel);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalTabWidget->addTab(verticalTabWidgetPage1, QString());
        gui->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(gui);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 20));
        menuM = new QMenu(menuBar);
        menuM->setObjectName(QStringLiteral("menuM"));
        menuStatut = new QMenu(menuBar);
        menuStatut->setObjectName(QStringLiteral("menuStatut"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menuScreen_size = new QMenu(menuSettings);
        menuScreen_size->setObjectName(QStringLiteral("menuScreen_size"));
        gui->setMenuBar(menuBar);
        mainToolBar = new QToolBar(gui);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        gui->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(gui);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        gui->setStatusBar(statusBar);

        menuBar->addAction(menuM->menuAction());
        menuBar->addAction(menuStatut->menuAction());
        menuBar->addAction(menuAide->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuM->addAction(actionImport);
        menuM->addAction(actionQuitter);
        menuStatut->addAction(actionV_rifier_mahine);
        menuStatut->addAction(actionNouvelle);
        menuStatut->addAction(actionConnecter);
        menuAide->addAction(actionInfo);
        menuAide->addAction(actionManuel);
        menuAide->addAction(actionDebug);
        menuSettings->addAction(actionLibrary_path);
        menuSettings->addAction(menuScreen_size->menuAction());
        menuSettings->addAction(actionToggle_Library);
        menuScreen_size->addAction(actionLittle_height_1024px);
        menuScreen_size->addAction(actionNormal_15_fullscreen_test);
        menuScreen_size->addAction(actionAutodetect);

        retranslateUi(gui);

        verticalTabWidget->setCurrentIndex(0);
        dessin->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(gui);
    } // setupUi

    void retranslateUi(QMainWindow *gui)
    {
        gui->setWindowTitle(QApplication::translate("gui", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("gui", "Quitter", 0));
        actionV_rifier_mahine->setText(QApplication::translate("gui", "V\303\251rifier machine", 0));
        actionInfo->setText(QApplication::translate("gui", "Info", 0));
        actionManuel->setText(QApplication::translate("gui", "Manuel", 0));
        actionDebug->setText(QApplication::translate("gui", "Debug", 0));
        actionNouvelle->setText(QApplication::translate("gui", "Nouvelle...", 0));
        actionConnecter->setText(QApplication::translate("gui", "Connecter...", 0));
        actionLibrary_path->setText(QApplication::translate("gui", "Library path...", 0));
        actionLittle_height_1024px->setText(QApplication::translate("gui", "Little(height<960px)", 0));
        actionNormal_15_fullscreen_test->setText(QApplication::translate("gui", "normal(15\" fullscreen test)", 0));
        actionAutodetect->setText(QApplication::translate("gui", "Autodetect", 0));
        actionImport->setText(QApplication::translate("gui", "Import", 0));
        actionToggle_Library->setText(QApplication::translate("gui", "Toggle Library", 0));
        testmoveButton->setText(QApplication::translate("gui", "Move 1 X", 0));
        dessin->setTabText(dessin->indexOf(gridTabWidget_2Page1), QString());
        label->setText(QApplication::translate("gui", "X", 0));
        label_2->setText(QApplication::translate("gui", "Y", 0));
        dessin->setTabText(dessin->indexOf(tab_4), QApplication::translate("gui", "Dessin", 0));
        pushButton_2->setText(QApplication::translate("gui", "Browse", 0));
        dessin->setTabText(dessin->indexOf(tab_3), QApplication::translate("gui", "Librairie", 0));
        verticalTabWidget->setTabText(verticalTabWidget->indexOf(tab_2), QApplication::translate("gui", "Fichier/Dessin", 0));
        label_4->setText(QApplication::translate("gui", "Driver file", 0));
        label_3->setText(QApplication::translate("gui", "Driver state", 0));
        getstatutButton->setText(QApplication::translate("gui", "Statut driver?", 0));
        deviceMenu->clear();
        deviceMenu->insertItems(0, QStringList()
         << QApplication::translate("gui", "/dev/minicut_virtmnc", 0)
         << QApplication::translate("gui", "/dev/ttyUSB0", 0)
         << QApplication::translate("gui", "/dev/parrot", 0)
         << QApplication::translate("gui", "/dev/hidraw0", 0)
        );
        initButton->setText(QApplication::translate("gui", "Connexion", 0));
        dri_statelabel->setText(QApplication::translate("gui", "inconnu", 0));
        dev_filelabel->setText(QApplication::translate("gui", "inconnu", 0));
        pushButton_3->setText(QApplication::translate("gui", "./GRBL.ngc", 0));
        gcodesendButton->setText(QApplication::translate("gui", "Envoyer", 0));
        pushButton->setText(QApplication::translate("gui", "Importer GRBL", 0));
        drawtocodeButton->setText(QApplication::translate("gui", "G\303\251n\303\251rer le code!", 0));
        verticalTabWidget->setTabText(verticalTabWidget->indexOf(tab), QApplication::translate("gui", "Driver/Code machine", 0));
        moinschaudButton->setText(QApplication::translate("gui", "MOINS chaud", 0));
        pluschaudButton->setText(QApplication::translate("gui", "PLUS chaud", 0));
        bgButton->setText(QApplication::translate("gui", "GAUCHE/BAS", 0));
        hButton->setText(QApplication::translate("gui", "HAUT", 0));
        bButton->setText(QApplication::translate("gui", "BAS", 0));
        hgButton->setText(QApplication::translate("gui", "GAUCHE/HAUT", 0));
        hdButton->setText(QApplication::translate("gui", "DROITE/HAUT", 0));
        bdButton->setText(QApplication::translate("gui", "DROITE/BAS", 0));
        gButton->setText(QApplication::translate("gui", "GAUCHE", 0));
        dButton->setText(QApplication::translate("gui", "DROITE", 0));
        runstopbutton->setText(QApplication::translate("gui", "Run/Stop", 0));
        movewaylabel->setText(QApplication::translate("gui", "ordre", 0));
        verticalTabWidget->setTabText(verticalTabWidget->indexOf(verticalTabWidgetPage1), QApplication::translate("gui", "Pilotage manuel", 0));
        menuM->setTitle(QApplication::translate("gui", "File", 0));
        menuStatut->setTitle(QApplication::translate("gui", "Machine", 0));
        menuAide->setTitle(QApplication::translate("gui", "Aide", 0));
        menuSettings->setTitle(QApplication::translate("gui", "Settings", 0));
        menuScreen_size->setTitle(QApplication::translate("gui", "Screen size", 0));
    } // retranslateUi

};

namespace Ui {
    class gui: public Ui_gui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_H
