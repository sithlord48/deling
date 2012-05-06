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
#ifndef TDWFILE_H
#define TDWFILE_H

#include <QtCore>
#include "FF8Image.h"

class TdwFile
{
public:
	TdwFile();
	bool open(const QByteArray &tdw);
	bool isModified();
	QPixmap image(int palID=0) const;
	static QPixmap image(const QByteArray &data, int palID=0);
	QImage letter(int charId, int fontColor, bool curFrame) const;
	quint8 *charWidth();
private:
	static QByteArray tim;
	bool modified;
	quint8 _charWidth[224];
};

#endif // TDWFILE_H