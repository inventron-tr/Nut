#ifndef TABLE1_H
#define TABLE1_H

#include "table.h"

class SampleTable : public Nut::Table
{
    Q_OBJECT

    NUT_PRIMARY_AUTO_INCREMENT(id)
    NUT_DECLARE_FIELD(int, id, id, setId)

    NUT_DECLARE_FIELD(QString, name, name, setName)
    NUT_DECLARE_FIELD(QString, password, password, setPassword)

public:
    Q_INVOKABLE SampleTable(QObject *parent = Q_NULLPTR);

};

Q_DECLARE_METATYPE(SampleTable*)

#endif // TABLE1_H
