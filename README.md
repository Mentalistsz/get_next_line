get_next_line

A simple function that takes a file descriptor and a string pointer as arguments
and reads the next line from a file. Returns 1 if the line was successfully read,
0 in case of EOF and -1 in case of an error. The function can be called in a while
loop. Memory gets allocated dynamically so free() is necessary.