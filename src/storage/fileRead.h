/***********************************************************************************************************************************
Storage File Read
***********************************************************************************************************************************/
#ifndef STORAGE_FILEREAD_H
#define STORAGE_FILEREAD_H

/***********************************************************************************************************************************
Storage file read object
***********************************************************************************************************************************/
typedef struct StorageFileRead StorageFileRead;

#include "common/type/buffer.h"
#include "common/type/string.h"
#include "storage/driver/posix/driverRead.h"

/***********************************************************************************************************************************
Constructor
***********************************************************************************************************************************/
StorageFileRead *storageFileReadNew(const String *name, bool ignoreMissing, size_t bufferSize);

/***********************************************************************************************************************************
Functions
***********************************************************************************************************************************/
bool storageFileReadOpen(StorageFileRead *this);
Buffer *storageFileRead(StorageFileRead *this);
void storageFileReadClose(StorageFileRead *this);

StorageFileRead *storageFileReadMove(StorageFileRead *this, MemContext *parentNew);

/***********************************************************************************************************************************
Getters
***********************************************************************************************************************************/
StorageFileReadPosix *storageFileReadFileDriver(const StorageFileRead *this);
bool storageFileReadIgnoreMissing(const StorageFileRead *this);
const String *storageFileReadName(const StorageFileRead *this);
size_t storageFileReadSize(const StorageFileRead *this);

/***********************************************************************************************************************************
Destructor
***********************************************************************************************************************************/
void storageFileReadFree(StorageFileRead *this);

/***********************************************************************************************************************************
Macros for function logging
***********************************************************************************************************************************/
#define FUNCTION_DEBUG_STORAGE_FILE_READ_TYPE                                                                                      \
    StorageFileRead *
#define FUNCTION_DEBUG_STORAGE_FILE_READ_FORMAT(value, buffer, bufferSize)                                                         \
    objToLog(value, "StorageFileRead", buffer, bufferSize)

#endif
