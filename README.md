# wireless-bms-tbox-sdk
# QL AG35 T-BOX 编译验证工程

## 快速使用指南

### 环境准备
1. WSL已安装Ubuntu
2. 供应商工具链解压至：`/opt/toolchains/ql-ag35-1806e-gcc-8.4.0-glibc-v1-toolchain`(需要保证同样的路径)
3. Windows已安装ADB并配置PATH
4. T-BOX通过USB连接至电脑

### 操作步骤

#### 1. 进入工程目录
```bash
cd ~/wireless-bms-tbox-sdk
```

#### 2. 编译程序
```bash
./build.sh
```
编译成功后生成文件：`bin/tbox_test`

#### 3. 连接T-BOX
```bash
# Windows CMD中检查连接
adb devices
# 应显示：P1Y25F30D0090640P       device
```

#### 4. 推送文件到T-BOX并连接shell
```bash
# 推送可执行文件
adb push tbox_test /tbox_data
# 进入shell操作(进入后直接使用Linux 命令操作)
adb shell
```

#### 5. 设置执行权限
```bash
#进入tbox_data目录
#应显示/oemdata, /tbox_data 是一个符号链接，指向 /oemdata
chmod 777  tbox_test
```

#### 6. 运行测试程序
```bash
# 直接运行
./tbox_test
```

### 验证成功
程序运行后将显示编译环境信息和功能测试结果，最后输出"所有测试通过"。

### 问题排查
1. **编译失败**：检查工具链路径`/opt/toolchains/`是否正确
2. **ADB设备未找到**：确认USB连接和驱动正常
3. **权限错误**：确保执行了`chmod 777`
4. **非法指令**：确认T-BOX架构为ARMv7l

### 文件说明
- `main.c`：测试程序源码
- `CMakeLists.txt`：构建配置
- `build.sh`：一键编译脚本
- `bin/tbox_test`：生成的可执行文件（编译后出现）

---
**只需上述步骤即可完成从编译到运行的全过程**