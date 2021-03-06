#ifndef WALLPAPER_H
#define WALLPAPER_H

#include "wallpapermask.h"
#include "mpvwidget.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QFileSystemWatcher>
#include <QPropertyAnimation>

class Wallpaper : public QWidget
{
    Q_OBJECT
public:
    explicit Wallpaper(QWidget *parent = 0);

public slots:
    void setFolder(const QStringList &list, const bool isVideo);
    void setVolume(const qint32 volume);
    void setInterval(const qint32 interval);
    void clear();
    void play();
    void pause();
    void stop();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    void registerDesktop();

private slots:
    void onTimerOut();

    void adjustGeometry();
private:
    bool m_isVideo;
    QPixmap m_pixmap;
    QStringList m_folderList;
    QVBoxLayout *mainlayout;
    int m_index;
    QTimer *m_adjustTimer;
    WallpaperMask *m_label;
    QPropertyAnimation *redAnimation;
    QTimer *m_wallpaperTimer;
    MpvWidget *m_mpv;

    QWidget *mpv_container;
    mpv_handle *mpv;
};

#endif // WALLPAPER_H
