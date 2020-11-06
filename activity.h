#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>

class Activity
{
public:
    Activity();
    Activity(QString room, QString group, QString clas, int slot, int day, QString teacher);
    ~Activity();

    QString getRoom();
    void setRoom(QString room);
    QString getGroup();
    void setGroup(QString group);
    int getSlot();
    void setSlot(int slot);
    int getDay();
    void setDay(int day);

    QString getTeacher();
    void setTeacher(QString teacher);
    QString getClass();
    void setClass(QString clas);

private:
    QString room;
    QString group;
    QString clas;
    int slot;
    int day;
    QString teacher;
};

#endif // ACTIVITY_H
