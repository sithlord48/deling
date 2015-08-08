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
#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QtWidgets>

class ListWidget : public QWidget
{
    Q_OBJECT
public:
    enum ActionType {
		Invisible, Add, Rem, Up, Down
    };

    explicit ListWidget(QWidget *parent = 0);
    QAction *addAction(ActionType type, const QString &text,
                       const QObject *receiver, const char *member);

    QToolBar *toolBar() const;
    QListWidget *listWidget() const;
signals:
    
public slots:
private:
    QToolBar *_toolBar;
    QListWidget *_listWidget;
};

#endif // LISTWIDGET_H
