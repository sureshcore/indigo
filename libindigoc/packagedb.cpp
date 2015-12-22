#include <iostream>
#include <capnp/message.h>
#include <capnp/serialize-packed.h>

#include "packagedb.h"
#include "lmdb++.h"
#include "pdbfmt_generated.h"

namespace Indigo
{

    PackageDb::PackageDb(const std::string &packageName, const std::string &packagePath) :
        packageName_(packageName),
        packagePath_(packagePath)
    {
        /* Create and open the LMDB environment: */
        auto env = lmdb::env::create();
        env.set_mapsize(100UL * 1024UL * 1024UL); /* 100 MB */

        try {
            env.open(packagePath.c_str());
        }
        catch (lmdb::error &err)
        {
            // Got an error.
            std::cout << "err=" << err.code() << std::endl;
        }

        std::cout << "opened DB successfully\n";
    }



    // Packages.
    bool PackageDb::getPackage(PackageRecord &pr)
    {
#if 0
        /* Fetch key/value pairs in a read-only transaction: */
        auto rtxn = lmdb::txn::begin(env, nullptr, MDB_RDONLY);
        auto cursor = lmdb::cursor::open(rtxn, dbi);
        std::string key, value;
        while (cursor.get(key, value, MDB_NEXT))
        {
            std::printf("key: '%s', value: '%s'\n", key.c_str(), value.c_str());
        }

        cursor.close();
        rtxn.abort();
#endif
        return false;
    }


    bool PackageDb::putPackage(PackageRecord &pr)
    {
#if 0
        /* Insert some key/value pairs in a write transaction: */
        auto wtxn = lmdb::txn::begin(env);
        auto dbi = lmdb::dbi::open(wtxn, nullptr);
        dbi.put(wtxn, "username", "jhacker");
        dbi.put(wtxn, "email", "jhacker@example.org");
        dbi.put(wtxn, "fullname", "J. Random Hacker");
        wtxn.commit();
#endif

        return false;
    }



    // Source files.
    bool PackageDb::getSourceFile(const std::string &path, SourceFileRecord &sfr)
    {
        return false;
    }


    bool PackageDb::putSourceFile(SourceFileRecord &sfr)
    {
        return false;
    }



    // Top level decls.
    bool PackageDb::getTopLevelDecl(const std::string &fqn, TopLevelDeclRecord &tldr)
    {
        return false;
    }


    bool PackageDb::putTopLevelDecl(TopLevelDeclRecord &tldr)
    {
        return false;
    }



}
