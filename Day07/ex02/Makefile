NAME			:= array

HEADERS_DIR		:= .
HEADERS_FILES	:= Array.hpp

HEADERS			:= $(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))

SRC_DIR			:= .
SRC_FILES		:= main.cpp

SRCS			:= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

BUILD_DIR		:=	build
OBJS			:=	$(SRC_FILES:%.cpp=$(BUILD_DIR)/%.o)

CC				:=	c++
CC_FLAGS		:=	-Wextra -Werror -Wall -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) Makefile
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS) -I$(HEADERS_DIR) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re