#include "polarization_observation.h"

#include <QDebug>

PolarizationObservation::PolarizationObservation(QWidget *parent)
	: QMainWindow(parent) {
		UpdateGUI();
}

PolarizationObservation::~PolarizationObservation() {

}

void PolarizationObservation::UpdateGUI() {
	ui.setupUi(this);

	data::AttributeTablePtr config = data::AttributeTable::create();
	config->insert("NAME", "AVAILABLEPORTS");
	std::vector<std::string> ports = pa_contrl_.get(config)->get_string_array("AVAILABLEPORTS");
	for (int i = 0; i < ports.size(); i++) {
		ui.ports_combobox->addItem(QString::fromStdString(ports[i]));
	}

	connect(ui.go_home_pushbutton, SIGNAL(clicked()), this, SLOT(GoHomeSlot()));
	connect(ui.go_pushbutton, SIGNAL(clicked()), this, SLOT(GoToSlot()));
	connect(&pa_contrl_, SIGNAL(UpdateMsg(QString)), this, SLOT(UpdateMsgSlot(QString)));
}

void PolarizationObservation::GoHomeSlot() {
	GoHome();
}

void PolarizationObservation::GoToSlot() {
	qDebug() << "GoTo";
	GoTo(ui.move_spinbox->value());
}

void PolarizationObservation::GoTo(double pos) {
	data::AttributeTablePtr config = data::AttributeTable::create();
	config->insert("PORTNAME", ui.ports_combobox->currentText().toStdString());
	config->insert("COMMAND", "GOTO");
	config->insert("POS", pos);
	pa_contrl_.set(config);
}

void PolarizationObservation::GoHome() {
	data::AttributeTablePtr config = data::AttributeTable::create();
	config->insert("PORTNAME", ui.ports_combobox->currentText().toStdString());
	config->insert("COMMAND", "GOHOME");
	pa_contrl_.set(config);
}

void PolarizationObservation::UpdateMsgSlot(QString msg) {
	ui.status_label->setText(msg);
}