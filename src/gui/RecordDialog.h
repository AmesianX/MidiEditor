/*
 * MidiEditor
 * Copyright (C) 2010  Markus Schwenk
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef RECORDDIALOG_H_
#define RECORDDIALOG_H_

#include <QDialog>
#include <QMultiMap>

class MidiFile;
class MidiEvent;
class QCheckBox;
class QComboBox;
class QListWidget;

class RecordDialog : public QDialog {

	Q_OBJECT

	public:
		RecordDialog(MidiFile *file, QMultiMap<int, MidiEvent*> data,
				QWidget *parent = 0);

	public slots:
		void enter();
		void cancel();

	private:
		MidiFile *_file;
		QMultiMap<int, MidiEvent*> _data;
		QComboBox *_channelBox;
		QComboBox *_trackBox;
		QListWidget *addTypes;
		void addListItem(QListWidget *w, QString title, int line, bool enabled);

};

#endif
