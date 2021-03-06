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
#ifndef MSDFILE_H
#define MSDFILE_H

#include "files/File.h"
#include "FF8Text.h"
#include "Data.h"

class MsdFile : public File
{
public:
	MsdFile();
	bool open(const QByteArray &msd);
	bool save(QByteArray &msd);
	inline QString filterText() const {
		return QObject::tr("Fichier dialogues �cran PC (*.msd)");
	}
	QByteArray data(int id) const;
	FF8Text text(int) const;
	void setText(int, const FF8Text &);
	void insertText(int);
	void removeText(int);
	int nbText() const;
	bool hasText(const QRegExp &txt) const;
	int indexOfText(const QRegExp &txt, int from = 0) const;
	bool searchText(const QRegExp &txt, int &textID, int &from, int &size) const;
	bool searchTextReverse(const QRegExp &txt, int &textID, int &from, int &index, int &size) const;
	bool isJp() const;
private:
	QList<QByteArray> texts;
	QList<bool> needEndOfString;
};

#endif // MSDFILE_H
