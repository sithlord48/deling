#include "MiscWidget.h"

MiscWidget::MiscWidget(QWidget *parent)
	: PageWidget(parent)
{
//	build();
}

void MiscWidget::build()
{
	if(isBuilded())	return;

	QLabel *nameLbl = new QLabel(tr("Nom :"), this);
	nameEdit = new QLineEdit(this);
	QLabel *ratLbl = new QLabel(tr("RAT :"), this);
	ratEdit = new QLineEdit(this);
	QLabel *mrtLbl = new QLabel(tr("MRT :"), this);
	mrtEdit = new QLineEdit(this);
	QLabel *pmpLbl = new QLabel(tr("PMP :"), this);
	pmpEdit = new QLineEdit(this);
	QLabel *pmdLbl = new QLabel(tr("PMD :"), this);
	pmdEdit = new QLineEdit(this);
	QLabel *pvpLbl = new QLabel(tr("PVP :"), this);
	pvpEdit = new QLineEdit(this);
	gateList = new QListWidget(this);

	caVectorX1Edit = new QSpinBox(this);
	caVectorX1Edit->setRange(-32768, 32767);
	caVectorX2Edit = new QSpinBox(this);
	caVectorX2Edit->setRange(-32768, 32767);
	caVectorX3Edit = new QSpinBox(this);
	caVectorX3Edit->setRange(-32768, 32767);

	caVectorY1Edit = new QSpinBox(this);
	caVectorY1Edit->setRange(-32768, 32767);
	caVectorY2Edit = new QSpinBox(this);
	caVectorY2Edit->setRange(-32768, 32767);
	caVectorY3Edit = new QSpinBox(this);
	caVectorY3Edit->setRange(-32768, 32767);

	caVectorZ1Edit = new QSpinBox(this);
	caVectorZ1Edit->setRange(-32768, 32767);
	caVectorZ2Edit = new QSpinBox(this);
	caVectorZ2Edit->setRange(-32768, 32767);
	caVectorZ3Edit = new QSpinBox(this);
	caVectorZ3Edit->setRange(-32768, 32767);

	caSpaceXEdit = new QDoubleSpinBox(this);
	qreal maxInt = qPow(2,31);
	caSpaceXEdit->setRange(-maxInt, maxInt);
	caSpaceXEdit->setDecimals(0);
	caSpaceYEdit = new QDoubleSpinBox(this);
	caSpaceYEdit->setRange(-maxInt, maxInt);
	caSpaceYEdit->setDecimals(0);
	caSpaceZEdit = new QDoubleSpinBox(this);
	caSpaceZEdit->setRange(-maxInt, maxInt);
	caSpaceZEdit->setDecimals(0);

	connect(caVectorX1Edit, SIGNAL(valueChanged(int)), SLOT(editCaVector(int)));
	connect(caVectorX2Edit, SIGNAL(valueChanged(int)), SLOT(editCaVector(int)));
	connect(caVectorX3Edit, SIGNAL(valueChanged(int)), SLOT(editCaVector(int)));
	connect(caVectorY1Edit, SIGNAL(valueChanged(int)), SLOT(editCaVector(int)));
	connect(caVectorY2Edit, SIGNAL(valueChanged(int)), SLOT(editCaVector(int)));
	connect(caVectorY3Edit, SIGNAL(valueChanged(int)), SLOT(editCaVector(int)));
	connect(caVectorZ1Edit, SIGNAL(valueChanged(int)), SLOT(editCaVector(int)));
	connect(caVectorZ2Edit, SIGNAL(valueChanged(int)), SLOT(editCaVector(int)));
	connect(caVectorZ3Edit, SIGNAL(valueChanged(int)), SLOT(editCaVector(int)));

	connect(caSpaceXEdit, SIGNAL(valueChanged(double)), SLOT(editCaPos(double)));
	connect(caSpaceYEdit, SIGNAL(valueChanged(double)), SLOT(editCaPos(double)));
	connect(caSpaceZEdit, SIGNAL(valueChanged(double)), SLOT(editCaPos(double)));

	QGridLayout *caLayout = new QGridLayout;
	caLayout->addWidget(caVectorX1Edit, 0, 0);
	caLayout->addWidget(caVectorX2Edit, 0, 1);
	caLayout->addWidget(caVectorX3Edit, 0, 2);
	caLayout->addWidget(caVectorY1Edit, 1, 0);
	caLayout->addWidget(caVectorY2Edit, 1, 1);
	caLayout->addWidget(caVectorY3Edit, 1, 2);
	caLayout->addWidget(caVectorZ1Edit, 2, 0);
	caLayout->addWidget(caVectorZ2Edit, 2, 1);
	caLayout->addWidget(caVectorZ3Edit, 2, 2);
	caLayout->addWidget(caSpaceXEdit, 3, 0);
	caLayout->addWidget(caSpaceYEdit, 3, 1);
	caLayout->addWidget(caSpaceZEdit, 3, 2);

	connect(nameEdit, SIGNAL(textEdited(QString)), SLOT(editName(QString)));
	connect(ratEdit, SIGNAL(textEdited(QString)), SLOT(editRat(QString)));
	connect(mrtEdit, SIGNAL(textEdited(QString)), SLOT(editMrt(QString)));
	connect(pmpEdit, SIGNAL(textEdited(QString)), SLOT(editPmp(QString)));
	connect(pmdEdit, SIGNAL(textEdited(QString)), SLOT(editPmd(QString)));
	connect(pvpEdit, SIGNAL(textEdited(QString)), SLOT(editPvp(QString)));

	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(nameLbl, 0, 0);
	layout->addWidget(nameEdit, 0, 1);
	layout->addWidget(ratLbl, 1, 0);
	layout->addWidget(ratEdit, 1, 1);
	layout->addWidget(mrtLbl, 2, 0);
	layout->addWidget(mrtEdit, 2, 1);
	layout->addWidget(pmpLbl, 3, 0);
	layout->addWidget(pmpEdit, 3, 1);
	layout->addWidget(pmdLbl, 4, 0);
	layout->addWidget(pmdEdit, 4, 1);
	layout->addWidget(pvpLbl, 5, 0);
	layout->addWidget(pvpEdit, 5, 1);
	layout->addWidget(gateList, 6, 0, 1, 2, Qt::AlignLeft);
	layout->addLayout(caLayout, 7, 0, 1, 2);
	layout->setRowStretch(8, 1);
	layout->setColumnStretch(1, 1);
	layout->setContentsMargins(QMargins());

	PageWidget::build();
}

void MiscWidget::clear()
{
	if(!isBuilded())	return;

	miscFile = NULL;
	nameEdit->clear();
	ratEdit->clear();
	mrtEdit->clear();
	pmpEdit->clear();
	pmdEdit->clear();
	pvpEdit->clear();
	gateList->clear();
	PageWidget::clear();
}

//bool MiscWidget::filled()
//{
//	return miscFile!=NULL;
//}

void MiscWidget::setReadOnly(bool readOnly)
{
	if(isBuilded()) {
		nameEdit->setReadOnly(readOnly);
		ratEdit->setReadOnly(readOnly);
		mrtEdit->setReadOnly(readOnly);
		pmpEdit->setReadOnly(readOnly);
		pmdEdit->setReadOnly(readOnly);
		pvpEdit->setReadOnly(readOnly);
	}

	PageWidget::setReadOnly(readOnly);
}

void MiscWidget::fill(MiscFile *miscFile, WalkmeshFile *walkmeshFile)
{
	PageWidget::fill();

	this->miscFile = miscFile;
	this->walkmeshFile = walkmeshFile;
	nameEdit->setText(miscFile->getMapName());
	ratEdit->setText(miscFile->getRatData().toHex());
	mrtEdit->setText(miscFile->getMrtData().toHex());
	pmpEdit->setText(miscFile->getPmpData().toHex());
	pmdEdit->setText(miscFile->getPmdData().toHex());
	pvpEdit->setText(miscFile->getPvpData().toHex());
	gateList->clear();
	foreach(quint16 mapId, miscFile->getGateways()) {
		gateList->addItem(QString::number(mapId));
	}

	if(walkmeshFile != NULL) {
		caVectorX1Edit->setValue(walkmeshFile->camAxis(0).x);
		caVectorX2Edit->setValue(walkmeshFile->camAxis(0).y);
		caVectorX3Edit->setValue(walkmeshFile->camAxis(0).z);
		caVectorY1Edit->setValue(walkmeshFile->camAxis(1).x);
		caVectorY2Edit->setValue(walkmeshFile->camAxis(1).y);
		caVectorY3Edit->setValue(walkmeshFile->camAxis(1).z);
		caVectorZ1Edit->setValue(walkmeshFile->camAxis(2).x);
		caVectorZ2Edit->setValue(walkmeshFile->camAxis(2).y);
		caVectorZ3Edit->setValue(walkmeshFile->camAxis(2).z);

		caSpaceXEdit->setValue(walkmeshFile->camPos(0));
		caSpaceYEdit->setValue(walkmeshFile->camPos(1));
		caSpaceZEdit->setValue(walkmeshFile->camPos(2));
	}
}

void MiscWidget::editName(const QString &name)
{
	miscFile->setMapName(name);
	emit modified(true);
}

void MiscWidget::editRat(const QString &rat)
{
	miscFile->setRatData(QByteArray::fromHex(rat.toLatin1()).leftJustified(miscFile->getRatData().size(), '\x00', true));
	emit modified(true);
	ratEdit->setText(miscFile->getRatData().toHex());
}

void MiscWidget::editMrt(const QString &mrt)
{
	miscFile->setMrtData(QByteArray::fromHex(mrt.toLatin1()).leftJustified(miscFile->getMrtData().size(), '\x00', true));
	emit modified(true);
	mrtEdit->setText(miscFile->getMrtData().toHex());
}

void MiscWidget::editPmp(const QString &pmp)
{
	miscFile->setPmpData(QByteArray::fromHex(pmp.toLatin1()).leftJustified(miscFile->getPmpData().size(), '\x00', true));
	emit modified(true);
	pmpEdit->setText(miscFile->getPmpData().toHex());
}

void MiscWidget::editPmd(const QString &pmd)
{
	miscFile->setPmdData(QByteArray::fromHex(pmd.toLatin1()).leftJustified(miscFile->getPmdData().size(), '\x00', true));
	emit modified(true);
	pmdEdit->setText(miscFile->getPmdData().toHex());
}

void MiscWidget::editPvp(const QString &pvp)
{
	miscFile->setPvpData(QByteArray::fromHex(pvp.toLatin1()).leftJustified(miscFile->getPvpData().size(), '\x00', true));
	emit modified(true);
	pvpEdit->setText(miscFile->getPvpData().toHex());
}

void MiscWidget::editCaVector(int value)
{
	QObject *s = sender();

	if(s == caVectorX1Edit)			editCaVector(0, 0, value);
	else if(s == caVectorX2Edit)	editCaVector(0, 1, value);
	else if(s == caVectorX3Edit)	editCaVector(0, 2, value);
	else if(s == caVectorY1Edit)	editCaVector(1, 0, value);
	else if(s == caVectorY2Edit)	editCaVector(1, 1, value);
	else if(s == caVectorY3Edit)	editCaVector(1, 2, value);
	else if(s == caVectorZ1Edit)	editCaVector(2, 0, value);
	else if(s == caVectorZ2Edit)	editCaVector(2, 1, value);
	else if(s == caVectorZ3Edit)	editCaVector(2, 2, value);
}

void MiscWidget::editCaVector(int id, int id2, int value)
{
	if(walkmeshFile != NULL) {
		Vertex_s v = walkmeshFile->camAxis(id), oldV;
		oldV = v;
		switch(id2) {
		case 0:
			v.x = value;
			break;
		case 1:
			v.y = value;
			break;
		case 2:
			v.z = value;
			break;
		}
		if(oldV.x != v.x || oldV.y != v.y || oldV.z != v.z) {
			walkmeshFile->setCamAxis(id, v);
			emit modified(true);
		}
	}
}

void MiscWidget::editCaPos(double value)
{
	QObject *s = sender();

	if(s == caSpaceXEdit)			editCaPos(0, value);
	else if(s == caSpaceYEdit)		editCaPos(1, value);
	else if(s == caSpaceZEdit)		editCaPos(2, value);
}

void MiscWidget::editCaPos(int id, int value)
{
	if(walkmeshFile != NULL) {
		if(walkmeshFile->camPos(id) != value) {
			walkmeshFile->setCamPos(id, value);
			emit modified(true);
		}
	}
}