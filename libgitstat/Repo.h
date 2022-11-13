#include <memory>
#include <string>

struct git_repository;

namespace GitStat
{
	class Commit;
	class Tree;
	class Repo
	{
		git_repository* _repo{ nullptr };

		friend Commit;
		friend Tree;
	public:
		Repo(git_repository* repo);

		static std::unique_ptr<Repo> open(const std::string& path);

		std::shared_ptr<Commit> findCommit(const std::string& sha);
		std::shared_ptr<Tree> findTree(const std::string& sha);
	};
}
