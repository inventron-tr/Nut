#include "querybase_p.h"

#include "table.h"
#include "abstracttableset.h"


NUT_BEGIN_NAMESPACE

QueryBase::QueryBase(QObject *parent) : QObject(parent)
{

}

//void QueryBase::addTableToSet(AbstractTableSet *set, Table *table)
//{
//    set->add(table);
//}

NUT_END_NAMESPACE
