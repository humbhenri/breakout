#include "sound.h"
#include <QDebug>
#include <QSound>
#include <QFile>

Sound::Sound(QString filePath, QObject *parent)
    :filename(filePath), QObject(parent)
{
}

void Sound::play()
{
    QSound::play(filename);
}
