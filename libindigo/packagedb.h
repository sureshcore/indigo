#ifndef PACKAGEDB_H
#define PACKAGEDB_H

#include <string>


class PackageDb
{
    std::string packageName_;

public:
    PackageDb(const std::string &packageName);
};

#endif // PACKAGEDB_H
