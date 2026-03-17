.cc.o:
	g++ -std=c++20 -c $< -O
itf:	itf.o reduce.o
	g++ $^ -o $@
clean:
	@rm itf *.o
deploy:
	@sudo cp itf /usr/sbin
	@sudo cp itf.service /etc/systemd/system
	@sudo systemctl enable itf
	@sudo systemctl start itf
	@systemctl status itf
