# 阿里云ubuntu系统配置linux-0.11（哈工大 李治军）实验环境搭建

## 环境介绍

使用的是ubuntu14.04（64位），最近在学习[操作系统（哈工大李治军老师）](https://www.bilibili.com/video/BV1d4411v7u7?t=1785&p=5)，本来在蓝桥云课上进行实验[操作系统蓝桥云课](https://www.lanqiao.cn/courses/115)，但没有会员环境只能保存一个小时，很不方便。于是使用阿里云搭建环境，有需要可以看[阿里云服务器Ubuntu14.04（64位）安装图形化界面](https://blog.csdn.net/leoabcd12/article/details/118751547)

## 实验材料

[gcc-3.4-ubuntu.tar.gz](https://github.com/hoverwinter/HIT-OSLab/blob/master/Resources/gcc-3.4-ubuntu.tar.gz)包含linux-0.11源码，bochs虚拟机等

[hit-oslab-linux-20110823.tar.gz](https://github.com/hoverwinter/HIT-OSLab/blob/master/Resources/hit-oslab-linux-20110823.tar.gz)编译linux-0.11需要用到的低版本的gcc

## 具体步骤

1.解压linux-0.11

```sh
tar zxvf hit-oslab-linux-20110823.tar.gz
```

2.配置gcc-3.4

```sh
cp gcc-3.4-ubuntu.tar.gz /tmp
cd /tmp		
tar zxvf gcc-3.4-ubuntu.tar.gz		
cd gcc-3.4		
sudo ./inst.sh amd64		
```

3.安装as86 ld86

```sh
sudo apt-get install bin86
```

4.C语言编译环境

```sh
sudo apt-get install build-essential
```

5.64位系统需要安装32位兼容库

```sh
sudo apt-get install libc6-dev-i386
```

6.编译内核

```sh
cd oslab/linux-0.11
make
```

7.运行linux-0.11

```sh
./run
```

8.出现错误

```sh
./bochs/bochs-gdb: error while loading shared libraries: libSM.so.6: cannot open shared object file: No such file or directory	
```
9.打印动态链接配置

```sh
ldconfig -p | grep libSM.so.6
```
10.libSM.so.6的链接信息		
```sh
libSM.so.6 (libc6,x86-64) => /usr/lib/x86_64-linux-gnu/libSM.so.6
```
11.我们需要的是32位的。搜索库对应的名称	
```sh
apt-file search libSM.so.6
```
12.打印结果
```sh
libsm6: /usr/lib/x86_64-linux-gnu/libSM.so.6
libsm6: /usr/lib/x86_64-linux-gnu/libSM.so.6.0.1
```
13.得到其对应的包名为libsm6，安装对应的32位库

```sh
sudo apt-get install libsm6:i386
```
14.再次尝试，出现错误

```sh
./bochs/bochs-gdb: error while loading shared libraries: libX11.so.6: cannot open shared object file: No such file or directory
```

15.同样可以按照步骤11来解决，不过这里用了另一个工具

```sh
dpkg-query -S libX11.so.6
```

16.打印结果		

```sh
libx11-6:i386: /usr/lib/i386-linux-gnu/libX11.so.6.3.0
libx11-6:amd64: /usr/lib/x86_64-linux-gnu/libX11.so.6
libx11-6:amd64: /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0
libx11-6:i386: /usr/lib/i386-linux-gnu/libX11.so.6
```

17.得到其对应的包名为libx11-6，安装对应的32位库		

```sh
sudo apt-get install libx11-6:i386
```

18.再次尝试，出现错误		

```sh
./bochs/bochs-gdb: error while loading shared libraries: libXpm.so.4: cannot open shared object file: No such file or directory
```

19.继续使用步骤15的工具		

```sh
dpkg-query -S libXpm.so.4
```

20.打印结果		

```sh
libxpm4:i386: /usr/lib/i386-linux-gnu/libXpm.so.4
libxpm4:amd64: /usr/lib/x86_64-linux-gnu/libXpm.so.4
libxpm4:amd64: /usr/lib/x86_64-linux-gnu/libXpm.so.4.11.0
libxpm4:i386: /usr/lib/i386-linux-gnu/libXpm.so.4.11.0
```

21.得到其对应的包名为libxpm4，安装对应的32位库

```
sudo apt-get install libxpm4:i386
```

22.还是报错

![image-20210715104852777](https://raw.githubusercontent.com/Casten-Wang/Pic/master/20210715104852.png)

23.缺乏依赖

![image-20210715105524593](https://raw.githubusercontent.com/Casten-Wang/Pic/master/20210715105524.png)

24.修复依赖

```
sudo apt-get -f install
```

25.安装lib32stdc++6

```
sudo apt-get install lib32stdc++6
```

![image-20210715110027203](https://raw.githubusercontent.com/Casten-Wang/Pic/master/20210715110027.png)

26.运行成功

![image-20210715110358805](https://raw.githubusercontent.com/Casten-Wang/Pic/master/20210715110358.png)

