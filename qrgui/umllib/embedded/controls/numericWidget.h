#pragma once

#include "embeddedControl.h"
#include "../../element.h"

#include <QSpinBox>

class NumericWidget : public QSpinBox, public EmbeddedControl
{
	Q_OBJECT
	public:
		NumericWidget(Element *element, const QString &propertyName, QWidget *parent = 0);
		NumericWidget* castToWidget() const;
	private:
		Element *element;
	private slots:
		void setNewValue(const int value) const;
};
