#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

int main()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("communes-01042019.db");
    if (!db.open())
        exit(EXIT_FAILURE);
    QSqlQuery query(R"(SELECT * FROM communes WHERE dep="33")");
    while (query.next())
        qDebug() << query.value("libelle").toString();
}
