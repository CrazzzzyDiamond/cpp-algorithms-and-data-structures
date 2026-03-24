CXX      = g++
CXXFLAGS = -std=c++17 -Wall
BUILD    = build

# Find implementation in algorithms/ or data_structures/
impl = $(or $(wildcard algorithms/$(1)/$(1).cpp),$(wildcard data_structures/$(1)/$(1).cpp))

# Auto-discover all test directories
TEST_DIRS := $(patsubst tests/%/,%,$(sort $(dir $(wildcard tests/*/*))))
TARGETS   := $(addprefix $(BUILD)/,$(TEST_DIRS))

.PHONY: all test clean

all: $(TARGETS)

# Generate a build rule for each test directory
define TEST_RULE
$(BUILD)/$(1): $(wildcard tests/$(1)/*.cpp) $(call impl,$(1))
	@mkdir -p $(BUILD)
	$$(CXX) $$(CXXFLAGS) $$^ -o $$@
endef

$(foreach d,$(TEST_DIRS),$(eval $(call TEST_RULE,$(d))))

test: all
	@for t in $(TARGETS); do echo "=== $$t ==="; ./$$t; done

clean:
	rm -rf $(BUILD)
