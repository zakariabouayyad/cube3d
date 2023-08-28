#include "cube3d.h"

bool	is_whitespace(const char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		// if (str[i] != 32 && str[i] >= 13 && str[i] <= 9)
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (false);
		
		i++;
	}
	return (true);
}

char	**filter_whitespace_lines(char **lines)
{
	char	**filtered_lines;
	int		filtered_count;
    int		filtered_index;
	int		i;

	filtered_index = 0;
	filtered_count = 0;
	i = 0;
    // Count non-empty lines
	while (lines[i])
	{
		if (!is_whitespace(lines[i]))
			filtered_count++;
		i++;
	}
	if (filtered_count == 0)
	{
		printf("nothing\n");	
		return (NULL);  // No non-empty lines
	}
    filtered_lines = (char **)malloc((filtered_count + 1) * sizeof(char *));
    if (filtered_lines == NULL)
	{
        perror("Memory allocation failed");
        exit(1);
    }
	i = 0;
    while (lines[i])
	{
        if (!is_whitespace(lines[i]))
		{
            filtered_lines[filtered_index] = ft_strdup(lines[i]);
            if (filtered_lines[filtered_index] == NULL)
			{
                perror("Memory allocation failed");
                exit(1);
            }
            filtered_index++;
        }
		i++;
    }
	filtered_lines[filtered_index] = NULL;
    return (filtered_lines);
}

void remove_whitespace_beginning(char **lines)
{
    if (lines == NULL)
        return; // Invalid input

    for (int i = 0; lines[i] != NULL; i++)
	{
        char *line = lines[i];
        int length = ft_strlen(line);
        int start = 0;

        // Find the index of the first non-whitespace character
        while (isspace(line[start]))
            start++;

        // Shift the string to the left to remove leading whitespace
        memmove(line, line + start, length - start + 1);
    }
}
