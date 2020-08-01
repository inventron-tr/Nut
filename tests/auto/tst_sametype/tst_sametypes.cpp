#include <QtTest>

#include "db.h"
#include "sampletable.h"
#include "query.h"

#include "tst_sametypes.h"
#include "consts.h"

SameTypes::SameTypes()
{

}

SameTypes::~SameTypes()
{

}


void SameTypes::initTestCase()
{
    REGISTER(DB);
    REGISTER(SampleTable);

    db.setDriver(DRIVER);
    db.setHostName(HOST);
    db.setDatabaseName(DATABASE);
    db.setUserName(USERNAME);
    db.setPassword(PASSWORD);

    db.open();
}

void SameTypes::insert()
{
    insertOnList(1, "1");
    insertOnList(2, "2");
    insertOnList(3, "3");
}

void SameTypes::counts()
{
    for (int i = 1; i < 4; ++i) {
        auto t = query(i);

        QTEST_ASSERT(t != nullptr);
        QCOMPARE(t->toList().count(), 1);
    }
}

void SameTypes::read()
{
    QCOMPARE(readPassword(1), "1");
    QCOMPARE(readPassword(2), "2");
    QCOMPARE(readPassword(3), "3");
}

void SameTypes::insertOnList(char no, const QString &password)
{
    Nut::TableSet<SampleTable> *tableSet;

    switch (no) {
    case 1:
        tableSet = db.users1();
        break;

    case 2:
        tableSet = db.users2();
        break;

    case 3:
        tableSet = db.users3();
        break;

    default:
        return;
    }

    bool ok;
    auto q = tableSet->query();
    int n = q->insert((SampleTable::nameField() = "user")
                      & (SampleTable::passwordField() = password))
                .toInt(&ok);

    qDebug() << q->sqlCommand();
    QTEST_ASSERT(ok);

    QTEST_ASSERT(n != 0);
}

QString SameTypes::readPassword(char no)
{
    Nut::TableSet<SampleTable> *tableSet;

    switch (no) {
    case 1:
        tableSet = db.users1();
        break;

    case 2:
        tableSet = db.users2();
        break;

    case 3:
        tableSet = db.users3();
        break;

    default:
        return QString();
    }

    bool ok;
    auto q = tableSet->query();
    QStringList passwordList = q->where(SampleTable::nameField() == "user")
                                   ->select(SampleTable::passwordField());


    qDebug() << q->sqlCommand();
    QTEST_ASSERT(passwordList.size() == 1);

    return passwordList.first();
}

Nut::Query<SampleTable> *SameTypes::query(int n)
{
    switch (n) {
    case 1:
        return db.users1()->query();
        break;

    case 2:
        return db.users2()->query();
        break;

    case 3:
        return db.users3()->query();
        break;

    default:
        return nullptr;
    }
}



QTEST_APPLESS_MAIN(SameTypes)

