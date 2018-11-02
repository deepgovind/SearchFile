#include <QCoreApplication>
#include <QTextStream>
#include<QDirIterator>
#include <QFile>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QFile filedoc("filedoc.txt");
    QTextStream outdoc(&filedoc);
    filedoc.open(QFile::WriteOnly);

    QFile filemusic("filemusic.txt");
    QTextStream outmusic(&filemusic);
    filemusic.open(QFile::WriteOnly);

    QFile filevideo("filevideo.txt");
    QTextStream outvideo(&filevideo);
    filevideo.open(QFile::WriteOnly);

    QFile fileimage("fileimage.txt");
    QTextStream outimage(&fileimage);
    fileimage.open(QFile::WriteOnly);

    QFile filearchive("filearchive.txt");
    QTextStream outarchive(&filearchive);
    filearchive.open(QFile::WriteOnly);

    QFile filesource("filesource.txt");
    QTextStream outsource(&filesource);
    filesource.open(QFile::WriteOnly);

    QFile fileother("fileother.txt");
    QTextStream outother(&fileother);
    fileother.open(QFile::WriteOnly);


    QFile Setting("Setting.txt");
    if(!Setting.exists())
    {
        Setting.open(QFile::WriteOnly);
        QTextStream SettingO(&Setting);
        SettingO<<"C\n";
        Setting.close();
    }

    QStringList strdoc,strmusic,strvideo,strimage,strarchive,strsource;

    strdoc<<".docx"<<".axd"<<".chm"<<".doc"<<".rtf"<<".pdf"<<".txt"<<".xls"<<".ppt"<<".pps"<<".opt"<<".sxi"<<".prz"<<".shf"<<".mdi"<<".htm"<<".html"<<".mth"<<".mdb"<<".abw"<<".csv"<<".odt"<<".tex"<<".wpd"<<".wri"<<".xml"<<".osd"<<".ots"<<".wks";
    strmusic<<".amr"<<".mp3"<<".wav"<<".ogg"<<".flac"<<".au"<<".ape"<<".ai"<<".m4a"<<".tta"<<".aac"<<".vox"<<".voc"<<".mid"<<".asx"<<".m3u"<<".pls"<<".ram";
    strvideo<<".ts"<<".mkv"<<".mp4"<<".mpg"<<".avi"<<".divx"<<".mov"<<".flv"<<".3gp"<<".aaf"<<".m1v"<<".m2v"<<".swf"<<".ogm"<<".rm"<<".xvid";
    strimage<<".jpe"<<".ico"<<".jpeg"<<".gif"<<".bmp"<<".jpg"<<".tif"<<".tiff"<<".png"<<".svg"<<".dib"<<".psd"<<".cpt"<<".tga"<<".pix"<<".raw"<<".pdd"<<".pbm";
    strarchive<<".zip"<<".rar"<<".tar"<<".gz"<<".bz2"<<".iso"<<".mdf"<<".ccd"<<".7z"<<".ace"<<".cab"<<".dmg"<<".jar"<<".lzh"<<".z";
    strsource<<".css"<<".aspx"<<".c"<<".cpp"<<".cxx"<<".h"<<".hpp"<<".hxx"<<".cs"<<".vb"<<".java"<<".js"<<".asp"<<".asm"<<".php"<<".pl"<<".py"<<".pyc"<<".pyo"<<".rb"<<".cgi"<<".sh"<<".vbs"<<".tcl"<<".bas"<<".s"<<".m"<<".inc";

    int status = 0;
    foreach (QFileInfo drive, QDir::drives())
    {
        if(drive.isReadable())
        {
                QString st = drive.absoluteFilePath().toAscii().data();

                QString SkipDrive;
                QFile file("Setting.txt");
                if(file.open(QFile::ReadOnly | QFile::Text))
                {
                    QTextStream in(&file);
                    while(!in.atEnd())
                    {
                        SkipDrive =  in.readLine();
                        if(st.mid(0,1) == SkipDrive.toUpper() || st.mid(0,1) == SkipDrive.toLower())
                             status = 1;
                    }
                  file.close();
                }
                else
                {
                      QFile fileSett("Setting.txt");
                      fileSett.open(QFile::WriteOnly);
                        QTextStream outset(&fileSett);
                       outset<<"C\n";
                       fileSett.close();
                }

                      if(status == 1)
                      {
                          status = 0;
                          continue;
                      }

                     QDirIterator it(st,QDir::Files,QDirIterator::Subdirectories);
                      while(it.hasNext())
                      {

                           for (int i = 0; i < strdoc.size(); ++i)
                           {
                               if(QString::compare(it.fileName().mid(it.fileName().lastIndexOf(".")), strdoc.at(i), Qt::CaseInsensitive) == 0)
                              {
                                 outdoc<<it.filePath()+"\n";
                                  goto last;
                              }
                           }
                           for (int i = 0; i < strmusic.size(); ++i)
                           {
                               if(QString::compare(it.fileName().mid(it.fileName().lastIndexOf(".")), strmusic.at(i), Qt::CaseInsensitive) == 0)
                              {
                                  outmusic<<it.filePath()+"\n";
                                   goto last;
                               }
                           }
                           for (int i = 0; i < strvideo.size(); ++i)
                           {
                               if(QString::compare(it.fileName().mid(it.fileName().lastIndexOf(".")), strvideo.at(i), Qt::CaseInsensitive) == 0)
                              {
                                 outvideo<<it.filePath()+"\n";
                                  goto last;
                              }
                           }
                           for (int i = 0; i < strimage.size(); ++i)
                           {
                               if(QString::compare(it.fileName().mid(it.fileName().lastIndexOf(".")), strimage.at(i), Qt::CaseInsensitive) == 0)
                               {
                                   outimage<<it.filePath()+"\n";
                                   goto last;
                                }
                          }
                           for (int i = 0; i < strarchive.size(); ++i)
                           {
                               if(QString::compare(it.fileName().mid(it.fileName().lastIndexOf(".")), strarchive.at(i), Qt::CaseInsensitive) == 0)
                               {
                                   outarchive<<it.filePath()+"\n";
                                   goto last;
                                }
                          }
                           for (int i = 0; i < strsource.size(); ++i)
                           {
                               if(QString::compare(it.fileName().mid(it.fileName().lastIndexOf(".")), strsource.at(i), Qt::CaseInsensitive) == 0)
                               {
                                   outsource<<it.filePath()+"\n";
                                   goto last;
                                }
                          }
                                outother<<it.filePath()+"\n";


                           last:    it.next();

                      }

                 }
        }

    QTimer::singleShot(10, &a, SLOT(quit()));
    return a.exec();
}
