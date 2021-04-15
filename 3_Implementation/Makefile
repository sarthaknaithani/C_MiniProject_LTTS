PROJ_NAME = snake
TEST_PROJ_NAME = tests

BUILD_DIR = Build

SRC = src/backend.c

TEST_SRC = test/tests.c\
unity/unity.c

INC = -Iinc\
-Iunity

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
.PHONY : all test coverage run clean doc

all:$(BUILD_DIR)
	
	gcc -o snake main.c src/backend.c src/frontend.c -lncurses

run: all
	./snake

test: $(SRC) $(TEST_SRC)
	gcc -lm $^ $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)) 
	./Build/tests.out


coverage:${PROJECT_NAME}
	gcc -fprofile-arcs -ftest-coverage src/backend.c src/frontend.c main.c $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)) -lncurses
	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
	gcov -a $(SRC)

doc:
	make -C doc
$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
	make clean 
	rmdir $(BUILD_DIR) 


