#include "grid.h"
#include <stdlib.h>
#include <stdio.h>
#include "draw.h"
#include <time.h>

/*
 * Allocate memory for a grid and initialize each cell.
 */
grid *create_grid(int x_size, int y_size) {
	int i, j;
	grid *g = (grid *)malloc(sizeof(grid));
	g->x_size = x_size;
	g->y_size = y_size;
	g->cells = (cell **)malloc(x_size*sizeof(cell *));
	for (i = 0; i < x_size; i++)
		g->cells[i] = (cell *)malloc(y_size*sizeof(cell));

	for (j = 0; j < y_size; j++)
		for (i = 0; i < x_size; i++) {
			g->cells[i][j].x_pos = i;
			g->cells[i][j].y_pos = j;
			g->cells[i][j].visible = 0;
			g->cells[i][j].marked = 0;
			g->cells[i][j].mine = 0;
			g->cells[i][j].mine_count = 0;
		}

	return g;
}

/*
 * Free memory for a grid.
 */
void free_grid(grid *g) {
	int i;
	for (i = 0; i < g->x_size; i++)
		free(g->cells[i]);
	free(g->cells);
	free(g);
}

/*
 * Set all cells to visible (for debugging).
 */
void set_all_visible(grid *g) {
	int x, y;
	for (x = 0; x < g->x_size; x++)
		for (y = 0; y < g->y_size; y++)
			g->cells[x][y].visible = 1;
}

/*
 * Add exactly n mines to grid g in random positions.
 */
void add_mines(grid *g, int n) {
	int i;
	for (i=0; i<n; i++){
		int x_mine = rand() % g->x_size;
		int y_mine = rand() % g->y_size;
		printf("%d ", x_mine);
		printf("%d   ", y_mine);
		g->cells[x_mine][y_mine].mine = 1;

		g->cells[x_mine][y_mine].mine_count++;
		if(y_mine!=0){
			g->cells[x_mine][y_mine-1].mine_count++;
		}
		if(y_mine!=g->y_size){
		g->cells[x_mine][y_mine+1].mine_count++;
		}
		if(x_mine!=0){
			g->cells[x_mine-1][y_mine].mine_count++;
		}
		if(x_mine!=0 && y_mine!=0){
			g->cells[x_mine-1][y_mine-1].mine_count++;
		}
		if(x_mine!=0 && y_mine!=g->y_size){
			g->cells[x_mine-1][y_mine+1].mine_count++;
		}
		if(x_mine!=g->x_size){
			g->cells[x_mine+1][y_mine].mine_count++;
		}
		if(x_mine!=g->x_size && y_mine!=0){
			g->cells[x_mine+1][y_mine-1].mine_count++;
		}
		if(x_mine!=g->x_size && y_mine!=g->y_size){
			g->cells[x_mine+1][y_mine+1].mine_count++;
		}
	}
	return;
}

/*
 * Uncover cell c in grid g.
 * Return the total number of cells uncovered.
 */
int uncover(grid *g, cell *c) {

	c->visible = 1;

	draw_cell_actualise_window(c);

	return 0;
}