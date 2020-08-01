#ifndef DB1_H
#define DB1_H

#include "database.h"

class SampleTable;
class DB : public Nut::Database
{
    Q_OBJECT

    NUT_DB_VERSION(1)

    NUT_DECLARE_TABLE(SampleTable, users1)
    NUT_DECLARE_TABLE(SampleTable, users2)
    NUT_DECLARE_TABLE(SampleTable, users3)

public:
    DB();
};

Q_DECLARE_METATYPE(DB*)

#endif // DB1_H
