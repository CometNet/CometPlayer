#include "playermain.h"
#include "ui_playermain.h"

PlayerMain::PlayerMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayerMain)
{
    ui->setupUi(this);

    m_vplayer = new VlcPlayer(this);
    connect(ui->hsilder_volume,&QSlider::valueChanged,[=](int value){m_vplayer->SetVolume(value);});
    connect(m_vplayer,&VlcPlayer::playAllTime,[=](int alltime){ui->hslider_progess->setMaximum(alltime);ui->lab_time->setText(QString::number(alltime));});
    connect(m_vplayer,&VlcPlayer::playCurrentTime,[=](int currenttime){ui->hslider_progess->setValue(currenttime);});

}

PlayerMain::~PlayerMain()
{
    delete ui;
}

void PlayerMain::on_btn_open_clicked()
{
    QString filename =QFileDialog::getOpenFileName(this,
                                               tr("Open video"), "", tr("video Files (*.mp4 *.avi *.wav)"));
    filename.replace("/","\\");
    m_vplayer->Play(filename,(void*)ui->widget_video->winId());
    qDebug()<<m_vplayer->GetPlayTime()<<m_vplayer->GetPos()<<m_vplayer->GetTime()<<m_vplayer->GetVolume();
    ui->hsilder_volume->setValue(99);
}

void PlayerMain::on_btn_pause_clicked()
{
    if(ui->btn_pause->text() == QStringLiteral("暂停")){
        m_vplayer->Pause();
        ui->btn_pause->setText( QStringLiteral("继续"));
    }else{
        m_vplayer->Play();
        ui->btn_pause->setText(QStringLiteral("暂停"));
    }
}

