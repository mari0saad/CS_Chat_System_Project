#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <QString>
#include <QFileInfo>

class FileService
{
public:
    QString createFileCmd(const QString& filename);
    QString writeFileCmd(const QString& filename, const QString& data);
    QString appendFileCmd(const QString& filename, const QString& data);
    QString readFileCmd(const QString& filename);
    QString deleteFileCmd(const QString& filename);
    QString renameFileCmd(const QString& oldName, const QString& newName);
    QString listFilesCmd();
    QString fileInfoCmd(const QString& filename);

private:
    bool createFile(const QString &filename, QString &errorMessage);
    bool writeFile(const QString &filename, const QString &data, QString &errorMessage);
    bool appendFile(const QString &filename, const QString &data, QString &errorMessage);
    bool readFile(const QString &filename, QString &outData, QString &errorMessage);
    bool deleteFile(const QString &filename, QString &errorMessage);
    bool renameFile(const QString &oldName, const QString &newName, QString &errorMessage);
    bool listFiles(QStringList &files, QString &errorMessage);
    bool fileInfo(const QString &filename, qint64 &size, QDateTime &modified, QString &errorMessage);

    bool isValidFilename(const QString& filename) const;
    bool resolvePath(const QString &clientFilename, QString &resolvedPath, QString &errorMessage) const;
};

#endif // FILESERVICE_H
