/****************************************************************************
 **
 ** Copyright (C) 2010 Arzel J�r�me <myst6re@gmail.com>
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
#include "MiscSearch.h"

MiscSearch::MiscSearch(FieldArchive *fieldArchive, QWidget *parent)
	: QDialog(parent, Qt::Tool), fieldArchive(fieldArchive)
{
	setWindowTitle(tr("Rechercher tout"));
	setWindowModality(Qt::NonModal);
	QFont font;
	font.setPointSize(8);

	list = new QListWidget(this);
	list->setFont(font);
	list->setUniformItemSizes(true);

	textEdit = new QPlainTextEdit(this);
	textEdit->setReadOnly(true);

	QGridLayout *layout = new QGridLayout(this);
	layout->addWidget(list, 0, 0);
	layout->addWidget(textEdit, 0, 1);

	fillList();

	connect(list, SIGNAL(currentRowChanged(int)), SLOT(search(int)));
}

void MiscSearch::fillList()
{
	if(fieldArchive==NULL)	return;

	list->clear();
	list->addItems(fieldArchive->fieldList());
//	QMap<int, QStringList> spells;
//	for(int i=0 ; i<list->count() ; ++i) {
//		QList<int> spellsId = fieldArchive->searchAllSpells(i);
//		foreach(int id, spellsId) {
//			QStringList curList = spells.value(id, QStringList());
//			Field *f = fieldArchive->getField(i);
//			if(f == NULL)	continue;
//			if(f->hasJsmFile()) {
//				curList.append(f->getJsmFile()->mapID() != -1 ? QString::number(f->getJsmFile()->mapID()) : f->name());
//			} else {
//				curList.append(f->name());
//			}
//			spells.insert(id, curList);
//		}
//	}
//	QString text;
//	QMapIterator<int, QStringList> it(spells);
//	int h=0, lastKey=1;
//	while(it.hasNext()) {
//		it.next();
//		if(h % 16 == 0) {
//			text.append("\n");
//		}
//		while(lastKey+1 < it.key()) {
//			text.append(QString("-1, "));
//			lastKey++;
//			h++;
//			if(h % 16 == 0) {
//				text.append("\n");
//			}
//		}
//		QString t;
//		foreach(const QString &map, it.value()) {
//			t.append(map).append("/");
//		}
//		t.chop(1);
//		text.append(QString("%1, ").arg(t));
//		lastKey = it.key();
//		h++;
//	}
//	textEdit->setPlainText(text);
//	qDebug() << "magies" << spells.size();

	QString text;
//	QMap<Field *, QList<int> > battles = fieldArchive->searchAllBattles();
//	QMapIterator<Field *, QList<int> > i(battles);
//	while(i.hasNext()) {
//		i.next();
//		if(!i.value().isEmpty()) {
//			text.append(QString("%1 -> ").arg(i.key()->name()));
//			foreach(int battleID, i.value()) {
//				text.append(QString("[%1] | ").arg(battleID));
//			}
//			text.chop(3);
//			text.append("\n");
//		}
//	}

//	int moment=-1, j=0;
//	QMultiMap<int, Field *> moments = fieldArchive->searchAllMoments();
//	QMapIterator<int, Field * > i(moments);
//	while(i.hasNext()) {
//		i.next();

//		if(moment == i.key())	continue;

//		moment = i.key();

//		int mapId = getMapId(moments.values(moment));

//		text.append(QString("cInt(%1, %2), ").arg(moment).arg(mapId==-1 ? moments.values(moment).last()->name() : QString::number(mapId)));

//		if(++j % 16 == 0) {
//			text.append("\n");
//		}

		/*if(moment != i.key()) {
			if(moment != -1) {
				text.chop(2);
				text.append("\");\n");
			}
			text.append(QString("gameMoments[%1] = tr(\"").arg(moment = i.key()));
		}

		text.append(QString("%1, ").arg(i.value()->getJsmFile()->mapID() != -1 ? Data::locations().value(i.value()->getJsmFile()->mapID()) : i.value()->name()));
		*/
//	}

//	text.chop(2);
//	text.append("\");\n");

	QMap<int, int> opcodeTypes = fieldArchive->searchAllOpcodeTypes();
	for(int j=0 ; j<376 ; ++j) {
		if(!opcodeTypes.contains(j)) {
			qWarning() << QString::number(j, 16) << JsmFile::opcodeName.value(j, "???") << "introuvable";
		}
	}
	QMapIterator<int, int> i(opcodeTypes);
	while(i.hasNext()) {
		i.next();

		QString type;

		switch(i.value()) {
		case JUST_KEY:
			type = "Aucun param�tre";
			break;
		case KEY_AND_UPARAM:
			type = "Un param�tre";
			break;
		case KEY_AND_SPARAM:
			type = "Un param�tre (Sign� ?)";
			break;
		}

		text.append(QString("%1: %2\n").arg(JsmFile::opcodeName.value(i.key(), "???")).arg(type));
	}

//	qDebug() << "count" << moments.uniqueKeys().size();
	textEdit->setPlainText(text);

}

int MiscSearch::getMapId(QList<Field *> fields)
{
	foreach(Field *field, fields) {
		if(field->getJsmFile()->mapID() != -1)
			return field->getJsmFile()->mapID();
	}
	return -1;
}

void MiscSearch::search(int fieldID)
{
//	int count=0;
//	textEdit->setPlainText(fieldArchive->searchAllSpells(fieldID, count));
}