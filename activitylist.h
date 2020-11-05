#ifndef ACTIVITYLIST_H
#define ACTIVITYLIST_H

#include <QList>
#include "activity.h"

class ActivityList
{
public:
    ActivityList();
    ~ActivityList();

    void addActivity(Activity activity);
    void deleteActivity(Activity activity);
    QList<Activity> getActivitiesByRoom(QString room);

private:
    QList<Activity> activityList;
};

#endif // ACTIVITYLIST_H
