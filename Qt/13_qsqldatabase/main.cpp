#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

int main()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("communes.db");
    if (!db.open())
        exit(EXIT_FAILURE);
    QSqlQuery query("SELECT * FROM communes WHERE dep='33'");
    while (query.next())
        qDebug() << query.value("libelle").toString();
}
