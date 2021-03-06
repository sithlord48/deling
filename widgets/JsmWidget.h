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
#ifndef JSMWIDGET_H
#define JSMWIDGET_H

#include <QtGui>
#include "widgets/PageWidget.h"
#include "widgets/CharaPreview.h"
#include "JsmHighlighter.h"
#include "PlainTextEdit.h"
#include "CharaModel.h"

class JsmWidget : public PageWidget
{
    Q_OBJECT
public:
	explicit JsmWidget(QWidget *parent = 0);
	void build();
	void clear();
	void setReadOnly(bool readOnly);
	void setData(Field *field);
	void setMainModels(QHash<int, CharaModel *> *mainModels);
	void fill();
	void gotoScript(int, int, int);
	int selectedOpcode();
	inline QString tabName() const { return tr("Scripts"); }
private:
	void saveSession();
	QList<QTreeWidgetItem *> nameList() const;
	QList<QTreeWidgetItem *> methodList(int groupID) const;
	QHash<int, CharaModel *> *mainModels;
	QTreeWidget *list1;
	CharaPreview *modelPreview;
	QTreeWidget *list2;
	QPlainTextEdit *textEdit;
	QToolBar *toolBar;
	QLabel *errorLabel;
	static int currentItem(QTreeWidget *);
//	void gotoScriptLabel(int groupID, int labelID);
	int groupID, methodID;
private slots:
	void compile();
	void fillList2();
	void fillTextEdit();
//	void jump(QTreeWidgetItem *);
};

#endif // JSMWIDGET_H
