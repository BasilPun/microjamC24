# Git Branching Cheatsheet

A few quick recipes for working with git branches and upstreams.

This assumes you have already added an upstream and are MAKING ALL CHANGES ON BRANCHES OTHER THAN MAIN.

## Pulling from upstream and updating branches
The following steps are done by ONLY ONE PARTNER.
1. If you have uncommited changes on your branch (e.g. dev), commit and push those before continuing. You can check with `git status`. Make sure you're not accidentally committing to main!
1. Switch to the main branch: `git switch main`
1. Pull from the upstream: `git pull upstream main` So long as you have not been committing anything directly to main, this should be a fast-forward and there will be no merge conflicts.
1. Push main back to your fork: `git push origin main`
1. Switch to the branch you are working on (e.g. dev)
1. Merge your main branch into your working branch: `git merge main` There may be a merge message that pops up in VS Code you can confirm, or there may be merge conflicts you need to resolve. Resolve them and commit as necessary.
1. Push your updated branch to your fork: `git push origin`
1. Now, all of the other partners can pull down the merged changes on each branch: `git pull`

## Making a new branch from a specific commit
Want to make new branch that doesn't include all of your current commits?
1. Run `git log` to see a history of the commits on your current branch. Above each commit there will be the commit hash - essentailly a hexidecimal ID number that identifies the commit. For example: `ebf6d26bad46d57e6468f52548b83e2d6c8badc3`.
1. Use the arrow keys to move down through the history until you find the commit you want to branch from. Copy the hash (remembering that ctrl-C will likely not work on Windows)
1. Press `q` to exit git log.
1. To make the new branch and switch to it, run `git switch -c NEW_BRANCH_NAME COMMIT_HASH` (replacing the name and hash as appropriate and remembering that ctrl-v likely will not work on Windows). The `-c` stands for "commit". 
1. You are now on the new branch! Run `git push origin BRANCH_NAME` to push the branch.