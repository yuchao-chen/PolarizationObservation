#include "polar_analy_contrl.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

namespace ic {
	PolarAnalyContrl::PolarAnalyContrl() 
		:config_(data::AttributeTable::create()) {
	}
	PolarAnalyContrl::~PolarAnalyContrl() {
	}

	void PolarAnalyContrl::set(data::AttributeTablePtr config) {
		std::string port_name = config->get_string("PORTNAME");
		std::string cur_port_name = config_->get_string("PORTNAME");

		std::string command = config->get_string("COMMAND");
		//qDebug() << QString::fromStdString(command);
		if (command == "GOHOME") {
		//	GoHome();
		} else if (command == "GOTO") {
		//	GoTo(config->get_long("POS"));
		}
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