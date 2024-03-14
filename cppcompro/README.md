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

