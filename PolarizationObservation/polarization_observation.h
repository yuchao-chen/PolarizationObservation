#ifndef POLARIZATION_OBSERVATION_H
#define POLARIZATION_OBSERVATION_H

#include <QtWidgets/QMainWindow>
#include "ui_polarization_observation.h"

class PolarizationObservation : public QMainWindow
{
	Q_OBJECT

public:
	PolarizationObservation(QWidget *parent = 0);
	~PolarizationObservation();

private:
	Ui::PolarizationObservationClass ui;
};

#endif // POLARIZATION_OBSERVATION_H
