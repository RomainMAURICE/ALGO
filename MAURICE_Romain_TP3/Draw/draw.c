#include <MLV/MLV_all.h>

#define LINE_COLOR MLV_COLOR_BLUE
#define BACKGROUND_COLOR MLV_COLOR_WHITE

void Hrecursif(int x, int y, int lenth){

	if(lenth<5){
		return;
	}

	/* Draw the letter H */

	MLV_draw_line(x+lenth, y, x-lenth, y, LINE_COLOR);
	MLV_draw_line(x+lenth, y+lenth, x+lenth, y-lenth, LINE_COLOR);
	MLV_draw_line(x-lenth, y+lenth, x-lenth, y-lenth, LINE_COLOR);

	MLV_update_window();

	/* Wait and quit */

	MLV_wait_seconds(1);
	Hrecursif(x+lenth, y+lenth, lenth/2);
	Hrecursif(x-lenth, y-lenth, lenth/2);
	Hrecursif(x+lenth, y-lenth, lenth/2);
	Hrecursif(x-lenth, y+lenth, lenth/2);

}

int main() {
	/* Create the window */
	MLV_create_window("Draw", "Draw", 500, 500);
	MLV_draw_filled_rectangle(0, 0, 499, 499, BACKGROUND_COLOR);
	
	Hrecursif(100, 100, 30);

	return 0;
}