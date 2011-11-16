#ifndef CLICKABLEAREA_H
#define CLICKABLEAREA_H

#include <QLabel>

class ClickableArea : public QLabel
{
    Q_OBJECT

public:
    ClickableArea( QWidget * parent = 0 );
    ~ClickableArea();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *ev);

};

#endif // CLICKABLEAREA_H

