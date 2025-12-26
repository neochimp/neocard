#ifndef CANVAS_H
#define CANVAS_H

#include <stddef.h>

typedef struct {
	size_t w;
	size_t h;
	char* buffer;
} Canvas;

typedef enum {
	WRITE_SUCCESS,
	WRITE_OVERFLOW,
	WRITE_OUT_OF_BOUNDS,
	WRITE_NULL,
	WRITE_CANVAS_NULL
} CanvasWriteError;

Canvas GenerateCanvas(size_t w, size_t h);

void CleanCanvas(Canvas canvas);

CanvasWriteError WriteCanvasH(Canvas canvas, size_t x, size_t y, const char* buffer);

CanvasWriteError WriteCanvasV(Canvas canvas, size_t x, size_t y, const char* buffer);

void PrintCanvas(Canvas canvas);

void CanvasTest();

Canvas CardCanvas();

#endif
