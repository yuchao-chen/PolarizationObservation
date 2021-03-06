#ifndef POLAR_ANALY_CONTRL_H
#define POLAR_ANALY_CONTRL_H

#include <QObject>

#include "attribute_table.h"

namespace ic {
	class PolarAnalyContrl: public QObject {
		Q_OBJECT
	public:
		PolarAnalyContrl();
		~PolarAnalyContrl();
		void set(data::AttributeTablePtr config);
		data::AttributeTablePtr get(data::AttributeTablePtr config);
	signals:
		void UpdateMsg(QString msg);
	private:
		std::vector<std::string> FindAvailablePorts();
			data::AttributeTablePtr config_;
	};
}
#endif