#include "statusbar.h"

#include <QLabel>
#include <QTimer>

StatusBar::StatusBar(QWidget* parent) :
    QStatusBar(parent)
{
    refreshFPSTimer = new QTimer(this);

    particleCountLabel = new QLabel(this);
    constraintCountLabel = new QLabel(this);
    FPSLabel = new QLabel(this);

    addPermanentWidget(FPSLabel);
    addPermanentWidget(particleCountLabel);
    addPermanentWidget(constraintCountLabel);

    connect(refreshFPSTimer, SIGNAL(timeout()), this, SLOT(updateSpeedLabel()));
    refreshFPSTimer->start(1000);
}

void StatusBar::updateSpeedLabel()
{
    QString text = QString("avg render time = ").append(QString::number(int(renderingTime*1000/nbRefreshes)))
                   .append(" ms / avg physics time = ").append(QString::number(int(physicsTime*1000/nbRefreshes)))
                   .append(" ms / FPS (real/possible) = ").append(QString::number(nbRefreshes))
                   .append("/").append(QString::number(nbRefreshes/(physicsTime+renderingTime), 'f', 2));
    FPSLabel->setText(text);
    nbRefreshes = 0;
    physicsTime = 0;
    renderingTime = 0;
}

void StatusBar::updateSpeed(double physicsT, double renderingT)
{
    ++nbRefreshes;
    physicsTime += physicsT;
    renderingTime += renderingT;
}
