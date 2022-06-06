pturtled:
	gcc -o pturtled main.c

install: pturtled
	@#@echo -ne $(shell [ $(shell id -u) -eq 0 ] || echo -e "Should be run as root" && exit 1)
	sudo cp pturtled.service /etc/systemd/system/multi-user.target.wants/
	-sudo killall -9 pturtled &> /dev/null
	sudo cp pturled /usr/local/bin/
	sudo systemctl daemon-reload
	sudo systemctl start pturtled
