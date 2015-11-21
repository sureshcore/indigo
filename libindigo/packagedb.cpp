#include "packagedb.h"
#include "lmdb++.h"

PackageDb::PackageDb(const std::string &packageName) :
    packageName_(packageName)
{
}

