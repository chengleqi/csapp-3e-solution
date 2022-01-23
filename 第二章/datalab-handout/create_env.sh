#!/usr/bin/env bash
echo 启动csapp环境容器🐳🚀
docker run -itd -v $(pwd):/csapp --name=csapp_env centos

CONTAINER_ID=$(docker ps |grep "centos" | awk '{print $1}')

docker exec $CONTAINER_ID curl -o /etc/yum.repos.d/CentOS-Base.repo https://mirrors.aliyun.com/repo/Centos-8.repo

docker exec $CONTAINER_ID yum makecache
docker exec $CONTAINER_ID yum -y update

docker exec $CONTAINER_ID yum install -y sudo make automake gcc gcc-c++ kernel-devel gdb glibc-devel.i686

echo 实验环境搭建完成🐳🚀
echo 请进入📂/csapp完成实验
echo -e "执行 \033[32mbash check.sh\033[0m 可以验证"
docker exec -it $CONTAINER_ID /bin/bash