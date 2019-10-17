#include <QDirIterator>
#include <QDebug>

int main()
{
    QRegExp rx(".*\\.\\w{3}$");  // Match all files with an alphanumeric 3 char-long extension
    QDirIterator it(QDir::homePath(), QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
        if (rx.exactMatch(it.next()))
            qDebug() << it.filePath();
}
