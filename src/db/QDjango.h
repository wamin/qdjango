/*
 * Copyright (C) 2010-2012 Jeremy Lainé
 * Contact: http://code.google.com/p/qdjango/
 *
 * This file is part of the QDjango Library.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QDJANGO_H
#define QDJANGO_H

#include "QDjango_p.h"

class QObject;
class QSqlDatabase;
class QSqlQuery;
class QString;

class QDjangoMetaModel;

/** \defgroup Database
 *
 * QDjango's Object Relation Mapper (ORM) strives to be both powerful
 * and simple to use. Where possible it tries to follow django's
 * ORM API, with a similar lazy queryset mechanism.
 */

/** \brief The QDjango class provides a set of static functions.
 *
 *  It is used to access registered QDjangoModel classes.
 *
 * \ingroup Database
 */
class QDJANGO_EXPORT QDjango
{
public:
    static bool createTables();
    static bool dropTables();

    static QSqlDatabase database();
    static void setDatabase(QSqlDatabase database);

    static bool isDebugEnabled();
    static void setDebugEnabled(bool enabled);

    template <class T>
    static QDjangoMetaModel registerModel();

private:
    // backend specific
    static QString noLimitSql();

    static QDjangoMetaModel registerModel(const QObject *model);
    static QDjangoMetaModel metaModel(const QString &name);

    friend class QDjangoCompiler;
    friend class QDjangoModel;
    friend class QDjangoMetaModel;
    friend class QDjangoQuerySetPrivate;
};

/** Register a QDjangoModel class with QDjango.
 */
template <class T>
QDjangoMetaModel QDjango::registerModel()
{
    T model;
    return registerModel(&model);
}

#endif
