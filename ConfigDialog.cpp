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
#include "ConfigDialog.h"

ConfigDialog::ConfigDialog(QWidget *parent)
	: QDialog(parent, Qt::Dialog | Qt::WindowCloseButtonHint)
{
	setWindowTitle(tr("Configuration"));
	setSizeGripEnabled(true);

	QLabel *langLabel = new QLabel(tr("Langue"), this);
	langComboBox = new QComboBox(this);

	QLabel *appPathLabel = new QLabel(tr("Chemin de FF8"), this);
	useRegAppPath = new QCheckBox(tr("Auto"), this);
	appPathLine = new QLineEdit(this);
	QPushButton *appPathButton = new QPushButton(tr("Parcourir..."), this);
	QHBoxLayout *appPathLayout = new QHBoxLayout;
	appPathLayout->addWidget(useRegAppPath);
	appPathLayout->addWidget(appPathLine);
	appPathLayout->addWidget(appPathButton);

	QLabel *encodingLabel = new QLabel(tr("Encodage des textes"), this);
	encodingComboBox = new QComboBox(this);
	encodingComboBox->addItem(tr("Latin"), "00");
	encodingComboBox->addItem(tr("Japonais"), "01");
	QPushButton *encodingManage = new QPushButton(tr("G�rer"), this);
	QHBoxLayout *encodingLayout = new QHBoxLayout();
	encodingLayout->addWidget(encodingComboBox, 1);
	encodingLayout->addWidget(encodingManage);
	encodingLayout->setContentsMargins(QMargins());

//	hideUnusedTexts = new QCheckBox(tr("Cacher les textes inutilis�s"), this);

	QPushButton *okButton = new QPushButton(tr("Enregistrer"), this);
	okButton->setDefault(true);
	QPushButton *cancelButton = new QPushButton(tr("Annuler"), this);
	QHBoxLayout *buttonsLayout = new QHBoxLayout;
	buttonsLayout->addWidget(okButton);
	buttonsLayout->addWidget(cancelButton);
	buttonsLayout->setContentsMargins(QMargins());
	
	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(langLabel, 0, 0);
	layout->addWidget(langComboBox, 0, 1);
	layout->addWidget(appPathLabel, 1, 0);
	layout->addLayout(appPathLayout, 1, 1);
	layout->addWidget(encodingLabel, 2, 0);
	layout->addLayout(encodingLayout, 2, 1);
//	layout->addWidget(hideUnusedTexts, 3, 0, 1, 2);
	layout->addLayout(buttonsLayout, 4, 0, 1, 2, Qt::AlignRight);

	connect(useRegAppPath, SIGNAL(toggled(bool)), appPathLine, SLOT(setDisabled(bool)));
	connect(useRegAppPath, SIGNAL(toggled(bool)), appPathButton, SLOT(setDisabled(bool)));

	fillMenuLang();
	useRegAppPath->setChecked(!Config::value("dontUseRegAppPath").toBool());
	QString appPath = Config::value("appPath").toString();
	if(appPath.isEmpty()) {
		appPath = Data::AppPath();
	}
	appPathLine->setText(appPath);

	foreach(const QString &fontName, Data::fontList()) {
		if(fontName == "00" || fontName == "01")	continue;
		FF8Font *font = Data::font(fontName);
		if(font) {
			encodingComboBox->addItem(font->name(), fontName);
		}
	}

	int indexOfData;
	indexOfData = encodingComboBox->findData(Config::value("encoding", "00"));
	encodingComboBox->setCurrentIndex(indexOfData != -1 ? indexOfData : 0);
//	hideUnusedTexts->setChecked(Config::value("hideUnusedTexts").toBool());

	connect(encodingManage, SIGNAL(clicked()), SLOT(manageEncoding()));
	connect(appPathButton, SIGNAL(clicked()), SLOT(setAppPath()));
	connect(okButton, SIGNAL(clicked()), SLOT(saveConfig()));
	connect(cancelButton, SIGNAL(clicked()), SLOT(reject()));
}

void ConfigDialog::fillMenuLang()
{
	QDir dir(qApp->applicationDirPath());
	QStringList stringList = dir.entryList(QStringList("deling_*.qm"), QDir::Files, QDir::Name);
	langComboBox->addItem("Fran�ais");
	langComboBox->setItemData(0, "fr");

	QTranslator translator;
	int i=1;
	foreach(const QString &str, stringList) {
		translator.load(qApp->applicationDirPath()+"/"+str);
		langComboBox->addItem(translator.translate("MainWindow", "Fran�ais", "Your translation language"));
		langComboBox->setItemData(i++, str.right(5).left(2));
	}

	for(i=0 ; i<langComboBox->count() ; ++i) {
		if(Config::value("lang")==langComboBox->itemData(i)) {
			langComboBox->setCurrentIndex(i);
			break;
		}
	}
}

void ConfigDialog::setAppPath()
{
	QString appPath = QFileDialog::getExistingDirectory(this, tr("Chemin d'installation de Final Fantasy VIII PC"), Data::AppPath());
	if(!appPath.isNull()) {
		appPathLine->setText(appPath);
	}
}

void ConfigDialog::manageEncoding()
{
	TdwManagerDialog tdwManager(this);
	tdwManager.exec();
}

void ConfigDialog::restartNow()
{
	QString str_title, str_text;
	QTranslator translator;
	if(translator.load(qApp->applicationDirPath() % "/deling_" % Config::value("lang").toString())) {
		str_title = translator.translate("MainWindow", "Param�tres modifi�s");
		str_text = translator.translate("MainWindow", "Relancez le programme pour que les param�tres prennent effet.");
	}
	else {
		str_title = "Param�tres modifi�s";
		str_text = "Relancez le programme pour que les param�tres prennent effet.";
	}
	QMessageBox::information(this, str_title, str_text);
}

void ConfigDialog::saveConfig()
{
	QString oldLang = Config::value("lang").toString();

	Config::setValue("lang", langComboBox->itemData(langComboBox->currentIndex()));
	Config::setValue("dontUseRegAppPath", !useRegAppPath->isChecked());
	Config::setValue("appPath", appPathLine->text());
	Config::setValue("encoding", encodingComboBox->itemData(encodingComboBox->currentIndex()));
//	Config::setValue("hideUnusedTexts", hideUnusedTexts->isChecked());

	if(oldLang != Config::value("lang").toString()) {
		restartNow();
	}

	accept();
}
