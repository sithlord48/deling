/****************************************************************************
 ** Deling Final Fantasy VIII Field Editor
 ** Copyright (C) 2009-2012 Arzel J�r�me <myst6re@gmail.com>
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
#include "widgets/BackgroundWidget.h"

BackgroundWidget::BackgroundWidget(QWidget *parent)
	: PageWidget(parent)
{
}

void BackgroundWidget::build()
{
	if(isBuilded())	return;

	QScrollArea *scrollArea = new QScrollArea(this);
	scrollArea->setWidgetResizable(true);

	QPalette pal = scrollArea->palette();
	pal.setColor(QPalette::Active, QPalette::Window, Qt::black);
	pal.setColor(QPalette::Inactive, QPalette::Window, Qt::black);
	pal.setColor(QPalette::Disabled, QPalette::Window, pal.color(QPalette::Disabled, QPalette::Text));
	scrollArea->setPalette(pal);

	image = new BGPreview2();
	image->setAlignment(Qt::AlignCenter);
	scrollArea->setWidget(image);

	parametersWidget = new QComboBox(this);
	parametersWidget->setMinimumWidth(150);
	parametersWidget->setEnabled(false);
	statesWidget = new QListWidget(this);
	statesWidget->setFixedWidth(150);
	layersWidget = new QListWidget(this);
	layersWidget->setFixedWidth(150);

	hideBack = new QCheckBox(tr("Cacher background"), this);
	hideBack->setChecked(false);

	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(scrollArea, 0, 0, 4, 1);
	layout->addWidget(parametersWidget, 0, 1);
	layout->addWidget(statesWidget, 1, 1);
	layout->addWidget(layersWidget, 2, 1);
	layout->addWidget(hideBack, 3, 1);
	layout->setContentsMargins(QMargins());

	connect(parametersWidget, SIGNAL(currentIndexChanged(int)), SLOT(parameterChanged(int)));
	connect(statesWidget, SIGNAL(itemChanged(QListWidgetItem*)), SLOT(enableState(QListWidgetItem*)));
	connect(layersWidget, SIGNAL(itemChanged(QListWidgetItem*)), SLOT(enableLayer(QListWidgetItem*)));
//	connect(statesWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(switchItem(QListWidgetItem*)));
//	connect(layersWidget, SIGNAL(itemClicked(QListWidgetItem*)), SLOT(switchItem(QListWidgetItem*)));
	connect(hideBack, SIGNAL(toggled(bool)), SLOT(setHideBack(bool)));

	PageWidget::build();
}

void BackgroundWidget::clear()
{
	if(!isFilled())	return;

	parametersWidget->clear();
	statesWidget->clear();
	layersWidget->clear();
	image->clear();

	PageWidget::clear();
}

void BackgroundWidget::parameterChanged(int index)
{
	if(!hasData() || !data()->hasBackgroundFile())		return;

	int parameter = parametersWidget->itemData(index).toInt();
	QList<quint8> states = data()->getBackgroundFile()->allparams.values(parameter);
	qSort(states);
	QListWidgetItem *item;

	statesWidget->clear();
	foreach(quint8 state, states)
	{
		item = new QListWidgetItem(tr("�tat %1").arg(state));
		item->setData(Qt::UserRole, state);
		item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
		item->setCheckState(data()->getBackgroundFile()->params.contains(parameter, state) ? Qt::Checked : Qt::Unchecked);
		statesWidget->addItem(item);
	}
}

void BackgroundWidget::enableState(QListWidgetItem *item)
{
	if(!hasData() || !data()->hasBackgroundFile())		return;

	bool enabled = item->data(Qt::CheckStateRole).toBool();
	int parameter = parametersWidget->itemData(parametersWidget->currentIndex()).toInt(), state = item->data(Qt::UserRole).toInt();

	if(enabled)
		data()->getBackgroundFile()->params.insert(parameter, state);
	else
		data()->getBackgroundFile()->params.remove(parameter, state);

	updateBackground();
}

void BackgroundWidget::enableLayer(QListWidgetItem *item)
{
	if(!hasData() || !data()->hasBackgroundFile())		return;

	bool enabled = item->data(Qt::CheckStateRole).toBool();
	int layer = item->data(Qt::UserRole).toInt();

	data()->getBackgroundFile()->layers.insert(layer, enabled);

	updateBackground();
}

/*void BackgroundWidget::switchItem(QListWidgetItem *item)
{
	item->setCheckState(item->checkState()==Qt::Unchecked ? Qt::Checked : Qt::Unchecked);
}*/

void BackgroundWidget::setHideBack(bool)
{
	if(!hasData() || !data()->hasBackgroundFile())		return;

	updateBackground();
}

void BackgroundWidget::updateBackground()
{
	image->setPixmap(QPixmap::fromImage(data()->getBackgroundFile()->background(hideBack->isChecked())));
}

void BackgroundWidget::fill()
{
	if(!isBuilded())	build();
	if(isFilled())		clear();

	if(!hasData() || !data()->hasBackgroundFile())		return;

	image->setName(data()->name());
	updateBackground();

	parametersWidget->clear();
	QList<quint8> parameters = data()->getBackgroundFile()->allparams.uniqueKeys();
	foreach(quint8 parameter, parameters)
		parametersWidget->addItem(tr("Param�tre %1").arg(parameter), parameter);

	QList<quint8> layerIDs = data()->getBackgroundFile()->layers.keys();
	QListWidgetItem *item;

	layersWidget->clear();
	foreach(quint8 layerID, layerIDs)
	{
		item = new QListWidgetItem(tr("Couche %1").arg(layerID));
		item->setData(Qt::UserRole, layerID);
		item->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
		item->setCheckState(data()->getBackgroundFile()->layers.value(layerID, false) ? Qt::Checked : Qt::Unchecked);
		layersWidget->addItem(item);
	}

	layersWidget->setEnabled(layersWidget->count()>0);
	parametersWidget->setEnabled(parametersWidget->count()>1);
	statesWidget->setEnabled(parametersWidget->count()>0);
	hideBack->setEnabled(parametersWidget->count()>0);
	hideBack->setChecked(false);

	PageWidget::fill();
}
