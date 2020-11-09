#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>

class Activity
{
public:
    Activity();
    Activity(QString room, QString group, QString clas, int slot, QString day, QString teacher);
    ~Activity();

    QString getRoom() const { return room; }
    void setRoom(QString room) { this->room = room; }
    QString getGroup() const { return group; }
    void setGroup(QString group) { this->group = group; }
    QString getClass() const { return clas; }
    void setClass(QString clas) { this-> clas = clas; }
    int getSlot() const { return slot; }
    void setSlot(int slot) { this->slot = slot; }
    QString getDay() const { return day; }
    void setDay(QString day) { this->day = day; }
    QString getTeacher() const { return teacher; }
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
