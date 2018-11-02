
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingui.h"
#include <QtGui>
#include "globlefun.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


      movie = new QMovie(":/Loading-Animated-GIF.gif");
      QSize s(371,8);
      movie->setScaledSize(s);
      ui->label->setMovie(movie);
      movie->setSpeed(400);

       ui->FindFileTxt->setGeometry(0,0,261,30);
       ui->frame->setVisible(false);
     // setAttribute(Qt::WA_TranslucentBackground);
    // setWindowFlags(Qt::FramelessWindowHint);

    QFile filem(":/min.css");
    filem.open(QFile::ReadOnly);
    QString styleSheetm = QLatin1String(filem.readAll());
    setStyleSheet(styleSheetm);

     createFilesTable();
     ui->close->setVisible(false);

     strdoc<<".docx"<<".axd"<<".chm"<<".doc"<<".rtf"<<".pdf"<<".txt"<<".xls"<<".ppt"<<".pps"<<".opt"<<".sxi"<<".prz"<<".shf"<<".mdi"<<".htm"<<".html"<<".mth"<<".mdb"<<".abw"<<".csv"<<".odt"<<".tex"<<".wpd"<<".wri"<<".xml"<<".osd"<<".ots"<<".wks";
     strmusic<<".amr"<<".mp3"<<".wav"<<".ogg"<<".flac"<<".au"<<".ape"<<".ai"<<".m4a"<<".tta"<<".aac"<<".vox"<<".voc"<<".mid"<<".asx"<<".m3u"<<".pls"<<".ram";
     strvideo<<".ts"<<".mkv"<<".mp4"<<".mpg"<<".avi"<<".divx"<<".mov"<<".flv"<<".3gp"<<".aaf"<<".m1v"<<".m2v"<<".swf"<<".ogm"<<".rm"<<".xvid";
     strimage<<".jpe"<<".ico"<<".jpeg"<<".gif"<<".bmp"<<".jpg"<<".tif"<<".tiff"<<".png"<<".svg"<<".dib"<<".psd"<<".cpt"<<".tga"<<".pix"<<".raw"<<".pdd"<<".pbm";
     strarchive<<".zip"<<".rar"<<".tar"<<".gz"<<".bz2"<<".iso"<<".mdf"<<".ccd"<<".7z"<<".ace"<<".cab"<<".dmg"<<".jar"<<".lzh"<<".z";
     strsource<<".css"<<".aspx"<<".c"<<".cpp"<<".cxx"<<".h"<<".hpp"<<".hxx"<<".cs"<<".vb"<<".java"<<".js"<<".asp"<<".asm"<<".php"<<".pl"<<".py"<<".pyc"<<".pyo"<<".rb"<<".cgi"<<".sh"<<".vbs"<<".tcl"<<".bas"<<".s"<<".m"<<".inc";

    StopList =0;



         DeleteAct = new QAction(tr("&Delete"), this);
         DeleteAct->setStatusTip(tr("Cut the current selection's contents to the "
                                 "clipboard"));
         connect(DeleteAct, SIGNAL(triggered()), this, SLOT(Delete()));

         copyAct = new QAction(tr("&Copy Path"), this);
         copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                                  "clipboard"));
         connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));

         PropertyAct = new QAction(tr("&Property"), this);
         PropertyAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                                   "selection"));
         connect(PropertyAct, SIGNAL(triggered()), this, SLOT(Property()));

             openAct = new QAction(tr("&Open..."), this);
             openAct->setStatusTip(tr("Open an existing file"));
             connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    ReadSettSe();

   QFileInfo filed("filedoc.txt");
   QFileInfo filea("filearchive.txt");
   QFileInfo filei("fileimage.txt");
   QFileInfo filemu("filemusic.txt");
   QFileInfo files("filesource.txt");
   QFileInfo filev("filevideo.txt");
   QFileInfo fileot("fileother.txt");

   if(!filed.exists())
   {
      indexFile();
   }
   else if(!filea.exists())
        indexFile();
   else if(!filei.exists())
        indexFile();
   else if(!filemu.exists())
        indexFile();
   else if(!files.exists())
        indexFile();
   else if(!filev.exists())
        indexFile();
   else if(!fileot.exists())
        indexFile();


}
void MainWindow::ReadSettSe()
{
    QFile filepo("SettingSe.txt");
    if(filepo.open(QFile::ReadOnly))
    {
           QTextStream inpo(&filepo);
          while(!inpo.atEnd())
          {
              QString re = inpo.readLine();
              if(re == "archive")
              {
                 ui->ChArchive->setChecked(true);
              }
              if(re == "video")
              {
                ui->ChVideos->setChecked(true);
              }
               if(re == "image")
              {
                   ui->ChImages->setChecked(true);
              }
               if(re == "docments")
              {
                ui->ChDocuments->setChecked(true);
              }
               if(re == "source")
              {
                ui->ChSource->setChecked(true);
              }
               if(re == "music")
              {
                ui->ChMusic->setChecked(true);
              }
               if(re == "other")
              {
                ui->ChOther->setChecked(true);
              }
          }

          filepo.close();
    }
}
void MainWindow::WriteSettSe()
{
    QFile filepo("SettingSe.txt");
    if(filepo.open(QFile::WriteOnly))
    {
           QTextStream outpo(&filepo);

        if(ui->ChArchive->isChecked())
        {
            outpo<<"archive"<<"\n";

        }
        if(ui->ChDocuments->isChecked())
        {
            outpo<<"documents"<<"\n";
        }
        if(ui->ChImages->isChecked())
        {
            outpo<<"image"<<"\n";
        }
        if(ui->ChMusic->isChecked())
        {
            outpo<<"music"<<"\n";
        }
        if(ui->ChOther->isChecked())
        {
            outpo<<"other"<<"\n";
        }
        if(ui->ChSource->isChecked())
        {
            outpo<<"source"<<"\n";
        }
        if(ui->ChVideos->isChecked())
        {
            outpo<<"video"<<"\n";
        }
          filepo.close();
    }

}

void MainWindow::createFilesTable()
{

      ui->filesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
       ui->filesTable->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
       ui->filesTable->verticalHeader()->hide();
       ui->filesTable->horizontalHeader()->hide();
       ui->filesTable->setShowGrid(false);
       ui->filesTable->hideColumn(1);

       // ui->filesTable->verticalScrollBar()->setStyle(new QWindowsVistaStyle);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::searchFile(QString str1,QString Filen)
{

       QFile file(Filen);
     if(file.open(QIODevice::ReadOnly | QIODevice::Text))
     {
         QTextStream in(&file);
         while(!in.atEnd())
         {
              Address =  in.readLine();
               QFileInfo fi(Address);

                if(!fi.exists())
                    continue;

             qApp->processEvents();
             if(StopList ==  1)
              {
                 file.close();
                 movie->stop();
                break;
              }
            /*  if(!W1->isActiveWindow())
              {
                 file.close();
                 StopList = 1;
                movie->stop();
               //   W1->setFixedHeight(58);
               //   W1->setFixedWidth(233);
                  ui->FindFileTxt->setGeometry(0,22,231,30);
                   ReadSettpo();
                QFile fileC("SettingCh.txt");
                if(fileC.open(QFile::ReadOnly))
                {
                       QTextStream in(&fileC);
                       while(!in.atEnd())
                       {
                            QString re = in.readLine();
                            if(re.toInt() == 1)
                            {
                               on_close_clicked();
                            }

                       }
                       fileC.close();
                 }
                 break;
              } */

               if(fi.fileName().contains(str1,Qt::CaseInsensitive))
              {



                int row = ui->filesTable->rowCount();
                int row2  = row +1;
                 int row3  = row2 +1;


                QTableWidgetItem *fileNameItem = new QTableWidgetItem(fi.fileName());
                fileNameItem->setFlags(fileNameItem->flags() ^ Qt::ItemIsEditable);

                QTableWidgetItem *fileAdrrItem = new QTableWidgetItem(Address);
                fileAdrrItem->setFlags(fileAdrrItem->flags() ^ Qt::ItemIsEditable);


                QTableWidgetItem *FoldAdd = new QTableWidgetItem("                     "+fi.absolutePath());
                FoldAdd->setFlags(FoldAdd->flags() ^ Qt::ItemIsEditable);

                QTableWidgetItem *FoldAdd1 = new QTableWidgetItem(fi.absolutePath());
                FoldAdd1->setFlags(FoldAdd1->flags() ^ Qt::ItemIsEditable);


                QTableWidgetItem *fileNameItemH1 = new QTableWidgetItem("");
                fileNameItemH1->setFlags(fileNameItemH1->flags() ^ Qt::ItemIsEditable);

                QTableWidgetItem *fileNameItemH2 = new QTableWidgetItem("");
                fileNameItemH2->setFlags(fileNameItemH2->flags() ^ Qt::ItemIsEditable);


                 ui->filesTable->insertRow(row);
                 ui->filesTable->setRowHeight(row,20);
                  ui->filesTable->setItem(row, 0, fileNameItem);
                 ui->filesTable->setItem(row, 1, fileAdrrItem);

                 QFileIconProvider ip;
                 QIcon ic = ip.icon(fi);
                 ui->filesTable->item(row,0)->setIcon(ic);


                 ui->filesTable->insertRow(row2);
                 ui->filesTable->setRowHeight(row2,20);
                 ui->filesTable->setItem(row2,0, FoldAdd);
                 ui->filesTable->setItem(row2, 1, FoldAdd1);



                 ui->filesTable->insertRow(row3);
                 ui->filesTable->setRowHeight(row3,20);
                 ui->filesTable->setItem(row3, 0, fileNameItemH1);
                 ui->filesTable->setItem(row3, 1, fileNameItemH2);

                 ui->filesTable->item(row,0)->setTextColor(Qt::blue);
                 ui->filesTable->item(row2,0)->setTextColor(Qt::darkMagenta);

                 QFont serifFont("Segoe UI", 9, QFont::Normal);
                 ui->filesTable->item(row2,0)->setFont(serifFont);

                }
           }
       file.close();
    }
    else
    {
       indexFile();
    }

}
void MainWindow::on_FindFileTxt_textChanged(const QString &arg1)
{
    ui->FindFileTxt->setGeometry(0,50,391,30);
    ui->frame->setVisible(true);
    W1->setFixedHeight(563);
    W1->setFixedWidth(393);

   WriteSettSe();
    cmp =  ui->FindFileTxt->text();
    StopList =1;
     movie->stop();
          ui->close->setVisible(true);
          ui->filesTable->clear();
          ui->filesTable->setRowCount(0);

    if(arg1.isEmpty()  || (arg1.count(" ") == arg1.length()))
    {
        StopList =  1;
        ui->label->setVisible(false);
        movie->stop();
        ui->filesTable->clear();
        ui->close->setVisible(false);
        ui->filesTable->setRowCount(0);

        ui->FindFileTxt->setGeometry(0,0,261,30);
        ui->frame->setVisible(false);

        W1->setFixedHeight(31);
        W1->setFixedWidth(261);

    }
    else
    {
         StopList =  0;
         movie->start();

         ui->label->setVisible(true);

        if(ui->ChArchive->isChecked())
        {
            searchFile(cmp,"filearchive.txt");
        }
        if(ui->ChDocuments->isChecked())
        {
           searchFile(cmp,"filedoc.txt");
        }
        if(ui->ChImages->isChecked())
        {
              searchFile(cmp,"fileimage.txt");
        }
        if(ui->ChMusic->isChecked())
        {
             searchFile(cmp,"filemusic.txt");
         }
        if(ui->ChSource->isChecked())
        {
              searchFile(cmp,"filesource.txt");
         }
        if(ui->ChVideos->isChecked())
        {
             searchFile(cmp,"filevideo.txt");
         }
        if(ui->ChOther->isChecked())
        {
             searchFile(cmp,"fileother.txt");

        }
        StopList =1;
        movie->stop();
        ui->label->setVisible( false);
    }

}
void MainWindow::on_close_clicked()
{
     StopList = 1;
      movie->stop();
      ui->close->setVisible(false);
 WriteSettSe();

}
void MainWindow::indexFile()
{

    int re = QMessageBox::warning(this,"Setting","Do you Change Setting",QMessageBox::Yes,QMessageBox::No);
    if(re == QMessageBox::Yes)
    {
        SettingUi *sett = new SettingUi();
        sett->show();
         int ret =  QMessageBox::information(this," Permition "," Do you Agree To Re-Index\n",QMessageBox::Yes,QMessageBox::No);
          if(ret == QMessageBox::Yes)
          {
            bool ret =  QDesktopServices::openUrl(QDir::currentPath()+"\\indexf.exe");
            if(ret)
              QMessageBox::information(this,"Informetion ","Re indexing Started....\n Please Use This Software After few Minuts...");
            else
              QMessageBox::information(this,"Error !"," Can'n Find indexf.exe File");
          }
          else
          {
               QMessageBox::information(this,"Informetion ","You Can not search File");

          }
    }


       QTimer::singleShot(5,this, SLOT(close()));
}


void MainWindow::on_filesTable_cellDoubleClicked(int row, int )
{

     QTableWidgetItem *item = ui->filesTable->item(row, 1);
    bool r =  QDesktopServices::openUrl(item->text());
     if(!r)
     {
         QMessageBox::critical(this,"Error ","File "+Path+"  Not Find");
     }

}
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
 {
     QMenu menu(this);
     menu.addAction(openAct);
     menu.addAction(copyAct);
     menu.addAction(DeleteAct);
     menu.addAction(PropertyAct);
     menu.exec(event->globalPos());
 }


void MainWindow::open()
{
     bool r = QDesktopServices::openUrl(Path);
     if(!r)
     {
         QMessageBox::critical(this,"Error ","File "+Path+"  Not Find");
     }
}

void MainWindow::Delete()
 {
    QFileInfo inf(Path);
    QFile fi(Path);
     if(inf.isFile())
     {
            int ret =  QMessageBox::warning(this,"Warning","Do You Went to Delete File",QMessageBox::Yes,QMessageBox::No);
            if(ret == QMessageBox::Yes)
            {
                 bool r  =  fi.remove();
                 if(r)
                     QMessageBox::warning(this,"Informetion","File "+Path+"  Remove SucessFull..");
                 else
                     QMessageBox::critical(this,"Error","File Not Find or File is Removed");
            }


     }

 }

 void MainWindow::copy()
 {
     QClipboard *clipboard = QApplication::clipboard();
     clipboard->setText(Path);
 }

 void MainWindow::Property()
 {
     QFile fi(Path);
     QFileInfo fil(Path);
    QMessageBox::information(0,"Property","File Name :   "
                                         " "+Path+"\n"
                                         "\n\nFile Size in Byte :"+QString::number(fi.size())+" Byte\n"
                                                            "\nFile Size in MB  :"+QString::number(fi.size()/(1024.0*1024))+" MB\n\n"
                                                                                                                         "File Size in GB  :"+QString::number(fi.size()/(1024.0*1024*1024)));

 }

void MainWindow::on_filesTable_cellClicked(int row, int)
{

     QTableWidgetItem *item = ui->filesTable->item(row, 1);
     if(!item->text().isEmpty())
        Path  = item->text();
}


void MainWindow::on_SettingButton_clicked()
{
    SettingUi *sett = new SettingUi(this);
    sett->show();

}

void MainWindow::on_ChImages_clicked()
{
    on_FindFileTxt_textChanged(ui->FindFileTxt->text());
}

void MainWindow::on_ChSource_clicked()
{
    on_FindFileTxt_textChanged(ui->FindFileTxt->text());
}

void MainWindow::on_ChArchive_clicked()
{
    on_FindFileTxt_textChanged(ui->FindFileTxt->text());
}

void MainWindow::on_ChMusic_clicked()
{
    on_FindFileTxt_textChanged(ui->FindFileTxt->text());
}

void MainWindow::on_ChDocuments_clicked()
{
    on_FindFileTxt_textChanged(ui->FindFileTxt->text());
}

void MainWindow::on_ChVideos_clicked()
{
    on_FindFileTxt_textChanged(ui->FindFileTxt->text());
}

void MainWindow::on_ChOther_clicked()
{
    on_FindFileTxt_textChanged(ui->FindFileTxt->text());
}
