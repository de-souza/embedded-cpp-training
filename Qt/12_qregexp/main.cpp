#include <QDirIterator>
#include <QDebug>

int main()
{
    QRegExp rx(".*\\.\\w{3}$");  // Match all files with an alphanumeric 3 char-long extension
    QDirIterator it(QDir::homePath(), QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        QString filename = it.next();
        if (rx.exactMatch(filename))
            qDebug() << filename;
    }
}
