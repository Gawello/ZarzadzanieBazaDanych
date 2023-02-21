#include "mainwindow.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

bool connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("localhost");               // adres hosta
    db.setDatabaseName("nazwa_bazy_danych");   // nazwa bazy danych
    db.setUserName("uzytkownik");              // nazwa użytkownika
    db.setPassword("haslo");                   // hasło użytkownika
    db.setPort(1433);                          // numer portu (domyślnie 1433)

    if (!db.open()) {
        qDebug() << "Nie udało się połączyć z bazą danych. Powód: " << db.lastError().text();
        return false;
    }

    qDebug() << "Połączenie z bazą danych zostało ustanowione.";

    return true;
}
