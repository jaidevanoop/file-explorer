#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QString>
#include <QLineEdit>
#include <QStyledItemDelegate>
#include <QDir>
#include <QDesktopServices>
#include <QUrl>
#include <QFile>
#include <QCompleter>
#include <QMainWindow>
#include <QEvent>

namespace Ui {
class FileBrowser;
}

class FileBrowser : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FileBrowser(QWidget *parent = 0);
    void update_tableView(QString);
    void update_views(QString);
    void enableParamFields(int);
    void clearParamFields();
    void copyFile();
    void moveFile();
    ~FileBrowser();
    
private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_actionCd_triggered();
    void on_actionBack_triggered();
    void on_actionHome_triggered();
    void on_actionRefresh_triggered();
    void on_listView_doubleClicked(const QModelIndex &index);
    void on_actionMkdir_triggered();
    void on_actionRmdir_triggered();
    void on_actionCp_triggered();
    void on_actionMv_triggered();
    void on_actionRm_triggered();
    void on_param1Edit_returnPressed();
    void on_param2Edit_returnPressed();
    void on_actionClose_triggered();
    void onlineEdit_returnPressed();

    void on_actionPwd_triggered();

private:
    Ui::FileBrowser *ui;
    QFileSystemModel *dirModel;     // directory model
    QFileSystemModel *fileModel;    // file model
    QLineEdit *lineEdit;
    QCompleter *completer;
};

#endif // FILEBROWSER_H
