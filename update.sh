#!/bin/bash
set -ux
# 適用したいバージョンアップのコミット
commit=b7ab0d95572221deb29336b1c0457e3f63105797
# 適用対象のブランチ一覧
branch_list=(`git branch -a | grep ex | sed -e 's/remotes\/origin\///g' | sed -e ':loop; N; $!b loop; s/\n/ /g'`)
echo ${branch_list[@]}

for branch in "${branch_list[@]}"; do
    git checkout $branch
    git log | grep commit | cut -f 2 -d ' ' | grep $commit; 
    if [ $? -eq 1 ] ;then
        git cherry-pick $commit
    fi
done

git checkout master
