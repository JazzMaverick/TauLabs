/**
 ******************************************************************************
 *
 * @file       mocapwidget.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010.
 *
 * @addtogroup GCSPlugins GCS Plugins
 * @{
 * @addtogroup MoCapPlugin Motion Capture Plugin
 * @{
 * @brief Motion capture plugin which communicates via UDP
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef MOCAPWIDGET_H
#define MOCAPWIDGET_H

#include <QWidget>
#include <QProcess>
#include "exporter.h"

class Ui_MoCapWidget;

class MoCapWidget : public QWidget
{
    Q_OBJECT

public:
    MoCapWidget(QWidget *parent = 0);
    ~MoCapWidget();

    void setSettingParameters(const MocapSettings& params) {settings = params;}
signals:
    void deleteExporter();

private slots:
    void startButtonClicked();
    void stopButtonClicked();
	void buttonClearLogClicked();
    void onProcessOutput(QString text);
    void onAutopilotConnect();
    void onAutopilotDisconnect();
    void onExporterConnect();
    void onExporterDisconnect();
    void ontrackablesComboBox_changed();

private:
    Ui_MoCapWidget* widget;
    Exporter* exporter;
    MocapSettings settings;

	QString greenColor;
	QString strAutopilotDisconnected;
    QString strExporterDisconnected;
	QString strAutopilotConnected;
    QString strStyleEnable;
    QString strStyleDisable;
};

#endif /* MOCAPWIDGET_H */
