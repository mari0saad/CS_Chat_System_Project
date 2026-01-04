#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <QString>

class FileService
{
public:
    bool createFile(const QString& filename, QString& errorMessage) const;
private:
    bool isValidFilename(const QString& filename) const;
};

#endif // FILESERVICE_H
