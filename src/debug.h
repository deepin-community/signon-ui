/*
 * This file is part of signon-ui
 *
 * Copyright (C) 2011 Canonical Ltd.
 *
 * Contact: Alberto Mardegan <alberto.mardegan@canonical.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SIGNON_UI_DEBUG_H
#define SIGNON_UI_DEBUG_H

#include <QDebug>

/* 0 - fatal, 1 - critical(default), 2 - info/debug */
extern int appLoggingLevel;

static inline bool debugEnabled()
{
    return appLoggingLevel >= 2;
}

static inline bool criticalsEnabled()
{
    return appLoggingLevel >= 1;
}

static inline int loggingLevel()
{
    return appLoggingLevel;
}

void setLoggingLevel(int level);

#ifdef DEBUG_ENABLED
    #define TRACE() \
        if (debugEnabled()) qDebug() << __FILE__ << __LINE__ << __func__
    #define BLAME() \
        if (criticalsEnabled()) qCritical() << __FILE__ << __LINE__ << __func__
#else
    #define TRACE() while (0) qDebug()
    #define BLAME() while (0) qDebug()
#endif

#endif // SIGNON_UI_DEBUG_H

