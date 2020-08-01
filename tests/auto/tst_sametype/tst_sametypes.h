#ifndef TST_UPGRADES_H
#define TST_UPGRADES_H

#include <QObject>
#include "db.h"


namespace Nut {
class Database;
template<class T>
class Query;
}
class SameTypes : public QObject
{
    Q_OBJECT

    DB db;

    void insertOnList(char no, const QString &password);
    QString readPassword(char no);
    Nut::Query<SampleTable> *query(int n);

public:
    SameTypes();
    ~SameTypes();

private slots:
    void initTestCase();

    void insert();
    void counts();
    void read();

};

#endif // TST_UPGRADES_H
