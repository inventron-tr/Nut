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

#ifndef NUT_QUERY_P_H
#define NUT_QUERY_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of qapplication_*.cpp, qwidget*.cpp and qfiledialog.cpp.  This header
// file may change from version to version without notice, or even be removed.
//
// We mean it.
//

#include "phrase.h"

#include <QtCore/QList>
#include <QtCore/QString>
#include <QtCore/QSharedData>

NUT_BEGIN_NAMESPACE

class Database;
class AbstractTableSet;
class AbstractQuery;
struct RelationModel;
class NUT_EXPORT AbstractQueryPrivate {
    AbstractQuery *q_ptr;
    Q_DECLARE_PUBLIC(AbstractQuery)

public:
    explicit AbstractQueryPrivate(AbstractQuery *parent);
    ~AbstractQueryPrivate();

    QString sql;
    QString className;
    QString tableName;
    QString select;
    Database *database;
    AbstractTableSet *tableSet;
    QStringList joins;
    QList<RelationModel*> relations;
    int skip;
    int take;
    PhraseList orderPhrase, fieldPhrase;
    ConditionalPhrase wherePhrase;
};

NUT_END_NAMESPACE

#endif // NUT_QUERY_P_H
