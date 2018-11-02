#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>


namespace Ui {
class MainWindow;

}
class SettingUi;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_FindFileTxt_textChanged(const QString &arg1);

    void on_close_clicked();
    void createFilesTable();
    void indexFile();
    void ReadSettSe();
    void WriteSettSe();
    void on_filesTable_cellDoubleClicked(int row, int column);
    void searchFile(QString str1,QString Filen);

     void Delete();
        void copy();
        void Property();
        void open();

    void contextMenuEvent(QContextMenuEvent *event);

    void on_filesTable_cellClicked(int row, int column);



    void on_SettingButton_clicked();

    void on_ChImages_clicked();

    void on_ChSource_clicked();

    void on_ChArchive_clicked();

    void on_ChMusic_clicked();

    void on_ChDocuments_clicked();

    void on_ChVideos_clicked();

    void on_ChOther_clicked();


private:
    Ui::MainWindow *ui;

    QStringList strdoc,strmusic,strvideo,strimage,strarchive,strsource,fileindex;
    bool StopList;
    QString cmp,Address,Path;
    QMovie *movie ;

       QAction *DeleteAct;
        QAction *copyAct;
        QAction *PropertyAct;
         QAction *openAct;

};

#endif // MAINWINDOW_H
