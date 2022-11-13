#include <string>
#include <vector>

#include <git2.h>

namespace GitStat
{
    class Repo;
    class Object
    {
    protected:
        std::string _sha1;
        git_oid _oid;
    public:
        Object(const std::string& sha1);
        virtual ~Object() = default;

        inline git_oid getOid() const { return _oid; }
        inline const std::string& getSHA1() const { return _sha1; }
    };

    class Commit : public Object
    {
        git_commit* _commit;
    public:
        Commit(const std::string& sha1, const Repo* repo);
    };

    class Tree : public Object
    {
        git_tree* _tree;
    public:
        Tree(const std::string& sha1, const Repo* repo);

        class TreeEntry
        {
            const git_tree_entry* _entry;
            git_tree_entry* _entryByPath;
            std::string _name;
            git_otype _objtype;
        public:
            TreeEntry(const Tree* tree, int index);
            TreeEntry(const Tree* tree, const std::string& path);
            ~TreeEntry();

            inline const std::string& getName() const { return _name; }
            inline git_otype getType() const { return _objtype; }
        };

        int getEntryCount() const;
        std::vector<TreeEntry> getTreeEntries() const;
    };

}