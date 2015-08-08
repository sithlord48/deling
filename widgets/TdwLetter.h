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
#ifndef TDWLETTER_H
#define TDWLETTER_H

#include <QtWidgets>
#include "widgets/TdwDisplay.h"
#include "widgets/TdwGrid.h"

#define PIXEL_SIZE	21

class TdwLetter : public TdwDisplay
{
	Q_OBJECT
public:
	explicit TdwLetter(QWidget *parent=0);
	virtual ~TdwLetter();
	void setReadOnly(bool ro);
	virtual void setTdwFile(TdwFile *tdwFile);
public slots:
	virtual void setLetter(int letter);
	void setPixelIndex(int index);
	void reset();
signals:
	void imageChanged(const QRect &rect);
protected:
	virtual QSize sizeHint() const;
	virtual QSize minimumSizeHint() const;
	virtual void paintEvent(QPaintEvent *e);
	virtual void mouseMoveEvent(QMouseEvent *e);
	virtual void mousePressEvent(QMouseEvent *e);
	virtual void mouseReleaseEvent(QMouseEvent *);
private:
	QPoint getPixel(const QPoint &pos);
	bool setPixel(const QPoint &pixel);
	QImage copyLetter;
	int _pixelIndex;
	bool readOnly, startDrag, startDrag2;
};

#endif // TDWLETTER_H
