# Get_next_line(42 project)


## Task


* Calling your  function get_next_line in a loop will then allow you to read the text
available on a file descriptor one line at a time until the EOF.
* Make sure that your function behaves well when it reads from a file and when it
reads from the standard input.
* Your program must compile with the flag -D BUFFER_SIZE=xx. which will be used
as the buffer size for the read calls in your get_next_line. 
* Compilation will be done this way : gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32
get_next_line.c get_next_line_utils.c
* Your read must use the BUFFER_SIZE defined during compilation to read from
a file or from stdin.

**Prototype:**
int get_next_line(int fd, char **line);

**Parameters:**

1. file descriptor for reading

2. The value of what has been read

**Allowed external functions:**
read, malloc, free

**Return value:**

1 : A line has been read

0 : EOF has been reached

-1 : An error happened
