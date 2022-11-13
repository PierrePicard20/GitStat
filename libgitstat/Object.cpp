#include "Object.h"
#include "repo.h"

namespace GitStat
{
    Object::Object(const std::string& sha1)
        :_sha1{sha1}
        , _oid{0}
    {
        int error = git_oid_fromstr(&_oid, sha1.c_str());
    }

    Commit::Commit(const std::string& sha1, const Repo* repo)
        :Object(sha1)
    {
        int error = git_commit_lookup(&_commit, repo->_repo, &_oid);
    }

    Tree::Tree(const std::string& sha1, const Repo* repo)
        :Object(sha1)
    {
        int error = git_tree_lookup(&_tree, repo->_repo, &_oid);
    }

    int Tree::getEntryCount() const
    {
        return (int)git_tree_entrycount(_tree);
    }

    std::vector<Tree::TreeEntry> Tree::getTreeEntries() const
    {
        std::vector<Tree::TreeEntry> ret;
        auto count = getEntryCount();
        for (int i = 0; i < count; i++)
        {
            ret.emplace_back(this, i);
        }
        return ret;
    }

    Tree::TreeEntry::TreeEntry(const Tree* tree, int index)
        :_entryByPath{nullptr}
    {
        _entry = git_tree_entry_byindex(tree->_tree, 0);
        _name = git_tree_entry_name(_entry);
        _objtype = git_tree_entry_type(_entry);
    }

    Tree::TreeEntry::TreeEntry(const Tree* tree, const std::string& path)
        :_entry{nullptr}
    {
        int error = git_tree_entry_bypath(&_entryByPath, tree->_tree, path.c_str());
        _name = git_tree_entry_name(_entryByPath);
        _objtype = git_tree_entry_type(_entryByPath);
    }

    Tree::TreeEntry::~TreeEntry()
    {
        if (_entryByPath)
        {
            git_tree_entry_free(_entryByPath);
        }
    }
}