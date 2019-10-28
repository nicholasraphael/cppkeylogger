#include <iostream>
#include <sys/types.h>
#include <linux/input.h>

using namespace std;

int main(int argc, char const *argv[])
{
    const char* buffer_path = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int fd;
    fd = open(buffer_path, O_RDONLY);
    if (fd == -1) {
        return EXIT_FAILURE;
    }
    struct input_event ev;
    ssize_t n;

    while (1) {
        n = read(fd, &ev, sizeof ev);
	if (ev.type == EV_KEY && ev.value == 1) {
            cout << "Key " << ev,code << " pressed" << endl;
	}
	if (ev.value == KEY_ESC) break;

    }
    close(fd);
    fflush(stdout);
    return EXIT_FAILURE;
}
