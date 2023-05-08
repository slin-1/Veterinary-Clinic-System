#ifndef CONTROL_H
#define CONTROL_H

#include "View.h"
#include "Schedule.h"

/*
  Class:    Control
  Purpose:  Contains the primary control flow of the clinic program.
*/

class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    Schedule* schedule;
    List<Animal> animals;
    View* view;
    bool addAppt(int animalId, int year, int month, int day, int hours, int mins);
    void initAnimals();
    void initSchedule();

};

#endif
