#ifndef VLCPLAYER_H
#define VLCPLAYER_H

#include <QObject>
#include<QFile>
#include<QDebug>

#include"vlc/vlc.h"

class VlcPlayer : public QObject
{
    Q_OBJECT
public:
    explicit VlcPlayer(QObject *parent = nullptr);
    // 播放
    int Play(QString filename,void* hwnd = nullptr);
    //去黑边
    void RemoveBlack();
    // 播放
    int Play();
    // 暂停
    void Pause();
    // 停止
    void Stop();
    // 音量设置为nVol
    void SetVolume(int nVol);
    //获取音量值
    int GetVolume();
    // 跳到指定位置nPos
    void SeekTo(float nPos);
    // 文件是否打开
    bool IsOpen();
    // 文件是否正在播放
    bool IsPlaying();
    // 是否暂停
    bool IsPause();
    // 获取文件当前播放的位置
    int GetPos();
    //获取总时长
    int64_t GetTime();
    // 获取播放时间
    int64_t GetPlayTime();
    // 设置播放时间
    void SetPlayTime(int64_t time);
    //获取播放状态
    int GetPlayState();
    //设置音轨
    bool setTrack(int trackIndex);
    //销毁
    void Release();

signals:
    void playAllTime(int sec);
    void playCurrentTime(int sec);

public slots:
private:
    libvlc_instance_t     *m_pVLC_Inst;                      // VLC实例
    libvlc_media_player_t *m_pVLC_Player;            // VLC播放器
    libvlc_event_manager_t *m_pVLC_eMg;           //VLC事件
};

#endif // VLCPLAYER_H
