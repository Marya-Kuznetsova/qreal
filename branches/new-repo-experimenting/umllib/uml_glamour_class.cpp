#include <QtGui>

#include "uml_glamour_class.h"
#include "realreporoles.h"

using namespace UML;

GlamourClass::GlamourClass()
{
	ports << QPointF(70,0) << QPointF(70,170) << QPointF(0,85) << QPointF(140,85);
}

GlamourClass::~GlamourClass()
{
}

void GlamourClass::updateData()
{
	NodeElement::updateData();

	QString name = dataIndex.data().toString();
	text = "<center><img src=\":/images/kdevclassview/CVclass.png\" /><b>class ";
	text += name;
	text += "</b><hr>&nbsp;";

	fields.clear();
	methods.clear();

//	methods = dataIndex.data(Unreal::MethodsRole).toString().split(';');
//	fields = dataIndex.data(Unreal::FieldsRole).toString().split(';');

	foreach (QString str, methods) {
		text += "<img src=\":/images/kdevclassview/CVpublic_meth.png\" />";
		text += str;
		text += "<br>\n";
	}

	text += "<hr>&nbsp;";

	foreach (QString str, fields) {
		text += "<img src=\":/images/kdevclassview/CVpublic_var.png\" />";
		text += str;
		text += "<br>\n";
	}

	text += "</center>";

	update();
}

void GlamourClass::contextMenuEvent ( QGraphicsSceneContextMenuEvent * event )
{
/*	QMenu menu;

	QAction *addMethAction = menu.addAction("Add Method");
	QAction *delMethAction = menu.addAction("Remove Method");

	QAction *addPropAction = menu.addAction("Add Property");
	QAction *delPropAction = menu.addAction("Remove Property");
	
	QAbstractItemModel *im = const_cast<QAbstractItemModel *>(dataIndex.model());

	if ( QAction *selectedAction = menu.exec(event->screenPos()) ) {
		bool ok;

		if ( selectedAction == addMethAction ) {
			QString text = QInputDialog::getText(0, QObject::tr("New Method"), QObject::tr("Method name:"), QLineEdit::Normal, "", &ok);
			if (ok && !text.isEmpty()) {
				methods << text;
				im->setData(dataIndex, methods.join(";"), Unreal::MethodsRole );
			}
		} else if ( selectedAction == delMethAction ) {
			QString text = QInputDialog::getItem(0, QObject::tr("Remove Method"), QObject::tr("Method name:"), methods, 0, false, &ok);
			if (ok && !text.isEmpty()) {
				methods.removeAll(text);
				im->setData(dataIndex, methods.join(";"), Unreal::MethodsRole );
			}
		} else if ( selectedAction == addPropAction ) {
			QString text = QInputDialog::getText(0, QObject::tr("New Field"), QObject::tr("Field name:"), QLineEdit::Normal, "", &ok);
			if (ok && !text.isEmpty()) {
				fields << text;
				im->setData(dataIndex, fields.join(";"), Unreal::FieldsRole );
			}
		} else if ( selectedAction == delPropAction ) {
			QString text = QInputDialog::getItem(0, QObject::tr("Remove Field"), QObject::tr("Field name:"), fields, 0, false, &ok);
			if (ok && !text.isEmpty()) {
				fields.removeAll(text);
				im->setData(dataIndex, fields.join(";"), Unreal::FieldsRole );
			}
		}
	} */
}

void GlamourClass::paint(QPainter *painter, const QStyleOptionGraphicsItem *style, QWidget *widget)
{
	//    QPainterPath path;
	//    path.moveTo(0,0);
	//    path.lineTo(100,100);
	//    path.moveTo(100,0);
	//    path.lineTo(0,100);

	//    painter->drawPath(path);
	//    painter->drawRect(boundingRect());

	QPen oldPen = painter->pen();
	QPen pen = oldPen;
	int width = 0;
	if (style->state & QStyle::State_Selected)
		width += 2;

	pen.setWidth(width);

	painter->setPen(pen);

	painter->setBrush(QBrush(QColor(255,255,191,200)));
	painter->drawRect(contentsRect());

	painter->setPen(oldPen);

	if (style->levelOfDetail > 0.5) {
		QTextDocument d;
		d.setHtml(text);
		d.setTextWidth(contentsRect().width());
		d.drawContents(painter,contentsRect());

		NodeElement::paint(painter, style, widget);
	}
}

QRectF GlamourClass::boundingRect() const
{
	return QRectF(-8,-8,156,186);
}

QRectF GlamourClass::contentsRect() const
{
	return QRectF(0,0,140,170);
}
