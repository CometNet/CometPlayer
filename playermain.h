#ifndef PLAYERMAIN_H
#define PLAYERMAIN_H

#include <QWidget>
#include<QFileDialog>
#include<QDebug>
#include "vlcplayer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PlayerMain; }
QT_END_NAMESPACE

class PlayerMain : public QWidget
{
    Q_OBJECT

public:
    PlayerMain(QWidget *parent = nullptr);
    ~PlayerMain();

private slots:
    void on_btn_open_clicked();
    void on_btn_pause_clicked();

private:
    Ui::PlayerMain *ui;
    VlcPlayer* m_vplayer;
};
#endif // PLAYERMAIN_H
