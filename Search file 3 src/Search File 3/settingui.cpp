#include "settingui.h"
#include "ui_settingui.h"
#include <QtGui>

SettingUi::SettingUi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingUi)
{
    ui->setupUi(this);

   setup();
}

SettingUi::~SettingUi()
{
    delete ui;
}

void SettingUi::setup()
{

    foreach (QFileInfo drive, QDir::drives())
    {
        if(drive.isReadable())
        {
                QString st = drive.absoluteFilePath().toAscii().data();

                ui->listWidget->addItem(st);

                        QListWidgetItem* item = 0;
                          for(int i = 0; i < ui->listWidget->count(); i++)
                          {
                              item = ui->listWidget->item(i);
                              item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
                              item->setCheckState(Qt::Unchecked);
                          }
        }
  }


                    QFile file("Setting.txt");
                    if(file.open(QFile::ReadOnly | QFile::Text))
                    {
                        QTextStream in(&file);
                        while(!in.atEnd())
                        {
                           QString  SkipDrive =  in.readLine();

                             QListWidgetItem* item = 0;
                              for(int i = 0; i < ui->listWidget->count(); i++)
                              {
                                  item = ui->listWidget->item(i);
                                  if(item->text().mid(0,1) == SkipDrive.toUpper() || item->text().mid(0,1) == SkipDrive.toLower())
                                  {
                                      item->setCheckState(Qt::Checked);
                                  }
                              }
                        }
                      file.close();
                    }



}

void SettingUi::on_Save_clicked()
{
    QFile filep("Setting.txt");
    if(filep.open(QFile::WriteOnly))
    {
           QTextStream outpari(&filep);
           QListWidgetItem* item = 0;
           for(int i = 0; i < ui->listWidget->count(); i++)
           {
                 item = ui->listWidget->item(i);
                 if(item->checkState() == Qt::Checked)
                 {

                     outpari<<item->text().mid(0,1)<<"\n";

                  }
             }
           filep.close();
     }
  this->close();

}
void SettingUi::on_help_clicked()
{
    QMessageBox::information(this,"Help ","Do Not do This --->\n 1) Do Not Delete Or Rename Any File"
                                             "\n\n For Skip Index a Drive ----->"
                                             "\n 1) Open Setting  window "
                                             "\n 2) For Skip more then one Drive Select Drive from setting window"
                                             "\n 3) This Software Can't Index Skiping Drive."
                                             "\n 4) By Default C Drive is skiped"
                                             "\n For More Help Contect with me "
                                             " \n\n\nGOVT. Polytechnic Unnao \n \
                                                 Deep Govind  CSE Final Year  - 2015 / 2016 \n\
                                                 Email - deepgovind4@gmailo.com  Mo. - 7388966141 \n"
                                                                                                    "\n 5) Right click and do operation");
}
