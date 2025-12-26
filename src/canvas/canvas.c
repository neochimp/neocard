#include "canvas.h"
#include "canvas/graphics.h"
#include <string.h>
#include <easymemory.h>
#include <easylogger.h>

Canvas GenerateCanvas(size_t w, size_t h) {
	Canvas can = (Canvas){ w, h, EZ_ALLOC((w*h) + 1 + h, sizeof(char)) };
	for (size_t r = 0; r < h; r++) {
		for (size_t c = 0; c <= w; c++) {
			size_t i = r*(w+1) + c;
			if (c == w) {
				can.buffer[i] = '\n';
			} else {
				can.buffer[i] = ' ';
			}
		}
	}
	return can;
}

void CleanCanvas(Canvas canvas) {
	if (canvas.buffer == NULL) {
		EZ_WARN("Attempted to clean canvas with null buffer");
	} else {
		EZ_FREE(canvas.buffer);
	}
}

CanvasWriteError WriteCanvasH(Canvas canvas, size_t x, size_t y, const char* buffer) {
	if (canvas.buffer == NULL) return WRITE_CANVAS_NULL;
	if (buffer == NULL) return WRITE_NULL;
	size_t index = y*(canvas.w + 1) + x;
	size_t len = strlen(buffer);
	if (y >= canvas.h || x >= canvas.w) return WRITE_OUT_OF_BOUNDS;
	for (size_t i = 0; i < len; i++) {
		index = y*(canvas.w + 1) + x + i;
		if (index >= (canvas.w + 1)*canvas.h) return WRITE_OVERFLOW;
		canvas.buffer[index] = buffer[i];
	}
	return WRITE_SUCCESS;
}

CanvasWriteError WriteCanvasV(Canvas canvas, size_t x, size_t y, const char* buffer) {
	if (canvas.buffer == NULL) return WRITE_CANVAS_NULL;
	if (buffer == NULL) return WRITE_NULL;
	size_t index = y*(canvas.w + 1) + x;
	size_t len = strlen(buffer);
	if (y >= canvas.h || x >= canvas.w) return WRITE_OUT_OF_BOUNDS;
	for (size_t i = 0; i < len; i++) {
		index = (y+i)*(canvas.w + 1) + x;
		if (index >= (canvas.w + 1)*canvas.h) return WRITE_OVERFLOW;
		canvas.buffer[index] = buffer[i];
	}
	return WRITE_SUCCESS;
}

void PrintCanvas(Canvas canvas) {
	if (canvas.buffer == NULL) {
		EZ_ERROR("Cannot print canvas with null buffer");
		return;
	}
	if (strnlen(canvas.buffer, (canvas.w+1)*canvas.h + 1) >= (canvas.w+1)*canvas.h + 1) {
		EZ_ERROR("Canvas buffer overflow detected");
		return;
	}
	printf("%s\n", canvas.buffer);
}

void CanvasTest() {
	Canvas c = CardCanvas();
	PrintCanvas(c);
	CleanCanvas(c);
}

Canvas CardCanvas() {
	Canvas c = GenerateCanvas(67, 21);
	WriteCanvasH(c, 0, 0, "-------------------------------------------------------------------");
	WriteCanvasV(c, 0, 1, "|||||||||||||||||||");
	WriteCanvasV(c, 66, 1, "|||||||||||||||||||");
	WriteCanvasH(c, 0, 20, "-------------------------------------------------------------------");
	DrawLogo(c, 53, 1);
	DrawPortrait(c, 2, 1);
	DrawUsername(c, 22, 1);
	DrawAge(c, 22, 6);
	DrawKernel(c, 22, 7);
	DrawPackages(c, 22, 8);
	DrawShell(c, 22, 9);
	DrawFavorites(c, 2, 13);
	DrawProjects(c, 2, 19);
	DrawBadges(c, 22, 12);
	return c;
}
