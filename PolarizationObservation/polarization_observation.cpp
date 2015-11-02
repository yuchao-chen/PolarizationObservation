#include "polarization_observation.h"

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
}
