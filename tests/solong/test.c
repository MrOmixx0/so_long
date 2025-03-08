#include <fcntl.h>    // For open()
#include <unistd.h>   // For read(), close()
#include <stdlib.h>   // For malloc(), free()
#include <stdio.h>    // For printf()
#include <string.h>   // For strtok(), strdup()

#define BUFFER_SIZE 1024

// Count number of lines in the buffer
int count_lines(char *buffer)
{
    int i = 0, count = 0;
    while (buffer[i])
    {
        if (buffer[i] == '\n')
            count++;
        i++;
    }
    return (count + 1);
}

// Check if the map is rectangular
int is_rectangular(char **map)
{
    printf("Checking if the map is rectangular...\n");
    int i = 0;
    int width = strlen(map[0]);

    while (map[i])
    {
        if ((int)strlen(map[i]) != width)
        {
            printf("Error: Map is NOT rectangular!\n");
            return (0);
        }
        i++;
    }
    printf("✅ Map is rectangular\n");
    return (1);
}

// Check if the map is surrounded by walls
int is_surrounded_by_walls(char **map)
{
    printf("Checking if the map is surrounded by walls...\n");
    int i = 0;
    int width = strlen(map[0]);
    int height = 0;

    while (map[height])
        height++;

    // Check first and last row
    for (int j = 0; j < width; j++)
    {
        if (map[0][j] != '1' || map[height - 1][j] != '1')
        {
            printf("Error: Map is NOT fully enclosed by walls!\n");
            return (0);
        }
    }

    // Check first and last column
    for (i = 0; i < height; i++)
    {
        if (map[i][0] != '1' || map[i][width - 1] != '1')
        {
            printf("Error: Map has an open border!\n");
            return (0);
        }
    }
    printf("✅ Map is fully enclosed by walls\n");
    return (1);
}

// Check if the map has the required elements
int has_required_elements(char **map)
{
    printf("Checking if the map has exactly 1P, 1E, and at least 1C...\n");
    int i = 0, j;
    int player = 0, exit = 0, collectible = 0;

    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P')
                player++;
            else if (map[i][j] == 'E')
                exit++;
            else if (map[i][j] == 'C')
                collectible++;
            j++;
        }
        i++;
    }

    printf("Found: P=%d, E=%d, C=%d\n", player, exit, collectible);
    if (player != 1 || exit != 1 || collectible < 1)
    {
        printf("Error: Map does NOT have correct elements!\n");
        return (0);
    }
    printf("✅ Map has valid elements\n");
    return (1);
}

// Store the map in a 2D array
char **store_map(const char *buffer)
{
    int i = 0;
    int lines = count_lines((char *)buffer);
    char **map = malloc(sizeof(char *) * (lines + 1));

    if (!map)
    {
        write(2, "Error\nMemory allocation failed\n", 32);
        return (NULL);
    }

    char *copy = strdup(buffer);
    if (!copy)
    {
        free(map);
        return (NULL);
    }

    char *line = strtok(copy, "\n");
    while (line)
    {
        map[i] = strdup(line);
        line = strtok(NULL, "\n");
        i++;
    }
    map[i] = NULL;
	free(copy);
    return (map);
}

int main()
{
    int fd = open("ftmap.ber", O_RDONLY);
    if (fd == -1)
    {
        write(2, "Error\nCan't open the file\n", 27);
        return (1);
    }

    // Read file content into buffer
    char buffer[BUFFER_SIZE + 1];
    int bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read == -1)
    {
        write(2, "Error\nCould not read file\n", 26);
        close(fd);
        return (1);
    }
    buffer[bytes_read] = '\0'; // Null-terminate the buffer

    // Debug: Print file content
    printf("File Content:\n%s\n", buffer);

    // Store the map
    char **map = store_map(buffer);
    if (!map)
    {
        write(2, "Error\nFailed to store map\n", 27);
        close(fd);
        return (1);
    }

    // Debug: Print stored map
    printf("\nStored Map:\n");
    for (int i = 0; map[i]; i++)
        printf("%s\n", map[i]);

    // Run validation checks
    if (!is_rectangular(map))
    {
        write(2, "Error\nMap is not rectangular\n", 29);
        return (1);
    }
    if (!is_surrounded_by_walls(map))
    {
        write(2, "Error\nMap is not surrounded by walls\n", 37);
        return (1);
    }
    if (!has_required_elements(map))
    {
        write(2, "Error\nInvalid number of P, E, or C\n", 36);
        return (1);
    }

    printf("✅ All validation checks passed! Map is valid.\n");

    // Free allocated memory
    for (int i = 0; map[i]; i++)
        free(map[i]);
    free(map);

    close(fd);
    return (0);
}

