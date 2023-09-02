
#include "./include/cub3D.h"

#include "mlx.h"

int main(void)
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    char *img_data;
    int bits_per_pixel;
    int size_line;
    int endian;
    int img_width;
    int img_height;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Print Column of Image");

    // Load the image
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "image.xpm", &img_width, &img_height);

    // Get image data
    img_data = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);

    // Define the column to print (e.g., column 100)
    int column_to_print = 100;

    // Iterate through the column and draw each pixel
    for (int y = 0; y < img_height; y++) {
        // Calculate the pixel index in the column
        int pixel_index = (column_to_print + y * img_width) * (bits_per_pixel / 8);

        // Extract the color components from the pixel data (assuming 32 bits per pixel)
        int red = img_data[pixel_index];
        int green = img_data[pixel_index + 1];
        int blue = img_data[pixel_index + 2];

        // Draw the pixel on the window
        mlx_pixel_put(mlx_ptr, win_ptr, 100, y, mlx_get_color_value(mlx_ptr, (red << 16) | (green << 8) | blue));
    }

    mlx_loop(mlx_ptr);
    return 0;
}
