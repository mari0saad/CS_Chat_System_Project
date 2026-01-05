#include "fileservice.h"
#include <QFile>
#include <QDir>
#include <QDateTime>
#include "serverconfig.h"

bool FileService::isValidFilename(const QString& filename) const
{
    return !filename.isEmpty()
        && !filename.contains("..")
        && !filename.contains(QChar('/'))
            && !filename.contains(QChar('\\'));
}

bool FileService::resolvePath(const QString &clientFilename, QString &resolvedPath, QString &errorMessage) const
{
    if (clientFilename.isEmpty()) {
        errorMessage = "Empty filename";
        return false;
    }

    QDir sandbox(ServerConfig::ROOT_DIR);

    // Build full path INSIDE sandbox
    QFileInfo fileInfo(sandbox.filePath(clientFilename));

    QString canonicalSandbox = sandbox.canonicalPath();
    QString canonicalFile = fileInfo.canonicalFilePath();

    // File may not exist yet (CREATE case)
    if (canonicalFile.isEmpty()) {
        canonicalFile = fileInfo.absoluteFilePath();
    }

    if (!canonicalFile.startsWith(canonicalSandbox + "/")) {
        errorMessage = "Access outside server directory forbidden";
        return false;
    }

    resolvedPath = canonicalFile;
    return true;
}

bool FileService::createFile(const QString &filename, QString &errorMessage)
{
    QString path;
    if (!resolvePath(filename, path, errorMessage))
        return false;

    QFile file(path);

    if (file.exists()) {
        errorMessage = "File already exists";
        return false;
    }

    if (!file.open(QIODevice::WriteOnly)) {
        errorMessage = "Cannot create file";
        return false;
    }

    file.close();
    return true;
}


bool FileService::writeFile(const QString &filename, const QString &data, QString &errorMessage)
{
    QString path;
    if (!resolvePath(filename, path, errorMessage))
        return false;

    QFile file(path);
    if (!file.exists()) {
        errorMessage = "File does not exist";
        return false;
    }

    if (!file.open(QIODevice::WriteOnly)) {
        errorMessage = "Cannot write file";
        return false;
    }

    file.write(data.toUtf8());
    file.close();
    return true;
}


bool FileService::appendFile(const QString &filename, const QString &data, QString &errorMessage)
{
    QString path;
    if (!resolvePath(filename, path, errorMessage))
        return false;

    QFile file(path);
    if (!file.exists()) {
        errorMessage = "File does not exist";
        return false;
    }

    if (!file.open(QIODevice::Append)) {
        errorMessage = "Cannot append to file";
        return false;
    }

    file.write(data.toUtf8());
    file.close();
    return true;
}


bool FileService::readFile(const QString &filename, QString &outData, QString &errorMessage)
{
    QString path;
    if (!resolvePath(filename, path, errorMessage))
        return false;

    QFile file(path);
    if (!file.exists()) {
        errorMessage = "File does not exist";
        return false;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        errorMessage = "Cannot read file";
        return false;
    }

    outData = QString::fromUtf8(file.readAll());
    file.close();
    return true;
}


bool FileService::deleteFile(const QString &filename, QString &errorMessage)
{
    QString path;
    if (!resolvePath(filename, path, errorMessage))
        return false;

    QFile file(path);
    if (!file.exists()) {
        errorMessage = "File does not exist";
        return false;
    }

    if (!file.remove()) {
        errorMessage = "Cannot delete file";
        return false;
    }

    return true;
}


bool FileService::renameFile(const QString &oldName, const QString &newName, QString &errorMessage)
{
    QString oldPath, newPath;
    if (!resolvePath(oldName, oldPath, errorMessage))
        return false;
    if (!resolvePath(newName, newPath, errorMessage))
        return false;

    QFile file(oldPath);
    if (!file.exists()) {
        errorMessage = "File does not exist";
        return false;
    }

    if (!file.rename(newPath)) {
        errorMessage = "Rename failed";
        return false;
    }

    return true;
}


bool FileService::listFiles(QStringList &files, QString &errorMessage)
{
    QDir dir(ServerConfig::ROOT_DIR);
    if (!dir.exists()) {
        errorMessage = "Server storage not available";
        return false;
    }

    files = dir.entryList(QDir::Files | QDir::NoDotAndDotDot);
    return true;
}


bool FileService::fileInfo(const QString &filename, qint64 &size, QDateTime &modified, QString &errorMessage)
{
    QString path;
    if (!resolvePath(filename, path, errorMessage))
        return false;

    QFileInfo info(path);
    if (!info.exists()) {
        errorMessage = "File does not exist";
        return false;
    }

    size = info.size();
    modified = info.lastModified();
    return true;
}
