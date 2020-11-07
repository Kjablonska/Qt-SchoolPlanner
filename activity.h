#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>

class Activity
{
public:
    Activity();
    Activity(QString room, QString group, QString clas, int slot, QString day, QString teacher);
    ~Activity();

    QString getRoom();
    void setRoom(QString room);
    QString getGroup();
    void setGroup(QString group);
    int getSlot();
    void setSlot(int slot);
    QString getDay();
    void setDay(QString day);

    QString getTeacher();
    void setTeacher(QString teacher);
    QString getClass();
    void setClass(QString clas);

private:
    QString room;
    QString group;
    QString clas;
    int slot;
    QString day;
    QString teacher;
};

#endif // ACTIVITY_H
