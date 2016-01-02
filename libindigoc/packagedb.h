#ifndef INDIGO_PACKAGEDB_H
#define INDIGO_PACKAGEDB_H

#include <string>

namespace Indigo
{
    class PackageRecord
    {
    public:

    };

    class SourceFileRecord
    {

    };

    class TopLevelDeclRecord
    {

    };


    class PackageDb
    {
        std::string packageName_;
        std::string packagePath_;

    public:
        PackageDb(const std::string &packageName, const std::string &packagePath);

        // Open an existing database or create a new database.
        bool open();

        // Packages.
        bool getPackage(PackageRecord &pr);
        bool putPackage(PackageRecord &pr);

        // Source files.
        bool getSourceFile(const std::string &path, SourceFileRecord &sfr);
        bool putSourceFile(SourceFileRecord &sfr);

        // Top level decls.
        bool getTopLevelDecl(const std::string &fqn, TopLevelDeclRecord &tldr);
        bool putTopLevelDecl(TopLevelDeclRecord &tldr);
    };

}

#endif // INDIGO_PACKAGEDB_H
