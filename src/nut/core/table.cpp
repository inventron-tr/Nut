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

#include <QtCore/QMetaMethod>
#include <QtCore/QVariant>
#include <QtSql/QSqlQuery>

#include "table.h"
#include "table_p.h"
#include "database.h"
#include "databasemodel.h"
#include "abstractsqlgenerator.h"
#include "abstracttableset.h"
#include "propertysignalmapper.h"

QT_BEGIN_NAMESPACE

NUT_BEGIN_NAMESPACE

/*
 * FIXME:
 *  Qt can not access metaObject inside of constructor
 *  so, if we can't initalize myModel inside of ctor. in
 *  other side myModel inited in propertyChanged signal, so
 *  any method that uses myModel (like: primaryKey, ...) can't
 *  be accessed before any property set. So ugly, but there are
 *  no other way for now.
 *
 *  This should be fixed to v1.2
 */

/*!
  * \class Table
  * \brief Base class for all tables
  */
Table::Table(QObject *parent) : QObject(parent),
    d(new TablePrivate)
{ }

Table::~Table()
{
    //Q_D(Table);

//    if (d->parentTableSet)
//        d->parentTableSet->remove(this);
}

void Table::add(AbstractTableSet *t)
{
    //Q_D(Table);
    d->childTableSets.insert(t);
}

//QString Table::primaryKey() const
//{
//    //Q_D(const Table);
//    return d->model->primaryKey();
//}

//bool Table::isPrimaryKeyAutoIncrement() const
//{
//    //Q_D(const Table);
//    FieldModel *pk = d->model->field(d->model->primaryKey());
//    if (!pk)
//        return false;
//    return pk->isAutoIncrement;
//}


//QVariant Table::primaryValue() const
//{
//    return property(primaryKey().toLatin1().data());
//}

void Table::propertyChanged(const QString &propName)
{
    d.detach();
    d->changedProperties.insert(propName);
    if (d->status == FetchedFromDB)
        d->status = Modified;

    if (d->status == NewCreated)
        d->status = Added;
}

void Table::setModel(TableModel *model)
{
    //Q_D(Table);
    d->model = model;
}

void Table::clear()
{
    //Q_D(Table);
    d->changedProperties.clear();
}

const QSet<QString> &Table::changedProperties() const
{
    //Q_D(const Table);
    return d->changedProperties;
}

bool Table::setParentTable(Table *master, TableModel *masterModel, TableModel *model)
{
    //Q_D(Table);
    d.detach();

    QString masterClassName = QString::fromUtf8(master->metaObject()->className());
    d->refreshModel();

//    if (!d->model)
//        d->model = TableModel::findByClassName(metaObject()->className());

    for (auto &r: model->foreignKeys())
        if(r->masterClassName == masterClassName)
        {
            setProperty(QString(r->localColumn).toLatin1().data(),
                        master->property(masterModel->primaryKey().toUtf8().data()));
            d->changedProperties.insert(r->localColumn);
            return true;
        }

    return false;
}

void Table::propertyChanged()
{
    auto pname = PropertySignalMapper::changedProperty(this, senderSignalIndex());
    propertyChanged(pname);
}

void Table::init()
{
    PropertySignalMapper::map(this);
}

AbstractTableSet *Table::parentTableSet() const
{
    //Q_D(const Table);
    return d->parentTableSet;
}

void Table::setParentTableSet(AbstractTableSet *parent)
{
    //Q_D(Table);
    d->parentTableSet = parent;

//    if (parent)
//        d->parentTableSet->add(this);
}

AbstractTableSet *Table::childTableSet(const QString &name) const
{
    //Q_D(const Table);
    for (auto &t: qAsConst(d->childTableSets))
        if (t->childClassName() == name)
            return t;
    return Q_NULLPTR;
}

int Table::save(Database *db)
{
    //Q_D(Table);
    QSqlQuery q = db->exec(db->sqlGenerator()->saveRecord(this, db->tableName(QString::fromUtf8(metaObject()->className()))));

    auto model = db->model().tableByClassName(QString::fromUtf8(metaObject()->className()));
    if(status() == Added && model->isPrimaryKeyAutoIncrement())
        setProperty(model->primaryKey().toLatin1().data(), q.lastInsertId());

    if(d->status != Deleted)
        foreach(AbstractTableSet *ts, d->childTableSets) {
            ts->save(db);
        }
    setStatus(FetchedFromDB);

    return q.numRowsAffected();
}

Table::Status Table::status() const
{
    //Q_D(const Table);
    return static_cast<Status>(d->status);
}

void Table::setStatus(const Status &status)
{
    //Q_D(Table);
    d->status = status;
}



TablePrivate::TablePrivate() : QSharedData(),
    model(nullptr), status(Table::NewCreated), parentTableSet(nullptr)
{

}

void TablePrivate::refreshModel()
{
//    Q_Q(Table);
//    if (!model)
//        model = TableModel::findByClassName(q->metaObject()->className());
}

NUT_END_NAMESPACE

QT_END_NAMESPACE
