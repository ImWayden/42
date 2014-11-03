/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarr <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/10 19:12:54 by msarr             #+#    #+#             */
/*   Updated: 2014/10/11 01:51:05 by msarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

int main()
{
    double posX = 22.0, posY = 11.5;  //x and y start position
	double dirX = -1.0, dirY = 0.0; //initial direction vector
	double planeX = 0.0, planeY = 0.66; //the 2d raycaster version of camera plane
	double time = 0; //time of current frame
	double oldTime = 0; //time of previous frame
	int texture[8];
    double cameraX; //x-coordinate in camera space     
    double rayPosX;
    double rayPosY;
    double rayDirX;
    double rayDirY;
    int x;
    double sideDistX;
    double sideDistY;
    double deltaDistX;
    double deltaDistY;
    double perpWallDist;
    int stepX;
    int stepY;
    int hit = 0;
    int side;
    int lineHeight;
    int drawStart;
    int drawEnd;
    int texNum;
    int texX;
    int texY;
    int d;
    int x;
    int y;
    int color;
    int  buffer[screenWidth][screenHeight];
    double wallX; //where exactly the wall was hit
    t_env env;

    if ((env.ptr = mlx_init()) == NULL)
            return (EXIT_FAILURE);
    if ((env.win = mlx_new_window(env.ptr, screenWidth,screenHeight, "Raycaster")) == NULL)
            return (EXIT_FAILURE);
  	//generate some color 
    texture[0] = BLACK;
    texture[1] = RED;
    texture[2] = GREEN;
    texture[3] = YELLOW;
    texture[4] = BLUE;
    texture[5] = PURPLE;
    texture[6] = CYAN;
    texture[7] = GREY;
  
  //start the main loop
    while(!done())
    {
        w = 24;
    	for(x = 0; x < w; x++)
    	{
        //calculate ray position and direction 
            cameraX = 2*x/double(w)-1; //x-coordinate in camera space     
            rayPosX = posX;
            rayPosY = posY;
            rayDirX = dirX + planeX*cameraX;
            rayDirY = dirY + planeY*cameraX;
            //which box of the map we're in  
            mapX = int(rayPosX);
            mapY = int(rayPosY);
            //length of ray from current position to next x or y-side
            //length of ray from one x or y-side to next x or y-side
            deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
            deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
            //what direction to step in x or y-direction (either +1 or -1)
            //was there a wall hit?
            //was a NS or a EW wall hit?
            //calculate step and initial sideDist
            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (rayPosX - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (rayPosY - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
            }
            //perform DDA
            while (hit == 0)
            {
                //jump to next map square, OR in x-direction, OR in y-direction
                if (sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                //Check if ray has hit a wall
                if (worldMap[mapX][mapY] > 0)
                    hit = 1;
            }
            //Calculate distance of perpendicular ray (oblique distance will give fisheye effect!)
            if (side == 0)
                perpWallDist = fabs((mapX - rayPosX + (1 - stepX) / 2) / rayDirX);
            else
                perpWallDist = fabs((mapY - rayPosY + (1 - stepY) / 2) / rayDirY);
            //Calculate height of line to draw on screen
            lineHeight = abs(int(h / perpWallDist));
            //calculate lowest and highest pixel to fill in current stripe
            drawStart = -lineHeight / 2 + h / 2;
            if (drawStart < 0) drawStart = 0;
                drawEnd = lineHeight / 2 + h / 2;
            if (drawEnd >= h)
                drawEnd = h - 1;
            //texturing calculations
            texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!
            //calculate value of wallX
            if (side == 1)
                wallX = rayPosX + ((mapY - rayPosY + (1 - stepY) / 2) / rayDirY) * rayDirX;
            else
                wallX = rayPosY + ((mapX - rayPosX + (1 - stepX) / 2) / rayDirX) * rayDirY;
            wallX -= floor((wallX));
            //x coordinate on the texture
            texX = (int )wallX * (double)texWidth;
            if (side == 0 && rayDirX > 0)
                texX = texWidth - texX - 1;
            if (side == 1 && rayDirY < 0)
                texX = texWidth - texX - 1;
            for (y = drawStart; y < drawEnd; y++)
            {
                d = y * 256 - h * 128 + lineHeight * 128;  //256 and 128 factors to avoid floats
                texY = ((d * texHeight) / lineHeight) / 256;
                color = texture[texNum];
                //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
                if (side == 1) color = (color >> 1) & 8355711;
                buffer[x][y] = color;
            }
        }
        for (x = 0; x < w; x++)
        {
            for(int y = 0; y < h; y++)
            {
                mlx_pixel_put(env.ptr, env.win, x, y, buffer[x][y]);
                buffer[x][y] = 0; //clear the buffer instead of cls()
            }
        }
        //timing for input and FPS counter
        //oldTime = time;
        //time = getTicks();
    //double frameTime = (time - oldTime) / 1000.0; //frametime is the time this frame has taken, in seconds     
    //print(1.0 / frameTime); //FPS counter
    //redraw();

    //speed modifiers
    //double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    //double rotSpeed = frameTime * 3.0; //the constant value is in radians/second
    
   /*readKeys();
    //move forward if no wall in front of you
    if (keyDown(SDLK_UP))
    {
      if(worldMap[int(posX + dirX * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if (keyDown(SDLK_DOWN))
    {
      if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false) posX -= dirX * moveSpeed;
      if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    }
    //rotate to the right
    if (keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if (keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = dirX;
      dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
      dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }*/
  }
}
