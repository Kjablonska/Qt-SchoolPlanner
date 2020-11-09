#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>

class Activity
{
public:
    Activity();
    Activity(QString room, QString group, QString clas, int slot, QString day, QString teacher);
    ~Activity();

    QString getRoom() { return room; }
    void setRoom(QString room) { this->room = room; }
    QString getGroup() { return group; }
    void setGroup(QString group) { this->group = group; }
    QString getClass() {return clas; }
    void setClass(QString clas) { this-> clas = clas; }
    int getSlot() { return slot; }
    void setSlot(int slot) { this->slot = slot; }
    QString getDay() { return day; }
    void setDay(QString day) { this->day = day; }
    QString getTeacher() { return teacher; }
    void setTeacher(QString teacher) { this->teacher = teacher; }

private:
    QString room;
    QString group;
    QString clas;
    int slot;
    QString day;
    QString teacher;
};

#endif // ACTIVITY_H
