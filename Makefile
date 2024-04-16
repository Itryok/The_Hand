all: compile_core compile_gui compile_tui run_gui

compile_core:
	gcc -c c_project_core.c -o c_project_core.o

compile_gui:
	gcc -c c_project_gui.c -o c_project_gui.o -lm `pkg-config --cflags --libs gtk+-3.0` -Wall -pthread
	gcc c_project_gui.o c_project_core.o -lm `pkg-config --cflags --libs gtk+-3.0` -rdynamic -o c_project_gui.out -pthread

compile_tui:
	gcc -c c_project_tui.c -o c_project_tui.o -pthread -Wall
	gcc c_project_tui.o c_project_core.o -pthread -Wall -o c_project_tui.out

compile_tui_temp:
	gcc -Wall -pthread -o c_project_tui.out c_project_tui.c -lpigpiod_if2

run_gui:
	./c_project_gui.out

run_tui:
	./c_project_tui.out

run_pigpiod:
	sudo pigpiod

clean:
	rm -f *.out *.o