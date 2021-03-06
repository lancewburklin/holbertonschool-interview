#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H
#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
int slide_right(int *line, size_t size, int direction);
int merge(int *line, size_t size, int direction);

#endif
