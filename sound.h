#ifndef SOUND_H
#define SOUND_H
#include <QString>
#include <QObject>

class Sound: public QObject
{
    Q_OBJECT
public:
    explicit Sound(QString, QObject *parent=0);
    void play();
private:
    QString filename;

};

#endif // SOUND_H
