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
