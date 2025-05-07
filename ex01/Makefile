NAME		= phonebook 

# Compiler and flags
CXX			= c++
CXXFLAGS	= -g -Wall -Wextra -Werror -std=c++98

# Source files and objects
SRC_DIR		= ./
SRCS		= $(wildcard $(SRC_DIR)*.cpp)
OBJ_DIR		= obj/
OBJS		= $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRCS))

# Colors
RESET		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m

# Targets
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "$(GREEN)Linking $(NAME)$(RESET)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Created objects directory$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Clean complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re

