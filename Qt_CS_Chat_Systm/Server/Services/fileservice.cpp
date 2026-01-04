#include "fileservice.h"
#include <QFile>


bool FileService::isValidFilename(const QString &filename) const
{
    bool isValid = !filename.isEmpty()
            && !filename.contains("..")
            && !filename.contains('/')
            && !filename.contains('\\');
    return isValid;
}


bool FileService::createFile(const QString& filename, QString& errorMessage) const
{
    bool retValue = true;
    QFile file(filename);
    if(!isValidFilename(filename))
    {
        errorMessage = "Invalid Filename";
        retValue = false;
    }
    else if(file.exists())
    {
        errorMessage = "File already exists";
        retValue = false;
    }
    else if(!file.open(QIODevice::WriteOnly))
    {
        errorMessage = "Can't create file";
    }
    file.close();
    return retValue;
}

