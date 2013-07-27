# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := math_native
DEFS_Debug := \
	'-DBUILDING_NODE_EXTENSION' \
	'-DDEBUG' \
	'-D_DEBUG'

# Flags passed to all source files.
CFLAGS_Debug := \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-pthread \
	-m32 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions

INCS_Debug := \
	-I/home/drola/.nw-gyp/0.6.1/src \
	-I/home/drola/.nw-gyp/0.6.1/deps/uv/include \
	-I/home/drola/.nw-gyp/0.6.1/deps/v8/include

DEFS_Release := \
	'-DBUILDING_NODE_EXTENSION'

# Flags passed to all source files.
CFLAGS_Release := \
	-Wall \
	-Wextra \
	-Wno-unused-parameter \
	-pthread \
	-m32 \
	-O2 \
	-fno-strict-aliasing \
	-fno-tree-vrp

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions

INCS_Release := \
	-I/home/drola/.nw-gyp/0.6.1/src \
	-I/home/drola/.nw-gyp/0.6.1/deps/uv/include \
	-I/home/drola/.nw-gyp/0.6.1/deps/v8/include

OBJS := \
	$(obj).target/$(TARGET)/src/addon.o \
	$(obj).target/$(TARGET)/src/Vector2.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m32

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m32

LIBS :=

$(obj).target/math_native.node: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/math_native.node: LIBS := $(LIBS)
$(obj).target/math_native.node: TOOLSET := $(TOOLSET)
$(obj).target/math_native.node: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,solink_module)

all_deps += $(obj).target/math_native.node
# Add target alias
.PHONY: math_native
math_native: $(builddir)/math_native.node

# Copy this to the executable output path.
$(builddir)/math_native.node: TOOLSET := $(TOOLSET)
$(builddir)/math_native.node: $(obj).target/math_native.node FORCE_DO_CMD
	$(call do_cmd,copy)

all_deps += $(builddir)/math_native.node
# Short alias for building this executable.
.PHONY: math_native.node
math_native.node: $(obj).target/math_native.node $(builddir)/math_native.node

# Add executable to "all" target.
.PHONY: all
all: $(builddir)/math_native.node

