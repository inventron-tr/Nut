#ifndef SQLMODEL_P_H
#define SQLMODEL_P_H

#include <QtCore/QSharedPointer>
#include <QtCore/QString>
#include "defines.h"

NUT_BEGIN_NAMESPACE

class SqlModel;
class Table;
class TableModel;
class NUT_EXPORT SqlModelPrivate : public QSharedData {
public:
    explicit SqlModelPrivate(SqlModel *parent);

    QString tableName;

    RowList<Table> rows;
    TableModel *model;
};

NUT_END_NAMESPACE

#endif // SQLMODEL_P_H
