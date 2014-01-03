/********************************************************************************
** Form generated from reading UI file 'filebrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEBROWSER_H
#define UI_FILEBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileBrowser
{
public:
    QAction *actionNew_folder;
    QAction *actionMove_to;
    QAction *actionCopy_to;
    QAction *actionDelete;
    QAction *actionRename;
    QAction *actionBack;
    QAction *actionForward;
    QAction *actionCd;
    QAction *actionMkdir;
    QAction *actionRmdir;
    QAction *actionRefresh;
    QAction *actionHome;
    QAction *actionCp;
    QAction *actionMv;
    QAction *actionAbout;
    QAction *actionClose_current_tabs;
    QAction *actionRm;
    QAction *actionClose;
    QAction *actionManual;
    QAction *actionPwd;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *commandEdit;
    QLineEdit *param1Edit;
    QLineEdit *param2Edit;
    QSplitter *splitter;
    QListView *listView;
    QTableView *tableView;
    QToolBar *mainToolBar;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuHome;
    QMenu *menuCommands;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FileBrowser)
    {
        if (FileBrowser->objectName().isEmpty())
            FileBrowser->setObjectName(QStringLiteral("FileBrowser"));
        FileBrowser->resize(580, 344);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../Downloads/Explorer.ico"), QSize(), QIcon::Normal, QIcon::Off);
        FileBrowser->setWindowIcon(icon);
        actionNew_folder = new QAction(FileBrowser);
        actionNew_folder->setObjectName(QStringLiteral("actionNew_folder"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../Downloads/Folder-Add (1).ico"), QSize(), QIcon::Normal, QIcon::Off);
        icon1.addFile(QStringLiteral("../../../Downloads/Folder-Add-32.png"), QSize(), QIcon::Normal, QIcon::On);
        actionNew_folder->setIcon(icon1);
        actionMove_to = new QAction(FileBrowser);
        actionMove_to->setObjectName(QStringLiteral("actionMove_to"));
        actionCopy_to = new QAction(FileBrowser);
        actionCopy_to->setObjectName(QStringLiteral("actionCopy_to"));
        actionDelete = new QAction(FileBrowser);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../Downloads/Close.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon2);
        actionRename = new QAction(FileBrowser);
        actionRename->setObjectName(QStringLiteral("actionRename"));
        actionBack = new QAction(FileBrowser);
        actionBack->setObjectName(QStringLiteral("actionBack"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../Downloads/Google Chrome/gfx/9002.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBack->setIcon(icon3);
        actionForward = new QAction(FileBrowser);
        actionForward->setObjectName(QStringLiteral("actionForward"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../../../Downloads/Google Chrome/gfx/9023.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionForward->setIcon(icon4);
        actionCd = new QAction(FileBrowser);
        actionCd->setObjectName(QStringLiteral("actionCd"));
        actionMkdir = new QAction(FileBrowser);
        actionMkdir->setObjectName(QStringLiteral("actionMkdir"));
        actionRmdir = new QAction(FileBrowser);
        actionRmdir->setObjectName(QStringLiteral("actionRmdir"));
        actionRefresh = new QAction(FileBrowser);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../../../Downloads/Google Chrome/gfx/9044.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon5);
        actionHome = new QAction(FileBrowser);
        actionHome->setObjectName(QStringLiteral("actionHome"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("../../../Downloads/Google Chrome/gfx/9359.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHome->setIcon(icon6);
        actionCp = new QAction(FileBrowser);
        actionCp->setObjectName(QStringLiteral("actionCp"));
        actionMv = new QAction(FileBrowser);
        actionMv->setObjectName(QStringLiteral("actionMv"));
        actionAbout = new QAction(FileBrowser);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionClose_current_tabs = new QAction(FileBrowser);
        actionClose_current_tabs->setObjectName(QStringLiteral("actionClose_current_tabs"));
        actionRm = new QAction(FileBrowser);
        actionRm->setObjectName(QStringLiteral("actionRm"));
        actionClose = new QAction(FileBrowser);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionManual = new QAction(FileBrowser);
        actionManual->setObjectName(QStringLiteral("actionManual"));
        actionPwd = new QAction(FileBrowser);
        actionPwd->setObjectName(QStringLiteral("actionPwd"));
        centralWidget = new QWidget(FileBrowser);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        commandEdit = new QLineEdit(centralWidget);
        commandEdit->setObjectName(QStringLiteral("commandEdit"));
        commandEdit->setEnabled(false);

        horizontalLayout->addWidget(commandEdit);

        param1Edit = new QLineEdit(centralWidget);
        param1Edit->setObjectName(QStringLiteral("param1Edit"));
        param1Edit->setEnabled(false);

        horizontalLayout->addWidget(param1Edit);

        param2Edit = new QLineEdit(centralWidget);
        param2Edit->setObjectName(QStringLiteral("param2Edit"));
        param2Edit->setEnabled(false);

        horizontalLayout->addWidget(param2Edit);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setChildrenCollapsible(false);
        listView = new QListView(splitter);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setFrameShape(QFrame::StyledPanel);
        splitter->addWidget(listView);
        tableView = new QTableView(splitter);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setShowGrid(false);
        tableView->setSortingEnabled(true);
        tableView->setWordWrap(false);
        tableView->setCornerButtonEnabled(false);
        splitter->addWidget(tableView);
        tableView->horizontalHeader()->setCascadingSectionResizes(true);
        tableView->horizontalHeader()->setHighlightSections(false);
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setHighlightSections(false);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        FileBrowser->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(FileBrowser);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setAcceptDrops(false);
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::BottomToolBarArea|Qt::TopToolBarArea);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        mainToolBar->setFloatable(true);
        FileBrowser->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar = new QToolBar(FileBrowser);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setAllowedAreas(Qt::AllToolBarAreas);
        FileBrowser->addToolBar(Qt::TopToolBarArea, toolBar);
        FileBrowser->insertToolBarBreak(toolBar);
        menuBar = new QMenuBar(FileBrowser);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 580, 21));
        menuHome = new QMenu(menuBar);
        menuHome->setObjectName(QStringLiteral("menuHome"));
        menuCommands = new QMenu(menuBar);
        menuCommands->setObjectName(QStringLiteral("menuCommands"));
        FileBrowser->setMenuBar(menuBar);
        statusBar = new QStatusBar(FileBrowser);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FileBrowser->setStatusBar(statusBar);

        mainToolBar->addAction(actionBack);
        mainToolBar->addAction(actionRefresh);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionHome);
        toolBar->addAction(actionCd);
        toolBar->addAction(actionMkdir);
        toolBar->addAction(actionRmdir);
        toolBar->addSeparator();
        toolBar->addAction(actionCp);
        toolBar->addAction(actionMv);
        toolBar->addAction(actionRm);
        toolBar->addSeparator();
        toolBar->addAction(actionPwd);
        menuBar->addAction(menuHome->menuAction());
        menuBar->addAction(menuCommands->menuAction());
        menuHome->addAction(actionRefresh);
        menuHome->addSeparator();
        menuHome->addAction(actionClose);
        menuCommands->addAction(actionCd);
        menuCommands->addAction(actionMkdir);
        menuCommands->addAction(actionRmdir);
        menuCommands->addSeparator();
        menuCommands->addAction(actionCp);
        menuCommands->addAction(actionMv);
        menuCommands->addAction(actionRm);
        menuCommands->addSeparator();
        menuCommands->addAction(actionPwd);

        retranslateUi(FileBrowser);

        QMetaObject::connectSlotsByName(FileBrowser);
    } // setupUi

    void retranslateUi(QMainWindow *FileBrowser)
    {
        FileBrowser->setWindowTitle(QApplication::translate("FileBrowser", "Linux File Explorer", 0));
        actionNew_folder->setText(QApplication::translate("FileBrowser", "New folder", 0));
        actionMove_to->setText(QApplication::translate("FileBrowser", "Move to...", 0));
        actionCopy_to->setText(QApplication::translate("FileBrowser", "Copy to...", 0));
        actionDelete->setText(QApplication::translate("FileBrowser", "Delete", 0));
        actionRename->setText(QApplication::translate("FileBrowser", "Rename", 0));
        actionBack->setText(QApplication::translate("FileBrowser", "Back", 0));
        actionForward->setText(QApplication::translate("FileBrowser", "Forward", 0));
        actionCd->setText(QApplication::translate("FileBrowser", "cd", 0));
#ifndef QT_NO_TOOLTIP
        actionCd->setToolTip(QApplication::translate("FileBrowser", "<html><head/><body><p><span style=\" font-weight:600;\">change directory</span><br/>cd <span style=\" font-style:italic;\">dirname</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionCd->setShortcut(QApplication::translate("FileBrowser", "Alt+1", 0));
        actionMkdir->setText(QApplication::translate("FileBrowser", "mkdir", 0));
#ifndef QT_NO_TOOLTIP
        actionMkdir->setToolTip(QApplication::translate("FileBrowser", "<html><head/><body><span style=\" font-weight:600;\">make directory</span><br>mkdir <span style=\" font-style:italic;\">dirname</span></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionMkdir->setShortcut(QApplication::translate("FileBrowser", "Alt+2", 0));
        actionRmdir->setText(QApplication::translate("FileBrowser", "rmdir", 0));
#ifndef QT_NO_TOOLTIP
        actionRmdir->setToolTip(QApplication::translate("FileBrowser", "<html><head/><body><span style=\" font-weight:600;\">remove directory</span><br>rmdir <span style=\" font-style:italic;\">dirname</span></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionRmdir->setShortcut(QApplication::translate("FileBrowser", "Alt+3", 0));
        actionRefresh->setText(QApplication::translate("FileBrowser", "Refresh", 0));
#ifndef QT_NO_TOOLTIP
        actionRefresh->setToolTip(QApplication::translate("FileBrowser", "Refresh", 0));
#endif // QT_NO_TOOLTIP
        actionRefresh->setShortcut(QApplication::translate("FileBrowser", "F5", 0));
        actionHome->setText(QApplication::translate("FileBrowser", "Home", 0));
#ifndef QT_NO_TOOLTIP
        actionHome->setToolTip(QApplication::translate("FileBrowser", "Home", 0));
#endif // QT_NO_TOOLTIP
        actionCp->setText(QApplication::translate("FileBrowser", "cp", 0));
#ifndef QT_NO_TOOLTIP
        actionCp->setToolTip(QApplication::translate("FileBrowser", "<html><head/><body><span style=\" font-weight:600;\">copy file</span><br>cp <span style=\" font-style:italic;\">filename1 filename2</span></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionCp->setShortcut(QApplication::translate("FileBrowser", "Alt+4", 0));
        actionMv->setText(QApplication::translate("FileBrowser", "mv", 0));
#ifndef QT_NO_TOOLTIP
        actionMv->setToolTip(QApplication::translate("FileBrowser", "<html><head/><body><span style=\" font-weight:600;\">move file</span><br>mv <span style=\" font-style:italic;\">filename1 filename2</span></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionMv->setShortcut(QApplication::translate("FileBrowser", "Alt+5", 0));
        actionAbout->setText(QApplication::translate("FileBrowser", "About", 0));
        actionClose_current_tabs->setText(QApplication::translate("FileBrowser", "Save tabs", 0));
        actionRm->setText(QApplication::translate("FileBrowser", "rm", 0));
#ifndef QT_NO_TOOLTIP
        actionRm->setToolTip(QApplication::translate("FileBrowser", "<html><head/><body><span style=\" font-weight:600;\">remove file</span><br>rm <span style=\" font-style:italic;\">filename</span></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionRm->setShortcut(QApplication::translate("FileBrowser", "Alt+6", 0));
        actionClose->setText(QApplication::translate("FileBrowser", "Close", 0));
        actionManual->setText(QApplication::translate("FileBrowser", "Manual", 0));
        actionPwd->setText(QApplication::translate("FileBrowser", "pwd", 0));
#ifndef QT_NO_TOOLTIP
        actionPwd->setToolTip(QApplication::translate("FileBrowser", "<html><head/><body><p><span style=\" font-weight:600;\">print working directory</span></p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        actionPwd->setShortcut(QApplication::translate("FileBrowser", "Alt+7", 0));
#ifndef QT_NO_WHATSTHIS
        param1Edit->setWhatsThis(QApplication::translate("FileBrowser", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        mainToolBar->setWindowTitle(QApplication::translate("FileBrowser", "Address bar", 0));
        toolBar->setWindowTitle(QApplication::translate("FileBrowser", "Command bar", 0));
        menuHome->setTitle(QApplication::translate("FileBrowser", "Home", 0));
        menuCommands->setTitle(QApplication::translate("FileBrowser", "Commands", 0));
    } // retranslateUi

};

namespace Ui {
    class FileBrowser: public Ui_FileBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEBROWSER_H
