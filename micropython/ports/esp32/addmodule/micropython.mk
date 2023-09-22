ADDMODULE_MOD_DIR := $(USERMOD_DIR)

# Add all C files to SRC_USERMOD.
SRC_USERMOD += $(ADDMODULE_MOD_DIR)/addmodule.c

# We can add our module folder to include paths if needed
# This is not actually needed in this example.
CFLAGS_USERMOD += -I$(ADDMODULE_MOD_DIR)
