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

## Layout

This configuration has some modifications from the original layout:

- Inner and outer thumbs are flipped since i find space to be more natural on the outer thumb
- Uses extra keybindings which use both thumb keys together
- Fn layer key switched to 'insert'
- Adds alternate mappings for ''' and ';' since my ring and pinkie fingers don't get along

```
Input Output Outer Inner Both
#---  r      R     >     Print Screen
----

-#--  s      S     }     Brightness Up
----

--#-  n      N     ]     Brightness Down
----

---#  i      I     )     Play/Pause
----

----  a      A     <     Next Track
#---

----  o      O     {     Volume Up
-#--

----  t      T     [     Volume Down
--#-

----  e      E     (     Previous Track
---#

----  c      C     1     F1
-#-#

----  u      U     2     F2
-##-

----  q      Q     3     F3
#-#-

----  l      L     4     F4
##--

--##  y      Y     5     F5
----

-#-#  f      F     6     F6
----

-##-  p      P     7     F7
----

#-#-  z      Z     8     F8
----

##--  b      B     9     F9
----

----  h      H     0     F10
--##

----  d      D     @     F11
#--#

#--#  g      G     #     F12
----

#---  x      X     ^     Cut
--#-

---#  k      K     +     Copy
-#--

-#--  v      V     *     Paste
---#

--#-  j      J     =     Undo
#---

#---  m      M     $
---#

---#  w      W     &
#---

-#--  /      \     |
--#-

--#-  -      _     %
-#--

---#  ?      !
--#-

--#-  ,      .     ~
---#

#---  ;      :
-#--

----  ;      :
###-

-#--  '      "     `
#---

###-  '      "     `
----

-###  Tab    Del   Ins
----

----  Enter  Esc   AltGr
-###

#---  Gui    Right PgUp
#---

-#--  Alt    Up    Home Gamepad Layer
-#--

--#-  Ctrl   Down  End  Gaming Layer
--#-

---#  Shift  Left  PgDn
---#
```

