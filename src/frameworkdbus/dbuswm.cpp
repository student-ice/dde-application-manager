//SPDX-FileCopyrightText: 2018 - 2023 UnionTech Software Technology Co., Ltd.
//
//SPDX-License-Identifier: GPL-3.0-or-later
/*
 * This file was generated by qdbusxml2cpp-fix version 0.8
 * Command line was: qdbusxml2cpp-fix -c wm -p generated/com_deepin_wm ../xml/com.deepin.wm.xml
 *
 * qdbusxml2cpp-fix is Copyright (C) 2016 Deepin Technology Co., Ltd.
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#include "dbuswm.h"

/*
 * Implementation of interface class __wm
 */

class __wmPrivate
{
public:
   __wmPrivate() = default;

    // begin member variables
    bool compositingAllowSwitch;
    bool compositingEnabled;
    bool compositingPossible;
    int cursorSize;
    QString cursorTheme;
    bool zoneEnabled;

public:
    QMap<QString, QDBusPendingCallWatcher *> m_processingCalls;
    QMap<QString, QList<QVariant>> m_waittingCalls;
};

__wm::__wm(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent)
    : DBusExtendedAbstractInterface(service, path, staticInterfaceName(), connection, parent)
    , d_ptr(new __wmPrivate)
{
    connect(this, &__wm::propertyChanged, this, &__wm::onPropertyChanged);

    if (QMetaType::type("QList<uint>") == QMetaType::UnknownType) {
        qRegisterMetaType< QList<uint> >("QList<uint>");
        qDBusRegisterMetaType< QList<uint> >();
    }
}

__wm::~__wm()
{
    qDeleteAll(d_ptr->m_processingCalls.values());
    delete d_ptr;
}

void __wm::onPropertyChanged(const QString &propName, const QVariant &value)
{
    if (propName == QStringLiteral("compositingAllowSwitch"))
    {
        const bool &compositingAllowSwitch = qvariant_cast<bool>(value);
        if (d_ptr->compositingAllowSwitch != compositingAllowSwitch)
        {
            d_ptr->compositingAllowSwitch = compositingAllowSwitch;
            Q_EMIT CompositingAllowSwitchChanged(d_ptr->compositingAllowSwitch);
        }
        return;
    }

    if (propName == QStringLiteral("compositingEnabled"))
    {
        const bool &compositingEnabled = qvariant_cast<bool>(value);
        if (d_ptr->compositingEnabled != compositingEnabled)
        {
            d_ptr->compositingEnabled = compositingEnabled;
            Q_EMIT CompositingEnabledChanged(d_ptr->compositingEnabled);
        }
        return;
    }

    if (propName == QStringLiteral("compositingPossible"))
    {
        const bool &compositingPossible = qvariant_cast<bool>(value);
        if (d_ptr->compositingPossible != compositingPossible)
        {
            d_ptr->compositingPossible = compositingPossible;
            Q_EMIT CompositingPossibleChanged(d_ptr->compositingPossible);
        }
        return;
    }

    if (propName == QStringLiteral("cursorSize"))
    {
        const int &cursorSize = qvariant_cast<int>(value);
        if (d_ptr->cursorSize != cursorSize)
        {
            d_ptr->cursorSize = cursorSize;
            Q_EMIT CursorSizeChanged(d_ptr->cursorSize);
        }
        return;
    }

    if (propName == QStringLiteral("cursorTheme"))
    {
        const QString &cursorTheme = qvariant_cast<QString>(value);
        if (d_ptr->cursorTheme != cursorTheme)
        {
            d_ptr->cursorTheme = cursorTheme;
            Q_EMIT CursorThemeChanged(d_ptr->cursorTheme);
        }
        return;
    }

    if (propName == QStringLiteral("zoneEnabled"))
    {
        const bool &zoneEnabled = qvariant_cast<bool>(value);
        if (d_ptr->zoneEnabled != zoneEnabled)
        {
            d_ptr->zoneEnabled = zoneEnabled;
            Q_EMIT ZoneEnabledChanged(d_ptr->zoneEnabled);
        }
        return;
    }

    qWarning() << "property not handle: " << propName;
    return;
}

bool __wm::compositingAllowSwitch()
{
    return qvariant_cast<bool>(internalPropGet("compositingAllowSwitch", &d_ptr->compositingAllowSwitch));
}

bool __wm::compositingEnabled()
{
    return qvariant_cast<bool>(internalPropGet("compositingEnabled", &d_ptr->compositingEnabled));
}

void __wm::setCompositingEnabled(bool value)
{

   internalPropSet("compositingEnabled", QVariant::fromValue(value), &d_ptr->compositingEnabled);
}

bool __wm::compositingPossible()
{
    return qvariant_cast<bool>(internalPropGet("compositingPossible", &d_ptr->compositingPossible));
}

int __wm::cursorSize()
{
    return qvariant_cast<int>(internalPropGet("cursorSize", &d_ptr->cursorSize));
}

void __wm::setCursorSize(int value)
{

   internalPropSet("cursorSize", QVariant::fromValue(value), &d_ptr->cursorSize);
}

QString __wm::cursorTheme()
{
    return qvariant_cast<QString>(internalPropGet("cursorTheme", &d_ptr->cursorTheme));
}

void __wm::setCursorTheme(const QString &value)
{

   internalPropSet("cursorTheme", QVariant::fromValue(value), &d_ptr->cursorTheme);
}

bool __wm::zoneEnabled()
{
    return qvariant_cast<bool>(internalPropGet("zoneEnabled", &d_ptr->zoneEnabled));
}

void __wm::setZoneEnabled(bool value)
{

   internalPropSet("zoneEnabled", QVariant::fromValue(value), &d_ptr->zoneEnabled);
}

void __wm::CallQueued(const QString &callName, const QList<QVariant> &args)
{
    if (d_ptr->m_waittingCalls.contains(callName))
    {
        d_ptr->m_waittingCalls[callName] = args;
        return;
    }
    if (d_ptr->m_processingCalls.contains(callName))
    {
        d_ptr->m_waittingCalls.insert(callName, args);
    } else {
        QDBusPendingCallWatcher *watcher = new QDBusPendingCallWatcher(asyncCallWithArgumentList(callName, args));
        connect(watcher, &QDBusPendingCallWatcher::finished, this, &__wm::onPendingCallFinished);
        d_ptr->m_processingCalls.insert(callName, watcher);
    }
}

void __wm::onPendingCallFinished(QDBusPendingCallWatcher *w)
{
    w->deleteLater();
    const auto callName = d_ptr->m_processingCalls.key(w);
    Q_ASSERT(!callName.isEmpty());
    if (callName.isEmpty())
        return;
    d_ptr->m_processingCalls.remove(callName);
    if (!d_ptr->m_waittingCalls.contains(callName))
        return;
    const auto args = d_ptr->m_waittingCalls.take(callName);
    CallQueued(callName, args);
}
