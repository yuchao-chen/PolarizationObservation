#include "polar_analy_contrl.h"

#include <QtSerialPort/QSerialPortInfo>
namespace ic {
	PolarAnalyContrl::PolarAnalyContrl() {
	}
	PolarAnalyContrl::~PolarAnalyContrl() {
	}

	void PolarAnalyContrl::set(data::AttributeTablePtr config) {
	
	}

	data::AttributeTablePtr PolarAnalyContrl::get(data::AttributeTablePtr config) {
		data::AttributeTablePtr r = data::AttributeTable::create();
		if (config->get_string("NAME") == "AVAILABLEPORTS") {
			std::vector<std::string> ports = FindAvailablePorts();
			r->insert("AVAILABLEPORTS", ports);
		}
		return r;
	}

	std::vector<std::string> PolarAnalyContrl::FindAvailablePorts() {
		std::vector<std::string> ports;
		foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
			ports.push_back(serial_port_info.portName().toStdString());
		}
		return ports;
	}
}