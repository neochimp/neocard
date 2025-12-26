#include "neocard.h"
#include "polling/commands.h"
#include "canvas/canvas.h"
void Neocard() { 
  Canvas can = CardCanvas();
  PrintCanvas(can);
}
