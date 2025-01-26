# Harite v2

<https://github.com/dlip/harite-v2>

Flash the default layout for testing (each switch should output UDLRC):

```
qmk flash -kb haritev2 -km default -bl uf2-split-left
qmk flash -kb haritev2 -km default -bl uf2-split-right
```

Flash the [Stained](./keymaps/stained) layout:

```
qmk flash -kb haritev2 -km stained -bl uf2-split-left
qmk flash -kb haritev2 -km stained -bl uf2-split-right
```
