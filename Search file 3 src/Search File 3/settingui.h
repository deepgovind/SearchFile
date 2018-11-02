#ifndef SETTINGUI_H
#define SETTINGUI_H

#include <QDialog>

namespace Ui {
class SettingUi;
}

class SettingUi : public QDialog
{
    Q_OBJECT

public:
    explicit SettingUi(QWidget *parent = 0);
    ~SettingUi();

private slots:

    void on_Save_clicked();
    void setup();
    void on_help_clicked();

private:
    Ui::SettingUi *ui;
};

#endif // SETTINGUI_H
