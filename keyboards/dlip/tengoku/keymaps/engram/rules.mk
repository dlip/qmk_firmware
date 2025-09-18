USER_NAME := dlip
REPEAT_KEY_ENABLE = yes
VPATH  +=  keyboards/gboards/
COMBO_ENABLE=yes
OS_DETECTION_ENABLE = yes
MOUSEKEY_ENABLE = yes
ifeq ($(findstring uf2-split-left,$(MAKECMDGOALS)),uf2-split-left)
    OPT_DEFS += -DUF2_SPLIT_LEFT
endif
