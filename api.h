#ifndef API_H
#define API_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonParseError>
#include <QDebug>


class API : public QObject
{
    Q_OBJECT

    QSqlQuery q;
    QJsonDocument jsonDocument;
    QJsonParseError jsonError;
    QNetworkAccessManager *manager;
    QVariantMap _requestData;
    QVariantMap _replyData;
    QString _host;

    bool tableNameError(const QString &tableName);
    bool operationNameError(const QString &operation);
    QByteArray variantMapToJson(QVariantMap &data);
    QVariantMap jsonToVariantMap(QJsonDocument &replyData);

public:
    API();
    ~API();

    QVariantMap getRequestData();
    void setRequestData(QVariantMap &data);
    QString getHost();
    void setSqlQuery(QSqlQuery &q);
    void setHost(QString &host);
    void clearRequestData();
    void initDataForRequest(const QString &tableName, const int &id);
    void readAllFromTable(const QString &tableName);
    void setRequest(const QString &tableName, const QString &operation);
    void setRequest(const QString &tableName, const QString &operation, QVariantMap &requestData);

signals:
    void done();

public slots:

    QVariantMap getReplyData();

private slots:

    void getReply(QNetworkReply* reply);

};

#endif // API_H
