/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2017 Deepin, Inc.
 *               2011 ~ 2017 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */ 

#ifndef LISTPAGE_H
#define LISTPAGE_H

#include <QVBoxLayout>
#include "dimagebutton.h"
#include "file_view.h"
#include "waveform.h"

#include <QMediaPlayer>
#include <QAudioProbe>

DWIDGET_USE_NAMESPACE

class ListPage : public QWidget
{
    Q_OBJECT
    
public:
    ListPage(QWidget *parent = 0);
    DImageButton *recordButton;
    QVBoxLayout *layout;
                       
    QString getPlayingFilepath();
    
public slots:
    void play(QString filepath);
    void pause(QString filepath);
    void resume(QString filepath);
    void stop(QString filepath);
    void renderLevel(const QAudioBuffer &buffer);
    void handleStateChanged(QMediaPlayer::State state);
    void selectItemWithPath(QString path);
    void handleClickRecordButton();
    
signals:
    void playFinished(QString filepath);
    void clickRecordButton();
    
private:    
    FileView *fileView;
    Waveform *waveform;
    QMediaPlayer *audioPlayer;
    QAudioProbe *audioProbe;
};

#endif
