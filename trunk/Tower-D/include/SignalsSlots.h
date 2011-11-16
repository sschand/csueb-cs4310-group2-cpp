#include <QtGUI>
#include <QtCore\QObject>

using namespace std;

#ifndef SIGNALSSLOTS_H
#define SIGNALSSLOTS_H

/*
 *  Signal Slots Class to do Qt Signalling and Slot Callbacks
 *
 *   It is hoped that by implementing this class, that the issue of not being able to update the View will be resolved.
 *
 *     Design and Implementation of the view by:
 *        Donat, Brian L.
 */

class SignalsSlots : public QObject
{
    Q_OBJECT
    Q_OBJECT_GETSTATICMETAOBJECT

    public:

        SignalsSlots() {
            mValue = 0;
        }

        //virtual ~SignalsSlots() {
        //}
        int value() const { return mValue; }

    public slots:
        void setViewUpdate(int value);
        //void doSomething() {
           // Later
        //};

    signals:
        void viewChanged(int newValue) {};

    protected:
    private:
        int mValue;
};

#endif // SIGNALSSLOTS_H
