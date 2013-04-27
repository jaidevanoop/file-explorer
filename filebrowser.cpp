#include "filebrowser.h"
#include "ui_filebrowser.h"

/**
 * @brief The NoFocusDelegate class
 * @ref http://stackoverflow.com/questions/2055705/hide-the-border-of-the-selected-cell-in-qtablewidget-in-pyqt
 */
class NoFocusDelegate : public QStyledItemDelegate
{
protected:
    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
};

void NoFocusDelegate::paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex &index) const
{
    QStyleOptionViewItem itemOption(option);
    if (itemOption.state & QStyle::State_HasFocus)
        itemOption.state = itemOption.state ^ QStyle::State_HasFocus;
    QStyledItemDelegate::paint(painter, itemOption, index);
}

FileBrowser::FileBrowser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileBrowser)
{
    ui->setupUi(this);

    // Directory (list view)
    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);  // shows only directories
    ui->listView->setModel(dirModel);
    ui->listView->setRootIndex(dirModel->setRootPath(""));

    // Folder/File (table view)
    completer = new QCompleter(this);
    fileModel = new QFileSystemModel(completer);
    ui->tableView->setModel(fileModel);
    ui->tableView->setItemDelegate(new NoFocusDelegate());  // hides selection focus border
    ui->tableView->setRootIndex(fileModel->setRootPath(QDir::homePath()));
    completer->setModel(fileModel);

    // Address bar
    lineEdit = new QLineEdit(fileModel->rootPath());
    ui->mainToolBar->addWidget(lineEdit);
    lineEdit->setCompleter(completer);
    connect(lineEdit, SIGNAL(returnPressed()), SLOT(onlineEdit_returnPressed()));

    // Splitter stretch
    ui->splitter->setStretchFactor(0, 1);
    ui->splitter->setStretchFactor(1, 4);
}

FileBrowser::~FileBrowser()
{
    delete ui;
}

// ====================== VIEW FUNCTIONS ======================
void FileBrowser::on_listView_doubleClicked(const QModelIndex &index)
{
    QString path = dirModel->fileInfo(index).absoluteFilePath();
    dirModel->setRootPath(path);
    update_tableView(path);
}

void FileBrowser::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString path = fileModel->fileInfo(index).absoluteFilePath();
    if(!fileModel->fileInfo(index).isFile())
    {
        fileModel->setRootPath(path);
        update_tableView(fileModel->rootPath());
    }
    else
    {
        if(QDesktopServices::openUrl(QUrl::fromLocalFile(path)))
            ui->statusBar->showMessage("File open success", 2000);
        else
            ui->statusBar->showMessage("File open failed", 2000);
    }
}

// ====================== COMMAND FUNCTIONS ======================
void FileBrowser::on_actionCd_triggered()
{
    ui->commandEdit->setText("cd (change directory)");
    enableParamFields(1);
}

void FileBrowser::on_actionMkdir_triggered()
{
    ui->commandEdit->setText("mkdir (make directory)");
    enableParamFields(1);
}

void FileBrowser::on_actionRmdir_triggered()
{
    ui->commandEdit->setText("rmdir (remove directory)");
    enableParamFields(1);
}

void FileBrowser::on_actionCp_triggered()
{
    ui->commandEdit->setText("cp (copy file)");
    enableParamFields(2);
}

void FileBrowser::on_actionMv_triggered()
{
    ui->commandEdit->setText("mv (move file)");
    enableParamFields(2);
}

void FileBrowser::on_actionRm_triggered()
{
    ui->commandEdit->setText("rm (remove file)");
    enableParamFields(1);
}

void FileBrowser::on_actionPwd_triggered()
{
    ui->statusBar->showMessage(fileModel->rootPath(), 3000);
}

void FileBrowser::on_param1Edit_returnPressed()
{
    QString cmd = ui->commandEdit->text();

    if(cmd.contains("cd"))
    {
        QDir tmpDir = fileModel->rootDirectory();
        bool valid = tmpDir.cd(ui->param1Edit->text());
        QString path = tmpDir.path();
        if(valid) {
            update_tableView(path);
            ui->statusBar->showMessage("cd: change directory success", 3000);
        }
        else
            ui->statusBar->showMessage("cd: change directory failed - directory does not exist", 3000);
    }
    else if(cmd.contains("mkdir"))
    {
        if(fileModel->rootDirectory().mkdir(ui->param1Edit->text())) {
            update_tableView(fileModel->rootPath());
            ui->statusBar->showMessage("mkdir: make directory success", 3000);
        }
        else
            ui->statusBar->showMessage("mkdir: make directory failed - directory already exists", 3000);
    }
    else if(cmd.contains("rmdir"))
    {
        if(fileModel->rootDirectory().rmdir(ui->param1Edit->text())) {
            update_tableView(fileModel->rootPath());
            ui->statusBar->showMessage("rmdir: remove directory success", 3000);
        }
        else
            ui->statusBar->showMessage("rmdir: remove directory failed - directory must be empty and exist", 3000);
    }
    else if(cmd.contains("cp"))
        copyFile();
    else if(cmd.contains("mv"))
        moveFile();
    else if(cmd.contains("rm"))
    {
        if(QFile::remove(fileModel->rootPath()+"/"+ui->param1Edit->text()))
        {
            update_tableView(fileModel->rootPath());
            ui->statusBar->showMessage("rm: remove file success", 3000);
        }
        else
            ui->statusBar->showMessage("rm: remove file failed - file does not exist", 3000);
    }

    clearParamFields();
}

void FileBrowser::on_param2Edit_returnPressed()
{
    QString cmd = ui->commandEdit->text();
    if(cmd.contains("cp"))
        copyFile();
    else if(cmd.contains("mv"))
        moveFile();
    clearParamFields();
}

void FileBrowser::copyFile()
{
    if(QFile::copy(fileModel->rootPath()+"/"+ui->param1Edit->text(),
                fileModel->rootPath()+"/"+ui->param2Edit->text()))
    {
        update_tableView(fileModel->rootPath());
        ui->statusBar->showMessage("cp: copy file success", 3000);
    }
    else
        ui->statusBar->showMessage("cp: copy file failed - filename may not exist or newname already exists", 3000);
}

void FileBrowser::moveFile()
{
    if(QFile::rename(fileModel->rootPath()+"/"+ui->param1Edit->text(),
                fileModel->rootPath()+"/"+ui->param2Edit->text()))
    {
        update_tableView(fileModel->rootPath());
        ui->statusBar->showMessage("mv: move file success", 3000);
    }
    else
        ui->statusBar->showMessage("mv: move file failed - filename may not exist or newname already exists", 3000);
}

// ====================== ADDRESS BAR FUNCTIONS ======================
void FileBrowser::on_actionBack_triggered()
{
    QDir tmpDir = fileModel->rootDirectory();
    tmpDir.cdUp();
    QString path = tmpDir.path();
    update_tableView(path);
}

void FileBrowser::on_actionHome_triggered()
{
    QString path = fileModel->rootDirectory().homePath();
    fileModel->setRootPath(path);
    update_tableView(path);
}

/**
 * @brief FileBrowser::on_actionRefresh_triggered
 * This function is not really needed since the browser auto-refreshes when there is a change.
 * Additional feature to clear the command line fields.
 */
void FileBrowser::on_actionRefresh_triggered()
{
    ui->commandEdit->clear();
    clearParamFields();
    enableParamFields(0);
    dirModel->rootDirectory().refresh();
    fileModel->rootDirectory().refresh();
    update_tableView(fileModel->rootPath());
}

void FileBrowser::onlineEdit_returnPressed()
{
    QDir tmpDir = fileModel->rootDirectory();
    bool valid = tmpDir.cd(lineEdit->text());
    QString path = tmpDir.path();
    if(valid)
        update_tableView(path);
}

// ====================== HELPER FUNCTIONS ======================
void FileBrowser::update_tableView(QString path)
{
    ui->tableView->setRootIndex(fileModel->setRootPath(path));
    lineEdit->setText(path);
}

void FileBrowser::enableParamFields(int args)
{
    switch(args)
    {
        case 1:
            ui->param1Edit->setEnabled(true);
            ui->param2Edit->setEnabled(false);
            ui->param1Edit->setFocus();
            break;
        case 2:
            ui->param1Edit->setEnabled(true);
            ui->param2Edit->setEnabled(true);
            ui->param1Edit->setFocus();
            break;
        default:
            ui->param1Edit->setEnabled(false);
            ui->param2Edit->setEnabled(false);
    }

    // if param1 field is empty, we know param2 field is empty too
    if(!ui->param1Edit->isEnabled())
        clearParamFields();
    else if(!ui->param2Edit->isEnabled())
        ui->param2Edit->clear();
}

void FileBrowser::clearParamFields()
{
    ui->param1Edit->clear();
    ui->param2Edit->clear();
}

// ====================== MENU FUNCTIONS ======================
void FileBrowser::on_actionClose_triggered()
{
    exit(0);
}
