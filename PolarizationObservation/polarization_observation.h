#ifndef POLARIZATION_OBSERVATION_H
#define POLARIZATION_OBSERVATION_H

#include <QtWidgets/QMainWindow>

#include "ui_polarization_observation.h"

#include "attribute_table.h"
#include "polar_analy_contrl.h"

class PolarizationObservation : public QMainWindow {
	Q_OBJECT

public:
	PolarizationObservation(QWidget *parent = 0);
	~PolarizationObservation();

private:
	void UpdateGUI();

	Ui::PolarizationObservationClass ui;
	ic::PolarAnalyContrl pa_contrl_;
};

#endif // POLARIZATION_OBSERVATION_H
