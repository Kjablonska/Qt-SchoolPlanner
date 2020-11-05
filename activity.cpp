#include "activity.h"

Activity::Activity() {}

Activity::Activity(QString room, QString group, QString clas, int slot, QString day, QString teacher) {
    this->room = room;
    this->group = group;
    this->clas = clas;
    this->slot = slot;
    this->day = day;
    this->teacher = teacher;
}

Activity::~Activity() {}

QString Activity::getRoom() {
    return room;
}

void Activity::setRoom(QString room) {
    this->room = room;
}

QString Activity::getGroup() {
    return group;
}

void Activity::setGroup(QString group) {
    this->group = group;
}

QString Activity::getClass() {
    return clas;
}

void Activity::setClass(QString clas) {
    this->clas = clas;
}

int Activity::getSlot() {
    return slot;
}

void Activity::setSlot(int slot) {
    this->slot = slot;
}

QString Activity::getDay() {
    return day;
}

void Activity::setDay(QString day) {
    this->day = day;
}

QString Activity::getTeacher() {
    return teacher;
}

void Activity::setTeacher(QString teacher) {
    this->teacher = teacher;
}
