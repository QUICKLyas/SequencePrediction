# SequencePrediction


## Python Progress - pyrep

1. exe文件运行位置在pyrep目录下。
2. 如果main.exe位置发生变化，需要将pyrep.config.file_config.py中json_file_path，修改为相对于main.exe，dataKJHM.json文件的路径。
3. json_file_path和json_file_name，可以合并为json_file_path。
4. 如果需要重新编译，请将main.py和main.spec移动到pyrep的上级目录。
5. 注意build 和 dist 在项目中是编译生成文件，可以删除build文件。

### Python Compile and Run

+ Compile: pyinstaller main.spec
+ main.spec 中 hiddenimports 写入需要引入的包文件地址，地址以pyrep为基地址
+ Run: ./main.exe 或者直接点击运行
+ 使用pip 指令可以安装缺少的第三方依赖包