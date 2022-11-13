#include "Repo.h"
#include "Object.h"

#include <git2.h>

namespace GitStat
{
	Repo::Repo(git_repository* repo)
		:_repo{repo}
	{
	}

	std::unique_ptr<Repo> Repo::open(const std::string& path)
	{
		int error;
		std::unique_ptr<Repo> ret;
		git_repository *repo;
		error = git_repository_open(&repo, path.c_str());
		ret = std::make_unique<Repo>(repo);
		return ret;
	}

	std::shared_ptr<Commit> Repo::findCommit(const std::string& sha)
	{
		return std::make_shared<Commit>(sha, this);
	}

	std::shared_ptr<Tree> Repo::findTree(const std::string& sha)
	{
		return std::make_shared<Tree>(sha, this);
	}
}
