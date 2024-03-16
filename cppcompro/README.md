## About CPP Program
### Boost Install
1. DownLoad: https://boostorg.jfrog.io/artifactory/main/release/1.84.0/source/boost_1_84_0.zip
2. 修改 bootstrap.sh 中 PREFIX= {安装路径地址}
3. 运行bootstrap.sh 生成 b2.exe
4. 在 cmd 中运行 b2.exe 和 b2.exe install 
   指令: .\b2.exe install --prefix={path you want} link=static

运行结束的时候应该出现一下内容
```
    ...failed updating 2 targets... 
    ...skipped 6 targets...
    ...updated 3274 targets...
```
安装完成之后可以使用
```
   b2 --version
```

### SCONS INSTALL
使用指令：
```
    pip install scons  
    scons --version
```

### MONGO-C-DRIVER INSTALL
1. 在源文件根目录下创建cmake-build，并且进入该目录
2. 运行cmake -G "Visual Studio 17 2022" "-DCMAKE_INSTALL_PREFIX=F:\tool\CXXPlugins\mongo-c-driver" "-DCMAKE_PREFIX_PATH=F:\tool\CXXPlugins\mongo-c-driver"  .. 

   结果：
   ```
      -- Configuring done (51.0s)  
      -- Generating done (1.1s)
      -- Build files have been written to: F:/tool/CXXPlugins/mongo-c-driver-1.26.0/cmake-build
   ```
   
3. 将msbuild.exe配置到电脑的环境变量，一般位置在 ...\Microsoft Visual Studio\2017\Professional\MSBuild\15.0\Bin\amd64 中
4. msbuild.exe  [/p:Configuration=RelWithDebInfo] ALL_BUILD.vcxproj
5. msbuild.exe  [/p:Configuration=RelWithDebInfo] INSTALL.vcxproj


### MONGO-CXX-DRIVER INSTALL
1. cmake .. -G "Visual Studio 17 2022" "-DCMAKE_CXX_STANDARD=17" "-DCMAKE_BUILD_TYPE=Release" "-DBUILD_SHARED_AND_STATIC_LIBS=ON" -DCMAKE_CXX_FLAGS="/Zc:__cplusplus" "-DBOOST_ROOT=F:\tool\CXXPlugins\boost" "-DCMAKE_PREFIX_PATH=F:\tool\CXXPlugins\mongo-c-driver" "-DCMAKE_INSTALL_PREFIX=F:\tool\CXXPlugins\mongo-cxx-driver" "-DBUILD_VERSION=1.0.2"
   结果：
   ```
      -- Configuring done (93.9s)
      -- Generating done (2.2s)
      -- Build files have been written to: F:/tool/CXXPlugins/mongo-cxx-driver-r3.10.0/cmake
   ```
2. 编译安装[README.md](README.md)
```
   msbuild.exe ALL_BUILD.vcxproj
   msbuild.exe INSTALL.vcxproj
   msbuild.exe generate_uninstall\uninstall.vcxproj \\ 卸载指令
```

## 关于CMAKE 引入外部文件
本项目大部分使用绝对引入，同时记录了部分其他引入的方法，详细可以从CMakeLists.txt中看到

## 关于连接MONGO
由于某种原因，不能将使用mongo-cxx-driver，转而使用mongo-c-driver连接数据库
2024.03.14: 重新研究发现，我们可以将mongo的库文件(.dll)复制到输出目录bin下，这样编译结果是可以运行的

## ABOUT ALGORITHM
已知目标输出是一组数字 前位 1-5 (1-35) 后位 6-7 (1-12) 我们成为这样的一组数据为数据链，在程序中可能生成多个这样的数据链组
1. 相同时间间隔，不同时间段的概率情况
   ```
   关于处理方式，首先，获取每个位置目前的概率，并做出概率分布，并且这个数据需要设置一个时间区间，
   既在一定时间内，所有数字在各个位置出现的概率，
   并根据通过这个时间获取交集，返回这些时间段下出现概率最小的一组数据。
   此时输出不需要考虑位置信息
   ```
2. 在整个时间下，数据出现的情况
   ```
   整个数据分布区间上计算每个位置各自的数据的数学期望，从中获取并以此，并依此数据链，
   生成新的数据链，
   这个新生成的数据链，应该是一个组，其中包含多个数据链，且每个数据链，表示未来可能出现的情况，
   ```
3. 对于新生成的数据链，需要加入的最近的一段时间周期进行验证
   ```
   数据链的验证目标，我们需要保证新生成的数据链，达到两种效果
   1. 新生成的数据链对于原本的数据的概率影响应该最小
   2. 新生成的数据链，必须在数据链的出现频率属于较小，情况，但应该期望这个数据链不是未出现过的数据
   ```
4. 正数据链出现频率，构成一个新的频率分布，概率分布
   ```
   对于过去已经出现的数据链，我们应该注意到，每一组数据链都是一种形式，在样本足够大的情况，每种可能出现的情况最少应该出现1次，
   由于样本量的有限，我们应该考虑到可能有一定数量的数据链是较少出现或者没有出现，
   时间越近的数据链，上次出现的情况应该是比较长的，但是在整个时间线上看，这样的数据链应该是具有一定的重复情况，这与间隔时间是反比的关系
   期望这是一个类似卡方分布的分布，
   ```
5. 关于不存在这样的数据链的情况
   ```
   如果在生成数据链的时候，没有生成我们需要的数据链，那么应该根据数据链组中最小概率的情况设置我们需要的数据链
   同时数据链的生成需要仔细考虑时间间隔的影响，出现间隔越长的数据应该增加权重
   ```