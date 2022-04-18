util/docker_build.sh  crkbd:dlip
sudo avrdude -p atmega32u4 -c avr109 -P /dev/ttyACM0 -U flash:w:crkbd_rev1_dlip.hex:i
