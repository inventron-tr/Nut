#ifndef BULKINSERTER_P_H
#define BULKINSERTER_P_H

#include <QtNut/phraselist.h>

NUT_BEGIN_NAMESPACE

class Database;
class BulkInserterPrivate
{
public:
    BulkInserterPrivate(Database *db);

    Database *database;
    QString className;
    PhraseList fields;
    QList<QVariantList> variants;
    size_t fieldCount;
};

NUT_END_NAMESPACE

#endif // BULKINSERTER_P_H
