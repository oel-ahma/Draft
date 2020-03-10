/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 14:22:18 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/03/10 14:22:29 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>

#define mapWidth 10
#define mapHeight 10
#define screenWidth 640
#define screenHeight 480

typedef struct s_pos
{
    double x;
    double y;
} t_pos;

t_pos get_start(int tab[mapWidth][mapHeight])
{
    int i = 0, j = 0;
    t_pos ret;

    ret.x = -1;
    ret.y = -1;

    while (i < 10)
    {
        j = 0;
        while (j < 10)
        {
            if (tab[i][j] == 5)
            {
                ret.y = (i * 64) + 32;
                ret.x = (j * 64) + 32;
                return (ret);
            }
            j++;
        }
        i++;
    }
    return (ret);
}

int map[mapWidth][mapHeight] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {1, 5, 0, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 1, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int main()
{
    t_pos start, I, B, ret;
    double DeltaX, DeltaY;
    double Alpha = -30;

    start = get_start(map);
    DeltaX = 64 / tan(Alpha);
    DeltaY = 64 * tan(Alpha);

    while (Alpha <= 30)
    {
        // Horizontal Intersection
        printf("Alpha is %f  ||  ", Alpha);
        if (Alpha < 0)
        {
            I.y = (int)(start.y / 64) * 64 - 1;
            I.x = start.x + (start.y - I.y) / tan(Alpha);
            while (map[(int)(I.y / 64)][(int)(I.x / 64)] != 1)
            {
                I.x += DeltaX;
                I.y += 64;
            }
        }
        if (Alpha > 0)
        {
            I.y = (int)(start.y / 64) * 64 + 64;
            I.x = start.x + (start.y - I.y) / tan(Alpha);
            while (map[(int)(I.y / 64)][(int)(I.x / 64)] != 1)
            {
                I.x += DeltaX;
                I.y -= 64;
            }
        }
        printf("Vx = %d, Vy = %d  ||", (int)(I.x / 64), (int)(I.y / 64));
        
        // Vertical Intersection

        if (Alpha < 0)
        {
            B.x = (int)(start.x / 64) * 64 - 1;
            B.y = start.y + (start.x - B.x) * tan(Alpha);
            while (map[(int)(B.y / 64)][(int)(B.x / 64)] != 1)
            {
                B.x += 64;
                B.y += DeltaY;
            }
        }
        if (Alpha >= 0)
        {
            B.x = (int)(start.x / 64) * 64 + 64;
            B.y = start.y + (start.x - B.x) * tan(Alpha);
            while (map[(int)(B.y / 64)][(int)(B.x / 64)] != 1)
            {
                B.x += 64;
                B.y += DeltaY;
            }
        }
        printf("  Hx = %d, Hy = %d\n", (int)(B.x / 64), (int)(B.y / 64));
        Alpha += 2;
    }
}
