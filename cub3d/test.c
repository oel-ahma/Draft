/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-ahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:12:37 by oel-ahma          #+#    #+#             */
/*   Updated: 2020/03/03 18:12:40 by oel-ahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <math.h>

int main()
{
    void *mlx;
    void *win;
    int x;
    int y;

    mlx = mlx_init();
    write(1, "opening file...\n", 16);
    win = mlx_new_window(mlx, 640, 400, "42");
    sleep(2);
    x = 100;
    y = 200;
   /* while (x < 200)
    {
        y = sqrt((120 * 120) - (x * x));
        mlx_pixel_put(mlx, win, x, y, 0xC04135);
        x++;
    }*/
    x = 270;
    y = 100;
    while (x < 200)
    {
        y = 100 + sqrt((10000 - ((x - 100) * (x - 100)))) ;
        mlx_pixel_put(mlx, win, x, y, 0xC04135);
        x++;
    }
    mlx_loop(mlx);
    sleep(5);
    return (0);
}