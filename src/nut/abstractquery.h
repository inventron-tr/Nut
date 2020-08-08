/**************************************************************************
**
** This file is part of Nut project.
** https://github.com/HamedMasafi/Nut
**
** Nut is free software: you can redistribute it and/or modify
** it under the terms of the GNU Lesser General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** Nut is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU Lesser General Public License for more details.
**
** You should have received a copy of the GNU Lesser General Public License
** along with Nut.  If not, see <http://www.gnu.org/licenses/>.
**
**************************************************************************/

#ifndef NUT_ABSTRACTQUERY_H
#define NUT_ABSTRACTQUERY_H

#include <QtCore/QObject>
#include <QtCore/qglobal.h>
#include <QtCore/QExplicitlySharedDataPointer>

#include "defines.h"
#include "abstractquery_p.h"

NUT_BEGIN_NAMESPACE

class AbstractQueryPrivate;
class NUT_EXPORT AbstractQuery : public QObject
{
    Q_OBJECT

protected:
    AbstractQueryPrivate *d_ptr;
    Q_DECLARE_PRIVATE(AbstractQuery)

public:
    explicit AbstractQuery(QObject *parent = nullptr);

protected:
    //    void addTableToSet(TableSetBase *set, Table *table);

public slots:
};

NUT_END_NAMESPACE

#endif // NUT_ABSTRACTQUERY_H
