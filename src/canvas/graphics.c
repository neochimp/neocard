#include "graphics.h"
#include "polling/commands.h"
#include "polling/identity.h"

void DrawLogo(Canvas c, size_t x, size_t y) {
	WriteCanvasH(c, x, y, "     /\\");
	WriteCanvasH(c, x, y+1, "    /  \\");
	WriteCanvasH(c, x, y+2, "   /\\   \\");
	WriteCanvasH(c, x, y+3, "  /  ,,  \\");
	WriteCanvasH(c, x, y+4, " /  |  | -\\");
	WriteCanvasH(c, x, y+5, "/-\'\'    \'\'-\\");
}

void DrawPortrait(Canvas c, size_t x, size_t y) {
	WriteCanvasH(c, x, y, "===================");
	WriteCanvasV(c, x, y+1, "||||||||||");
	WriteCanvasV(c, x+18, y+1, "||||||||||");
	WriteCanvasH(c, x, y+10, "=================== -------------------------------------------");
	WriteCanvasV(c, x+18, y+12, "||||||");
	WriteCanvasH(c, x, y+17, "-----------------");
}

void DrawUsername(Canvas c, size_t x, size_t y) {
  UserInfo user = GetUserInfo();
	WriteCanvasH(c, x, y, "NEOCARD Version 1.0");
	WriteCanvasH(c, x, y+1, "--------------------------------");
	WriteCanvasH(c, x, y+2, user.username);
	WriteCanvasH(c, x, y+3, "=============================");
}

void DrawAge(Canvas c, size_t x, size_t y) {
	WriteCanvasH(c, x, y, "AGE: 894 days, 4 hr, 3 min");
}

void DrawKernel(Canvas c, size_t x, size_t y) {
  UserInfo user = GetUserInfo();
	WriteCanvasH(c, x, y, user.kernel);
}

void DrawPackages(Canvas c, size_t x, size_t y) {
	WriteCanvasH(c, x, y, "PACKAGES: 2092 (pacman), 16 (flatpak)");
}

void DrawShell(Canvas c, size_t x, size_t y) {
	WriteCanvasH(c, x, y, "SHELL: zsh 5.9");
}

void DrawFavorites(Canvas c, size_t x, size_t y) {
  Top3Commands commands = MostUsedCommands();
  WriteCanvasH(c, x+2, y, "TOP COMMANDS");
	WriteCanvasH(c, x, y+1, commands.top1);
	WriteCanvasH(c, x, y+2, commands.top2);
	WriteCanvasH(c, x, y+3, commands.top3);
}

void DrawProjects(Canvas c, size_t x, size_t y) {
	WriteCanvasH(c, x, y, "PROJECTS: 9 (git)");
}

void DrawBadges(Canvas c, size_t x, size_t y) {
	WriteCanvasH(c, x + 14, y, "--- BADGES ---");
}
