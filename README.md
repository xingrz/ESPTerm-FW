ESPTerm-FW
==========

这是 [ESPTerm](https://github.com/xingrz/ESPTerm-PCB) 软件部分的源码。基于 [ESP8266_RTOS_SDK](https://github.com/espressif/ESP8266_RTOS_SDK) 开发。

## 编译

配置 ESP8266 SDK，详见[相关官方文档](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html#setup-toolchain)。

```sh
# 获取源码
git clone --recursive https://github.com/xingrz/ESPTerm-FW.git

# 初始化环境，假设你的 ESP8266_RTOS_SDK 位于 ~/esp 目录下
export IDF_PATH=$HOME/esp/ESP8266_RTOS_SDK && . $IDF_PATH/export.sh

# 执行编译
make
```

## 烧录

将 ESPTerm 上的 5V/RX/TX/GND 分别接到串口板的 5V/TXD/RXD/GND 上。按住 ESPTerm 上方的按钮上电。上电后即可松开按钮。

### 从源码烧录

首次烧录需要全量烧录：

```sh
# 假设你的串口板位于 /dev/cu.usbserial-31120
make ESPPORT=/dev/cu.usbserial-31120 flash
```

后续开发调试通常只需要烧录 app 分区：

```sh
# 假设你的串口板位于 /dev/cu.usbserial-31120
make ESPPORT=/dev/cu.usbserial-31120 app-flash
```

### 烧录 CI 产物

除了自己从源码构建外，你还可以从 [Actions](https://github.com/xingrz/ESPTerm-FW/actions) 下载由 CI 编译好的产物，并通过 esptool.py 烧录。

```sh
# 安装烧录工具
pip install esptool

# 假设你的串口板位于 /dev/cu.usbserial-31120
esptool.py \
    --port /dev/cu.usbserial-31120 --baud 115200 \
    write_flash --flash_mode dout \
    0x0 bootloader.bin \
    0x8000 partition_table.bin \
    0x10000 app.bin
```

烧录完毕后重新上电即可。

## 开源许可

ESPTerm 的软件部分采用 [GNU v3](LICENSE) 协议开源。
