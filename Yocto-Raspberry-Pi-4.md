# Embedded-Linux
Embedded Linux Projects using Yocto

## Build Yocto Poky Linux Image for Raspberry Pi 4 ##

### Install pre-requisites ###

```shell
sudo apt install gawk wget git diffstat unzip texinfo gcc build-essential chrpath socat cpio python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 python3-subunit zstd liblz4-tool file locales libacl1
```

```shell
sudo locale-gen en_US.UTF-8
```
Bmap Tool is required while writing the generated image to the storage

```shell
sudo apt install bmap-tools
```

### Set Locale ###

Open the default shell resource file like .bashrc or .zshrc located in the user's home directory (~/ or $HOME/). You can do this from the terminal using a command-line text editor like nano, vim, etc.

```shell
sudo nano ~/.bashrc
```

Inside the .bashrc file, add your environment variable.

```shell
export LANG=en_US.UTF-8
```

Save the file and exit the editor.

Source the .bashrc file to apply changes immediately without closing the terminal.

```shell
source ~/.bashrc
```

### Download Poky ###

Use Git to clone Poky
```shell
git clone git://git.yoctoproject.org/poky
```

### Initialize the Build Environment ###

```shell
cd poky
source oe-init-build-env
```
### Download Raspberry Pi BSP ###

Clone the Raspberry Pi BSP **meta-raspberrypi**
```shell
git clone git://git.yoctoproject.org/meta-raspberrypi
```

### Modify Configuration Files ###

Open the Bitbake Layers configuration file
```shell
nano conf/bblayers.conf
```

Add the meta-raspberrypi layer
```shell
BBLAYERS ?= " \
  /home/server/Desktop/Yocto/poky/meta \
  /home/server/Desktop/Yocto/poky/meta-poky \
  /home/server/Desktop/Yocto/poky/meta-yocto-bsp \
  /home/server/Desktop/Yocto/poky/meta-raspberrypi \
  "
```
The file should look like the above given content. Save the file and exit the editor.

Open the local configuration file
```shell
nano conf/local.conf
```
Set the machine target : 
```shell
MACHINE ??= "raspberrypi4-64"
```
Enable UART for monitoring system logs :
```shell
ENABLE_UART = "1"
```
Save the file and exit the editor.

### Start the Build ###

```shell
bitbake core-image-minimal
```
After the build process is completed go to the following directory :
```shell
cd /tmp/deploy/images/raspberrypi4-64
```
Here you will see the image files along with other modules generated
```shell
ls *wic*
```

### Flash the image to SD Card ###

Now, connect your SD Card and check the partition
```shell
sudo fdisk -l
```

Run the **bmaptool** to copy the image. Replace X with the partition number
```shell
sudo bmaptool copy core-image-minimal-raspberrypi4-64.rootfs.wic.bz2 /dev/sdX
```

Eject the SD Card


Plug the SD Card in Raspberry Pi and Boot !




