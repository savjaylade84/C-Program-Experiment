


%:
	@echo "======================================================="
	@echo "\033[5m @Author : \033[0m john jayson b. de leon"
	@echo "\033[5m @Alias : \033[0m savjaylade84"
	@echo "==================|STARTING|==========================="
	@echo "\033[2m Removing old binary...\033[0m"
	rm -f ./bin/$@
	@echo "\033[2m Compiling new binary...\033[0m"
	gcc -g -Wall -std=c11 -o $@ $@.c
	@echo "\033[2m Moving new binary...\033[0m"
	mv $@ ./bin/
	@echo "==================|RUNNING|============================"
	@echo "\033[2m Executing binary \033[0m"
	./bin/$@