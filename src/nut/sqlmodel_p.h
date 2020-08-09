#ifndef SQLMODEL_P_H
#define SQLMODEL_P_H

#include <QtCore/QSharedPointer>
#include <QtCore/QString>

#include <functional>

#include <QtNut/defines.h>

NUT_BEGIN_NAMESPACE

class SqlModel;
class Table;
class TableModel;
class NUT_EXPORT SqlModelPrivate {
public:
    SqlModel *q_ptr;
    Q_DECLARE_PUBLIC(SqlModel);

    explicit SqlModelPrivate(SqlModel *parent);

    QString tableName;

    RowList<Table> rows;
    TableModel *model;
    std::function <QVariant(int, QVariant)> renderer;
};

NUT_END_NAMESPACE

#endif // SQLMODEL_P_H
