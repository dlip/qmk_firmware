# Chouchou

## Build and flash

Run

```
  qmk compile -kb chouchou -km default
```
or
```
  util/docker_build.sh chouchou:default
```

Hold the boot button on your RP2040-Zero while connecting the usb.

Copy the file `.build/chouchou_default.uf2` to the drive that appears.