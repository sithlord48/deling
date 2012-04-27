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
#include "Config.h"

QSettings *Config::settings = 0;

void Config::set() {
	if(!settings)
		settings = new QSettings(qApp->applicationDirPath()%"/"%PROG_NAME%".ini", QSettings::IniFormat);
}

void Config::remove() {
	if(settings)
		delete settings;
}

QVariant Config::value(const QString &key, const QVariant &defaultValue)
{
	return settings->value(key, defaultValue);
}

void Config::setValue(const QString &key, const QVariant &value)
{
	settings->setValue(key, value);
}
