#include "include/ClickableArea.h"

ClickableArea::ClickableArea(QWidget *parent) :
    QLabel(parent)
{
}

ClickableArea::~ClickableArea()
{
}

void ClickableArea::mousePressEvent(QMouseEvent *ev)
{
    emit clicked();
}
