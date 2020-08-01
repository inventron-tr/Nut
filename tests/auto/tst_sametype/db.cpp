#include "db.h"
#include "sampletable.h"

DB::DB() : Nut::Database()
      , m_users1(new Nut::TableSet<SampleTable>(this))
      , m_users2(new Nut::TableSet<SampleTable>(this))
      , m_users3(new Nut::TableSet<SampleTable>(this))
{

}
