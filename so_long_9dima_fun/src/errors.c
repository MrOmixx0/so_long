/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:28:32 by mel-hajj          #+#    #+#             */
/*   Updated: 2025/03/11 03:28:35 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_MAP_SIZE 100

typedef struct {
    int width;
    int height;
    char map[MAX_MAP_SIZE][MAX_MAP_SIZE];
    int collectibles;
    int exits;
    int start_positions;
} Map;

char *get_next_line(int fd);

bool is_valid_map(Map *map) {
    int i = 0;
    // Check if the map is rectangular
    while (i < map->height) {
        if (map->map[i][map->width - 1] != '\0' && map->map[i][map->width - 1] != '\n') {
            return false;
        }
        i++;
    }

    i = 0;
    // Check if the map is enclosed in walls
    while (i < map->width) {
        if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1') {
            return false;
        }
        i++;
    }

    i = 0;
    while (i < map->height) {
        if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1') {
            return false;
        }
        i++;
    }

    // Check for exactly one exit, one start position, and at least one collectible
    if (map->exits != 1 || map->start_positions != 1 || map->collectibles < 1) {
        return false;
    }

    return true;
}

void read_map(const char *filename, Map *map) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open map file");
        exit(EXIT_FAILURE);
    }

    int row = 0;
    map->collectibles = 0;
    map->exits = 0;
    map->start_positions = 0;
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        int col = 0;
        while (line[col] != '\n' && line[col] != '\0') {
            map->map[row][col] = line[col];
            if (line[col] == 'C') map->collectibles++;
            if (line[col] == 'E') map->exits++;
            if (line[col] == 'P') map->start_positions++;
            col++;
        }
        map->map[row][col] = '\0'; // Null-terminate the line
        free(line);
        row++;
    }
    map->height = row;
    map->width = col;

    close(fd);

    if (!is_valid_map(map)) {
        printf("Invalid map\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <map_file.ber>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Map map;
    read_map(argv[1], &map);

    // Proceed with game initialization using the map
    return 0;
}

