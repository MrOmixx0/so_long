static void check_chars(t_game *game, int *p_count, int *e_count, int *c_count)
{
    int     i;
    int     j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == 'P')
                (*p_count)++;
            else if (game->map[i][j] == 'E')
                (*e_count)++;
            else if (game->map[i][j] == 'C')
                (*c_count)++;
            else if (game->map[i][j] != '0' && game->map[i][j] != '1')
                exit_game(game, "Error: Invalid character in map\n");
            j++;
        }
        i++;
    }
}

static void check_walls(t_game *game, int height, int width)
{
    int     i;

    i = 0;
    while (i < width)
    {
        if (game->map[0][i] != '1' || game->map[height - 1][i] != '1')
            exit_game(game, "Error: Map not surrounded by walls\n");
        i++;
    }
    i = 0;
    while (i < height)
    {
        if (game->map[i][0] != '1' || game->map[i][width - 1] != '1')
            exit_game(game, "Error: Map not surrounded by walls\n");
        i++;
    }
}

static void validate_map(t_game *game)
{
    int     height;
    int     width;
    int     i;
    int     p_count;
    int     e_count;
    int     c_count;

    height = 0;
    while (game->map[height])
        height++;
    width = ft_strlen(game->map[0]);  // Assuming ft_strlen from libft
    i = 0;
    while (game->map[i])
    {
        if (ft_strlen(game->map[i]) != width)
            exit_game(game, "Error: Map not rectangular\n");
        i++;
    }
    p_count = 0;
    e_count = 0;
    c_count = 0;
    check_chars(game, &p_count, &e_count, &c_count);
    check_walls(game, height, width);
    if (p_count != 1 || e_count != 1 || c_count < 1)
        exit_game(game, "Error: Invalid number of P, E, or C\n");
}
