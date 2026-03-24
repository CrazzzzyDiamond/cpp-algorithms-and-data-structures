CXX      = g++
CXXFLAGS = -std=c++17 -Wall
BUILD    = build

RESET  = \033[0m
BOLD   = \033[1m
GREEN  = \033[32m
CYAN   = \033[36m
YELLOW = \033[33m
RED    = \033[31m

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
	@printf "$(CYAN)building$(RESET)  $(BOLD)$(1)$(RESET)\n"
	@$$(CXX) $$(CXXFLAGS) $$^ -o $$@ && printf "$(GREEN)ok$(RESET)        $(BOLD)$(1)$(RESET)\n"
endef

$(foreach d,$(TEST_DIRS),$(eval $(call TEST_RULE,$(d))))

test: all
	@printf "\n$(BOLD)$(YELLOW)running tests$(RESET)\n"
	@printf "$(YELLOW)─────────────────────────────$(RESET)\n"
	@failed=0; \
	for t in $(TARGETS); do \
		name=$$(basename $$t); \
		printf "$(CYAN)testing$(RESET)   $(BOLD)$$name$(RESET)\n"; \
		if ./$$t > /dev/null 2>&1; then \
			printf "$(GREEN)passed$(RESET)    $(BOLD)$$name$(RESET)\n"; \
		else \
			printf "$(RED)failed$(RESET)    $(BOLD)$$name$(RESET)\n"; \
			failed=$$((failed+1)); \
		fi; \
	done; \
	printf "$(YELLOW)─────────────────────────────$(RESET)\n"; \
	if [ $$failed -eq 0 ]; then \
		printf "$(GREEN)$(BOLD)all tests passed$(RESET)\n\n"; \
	else \
		printf "$(RED)$(BOLD)$$failed test(s) failed$(RESET)\n\n"; \
		exit 1; \
	fi

clean:
	@printf "$(YELLOW)cleaning$(RESET)  $(BUILD)/\n"
	@rm -rf $(BUILD)
	@printf "$(GREEN)done$(RESET)\n"
